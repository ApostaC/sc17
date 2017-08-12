// Hacky function to simulate Math.fround function if not supported.
Math.fround = Math.fround || function(x) {
    return Math.round(x * 1000000000) / 1000000000;
};

// Performance Reports specific functions
var perfReports = {};
var window;
(function initPerfReports() {
    // Format our byte value numbers to show at most 2 decimal places, but only if required to attain 3 digits of precision
    // 1234.56 -> "1234"
    // 12.3456 -> "12.3"
    // 1.23456 -> "1.23"
    // 0.00000 -> "0.00"
    perfReports.formatNumber = function formatNumber(num) {
        if(num !== null && num !== '' && isFinite(num)) {
            if (num >= 100) return Number(num).toFixed(0); // 1234.56 -> 1234
            if (num >= 10)  return Number(num).toFixed(1); // 12.3456 -> 12.3
            else            return Number(num).toFixed(2); // 1.23456 -> 1.23 and 0 -> 0.00
        }
        else {
            return 'not supported ';
        }
    };

    // SI scaling factors PR understands
    perfReports.siFactors = [
        {factor: Math.pow(10, 9), prefix: 'G'},
        {factor: Math.pow(10, 6), prefix: 'M'},
        {factor: Math.pow(10, 3), prefix: 'k'},
        {factor: Math.pow(10, 0), prefix: ''},
    ];

    // IEC scaling factors PR understands
    perfReports.iecFactors = [
        {factor: Math.pow(2, 30), prefix: 'Gi'},
        {factor: Math.pow(2, 20), prefix: 'Mi'},
        {factor: Math.pow(2, 10), prefix: 'ki'},
        {factor: Math.pow(2,  0), prefix: ''},
    ];

    // Select the appropriate factor for a given value
    perfReports.chooseFactor = function chooseFactor(value, factors) {
        for(var i=0; i<factors.length; ++i) {
            if(value >= factors[i].factor) {
                return factors[i];
            }
        }

        return factors[factors.length-1];
    };

    // Return a value scaled according to the factors
    perfReports.factorValue = function factorValue(value, factors) {
        if(value != null) {
            var factor = perfReports.chooseFactor(value, factors);
            return value/factor.factor;
        }
        else {
            return value;
        }
    };

    // Return the units for a particular scale
    perfReports.factorUnits = function factorUnits(value, factors, options) {
        // Only bytes and bytes/s vary the unit/symbol used at the moment
        var knownUnits = {
            'B': 'bytes',
            'B/s': 'bytes/s'
        };
        var knownSymbols = {
            'bytes': 'B',
            'bytes/s': 'B/s'
        };
        var factor = perfReports.chooseFactor(value, factors);
        // prefer an explicit symbol, then a known mapping from units to symbol, then the units themselves
        var symbol = options.symbol || knownSymbols[options.units] || options.units || '';
        // prefer explicit units, then a known mapping from symbol to units, then the symbol itself
        var units = options.units || knownUnits[options.symbol] || options.symbol || '';
        return factor.prefix ? factor.prefix + symbol : units;
    };

    // Performance reports utility functions
    perfReports.templateHelpers = {
        // Use like {{number myNumberValue}} to apply formatNumber to myNumberValue
        number: perfReports.formatNumber,

        // Use like {{percent myNumberValue}} to format myNumberValue as a
        // percentage (without % sign)
        percent: function percent(value, options) {
            if(value !== null && value !== '' && isFinite(+value)) {
                if(+value > 0 && +value < 0.1) {
                    return '<0.1';
                }
                else {
                    return (+value).toFixed(1);
                }
            }
            else {
                return 'not supported ';
            }
        },

        // Use like {{barWidth myNumberValue}} to force myNumberValue to a
        // valid % bar width
        barWidth: function barWidth(value, options) {
            if(value !== null && value !== '' && isFinite(+value)) {
                return Math.min(100, +value);
            }
            else {
                return '0';
            }
        },


        // Use like {{#if (isVisible ctx)}}any template text{{/if}} to show or
        // hide content based on the value of "ctx.visible" and "ctx.hidden"
        // (visible takes priority over hidden). If ctx.visible or ctx.hidden
        // are strings they are resolved as dotted paths into the root scope.
        isVisible: function isVisible(ctx, options) {
            if(ctx.visible !== undefined) {
                if(allinea.isString(ctx.visible)) {
                    return allinea.toBool(allinea.lookup(options.data.root, ctx.visible));
                }
                else {
                    return allinea.toBool(ctx.visible);
                }
            }
            else {
                if(allinea.isString(ctx.hidden)) {
                    return !allinea.toBool(allinea.lookup(options.data.root, ctx.hidden));
                }
                else {
                    return !allinea.toBool(ctx.hidden);
                }
            }
        },

        // Use like {{#each (normaliseMetrics metrics)}}...{{/each}}
        // to normalise a set of metrics and loop over the results
        normaliseMetrics: function(metrics, options) {
            var newMetrics = [];
            var maxValues = {};

            allinea.forEach(metrics, function(metric) {
                function valueOrNull(val) {
                    if(typeof(val) === 'number') {
                        return isFinite(val) ? val : null;
                    }
                    else {
                        return null;
                    }
                }

                var newMetric = Handlebars.Utils.extend(metric,{});
                newMetric.def = options.data.root.metricData[metric.metricId];

                if(metric.metricId && !newMetric.def) {
                    console.warn('unknown metric: '+metric.metricId);
                }

                var metricValue = allinea.lookup(options.data.root.data, newMetric.def && newMetric.def.value);

                if(!allinea.isObject(metricValue)) {
                    metricValue = {mean: metricValue};
                }

                newMetric.value = {
                    mean:  valueOrNull(metricValue.mean),
                    min:   valueOrNull(metricValue.min),
                    max:   valueOrNull(metricValue.max),
                    stdev: valueOrNull(metricValue.stdev),
                };

                if(metric.group !== undefined) {
                    maxValues[metric.group] = Math.max(
                        maxValues[metric.group] || 0,
                        metric.value.min  || 0,
                        metric.value.mean || 0,
                        metric.value.max  || 0,
                        metric.maxBarValue || 0
                    );
                }

                newMetrics.push(newMetric);
            });

            allinea.forEach(newMetrics, function(metric) {
                metric.normalisedValue = metric.value;

                if(metric.group !== undefined) {
                    if(maxValues[metric.group] > 0) {
                        metric.normalisedValue = {
                            min:   100.0*metric.value.min/maxValues[metric.group],
                            mean:  100.0*metric.value.mean/maxValues[metric.group],
                            max:   100.0*metric.value.max/maxValues[metric.group],
                            stdev: 100.0*metric.value.stdev/maxValues[metric.group]
                        };
                    }
                }
                else if(metric.maxBarValue !== undefined) {
                    metric.normalisedValue = {
                        min:   100.0*metric.value.min/metric.maxBarValue,
                        mean:  100.0*metric.value.mean/metric.maxBarValue,
                        max:   100.0*metric.value.max/metric.maxBarValue,
                        stdev: 100.0*metric.value.stdev/metric.maxBarValue,
                    };
                }
            });

            return newMetrics;
        },

        // Use like {{lookupMetric metricId}} to get the value of a metric
        lookupMetric: function lookupMetric(metricId, options) {
            if(arguments.length !== 2) {
                // one argument when used by a template that is!
                throw new Error('lookupMetric requires one argument');
            }

            var metricDef = options.data.root.metricData[metricId];
            if(!metricDef || !metricDef.value) {
                return undefined;
            }

            var metricValue = allinea.lookup(options.data.root.data, metricDef.value);

            // Handle formatted metrics
            if (metricValue && typeof metricValue === 'object' && metricValue.plain !== undefined) {
                metricValue = metricValue.plain;
            }

            // Handle double precision metrics
            if (metricValue && typeof metricValue === 'object' && metricValue.value !== undefined) {
                metricValue = metricValue.value;
            }

            return metricValue;
        },

        // Use like {{lookupMetricDisplayName metricId}} to get the display name of a metric
        lookupMetricDisplayName: function lookupMetricDisplayName(metricId, options) {
            if(arguments.length !== 2) {
                // one argument when used by a template that is!
                throw new Error('lookupMetricDisplayName requires one argument');
            }

            var metricDef = options.data.root.metricData[metricId];
            if(!metricDef || !metricDef.displayName) {
                return '';
            }

            return metricDef.displayName;
        },

        // Use like {{lookupMetricUnits metricId}} to get the units of a metric
        lookupMetricUnits: function lookupMetricUnits(metricId, options) {
            if(arguments.length !== 2) {
                // one argument when used by a template that is!
                throw new Error('lookupMetricUnits requires one argument');
            }

            var metricDef = options.data.root.metricData[metricId];
            if(!metricDef || !metricDef.units) {
                return '';
            }

            return metricDef.units;
        },

        // Use like {{siValue value}} to get an S.I. scaled version of value
        siValue: function siValue(value, options) {
            return perfReports.factorValue(value, perfReports.siFactors);
        },

        // Use like {{siUnits value symbol="symbol" units="units"}} to get the
        // units for a value
        siUnits: function siUnits(value, options) {
            return perfReports.factorUnits(value, perfReports.siFactors, options.hash);
        },

        // Use like {{iecValue value}} to get a scaled version of value
        iecValue: function iecValue(value, options) {
            return perfReports.factorValue(value, perfReports.iecFactors);
        },

        // Use like {{iecUnits value symbol="symbol" units="units"}} to get the
        // units for a value. Symbol is used when a prefix is required,
        // otherwise units is used.
        iecUnits: function iecUnits(value, options) {
            return perfReports.factorUnits(value, perfReports.iecFactors, options.hash);
        },

        // Use like {{customUnits value units}} to get the custom unit to
        // display. The units should be in plural form. This function will try
        // to remove trailing 'es' (where applicable) or 's'.
        // e.g. {{customUnits 1 buses/hour}} will return 'bus/hour'.
        customUnits: function customUnits(value, units) {
            if (value !== 1)
                return units;

            return units.split('/').map(function stripPlural(unit) {
                if (unit.length === 1)
                    return unit;

                if (unit.substring(unit.length - 3) === 'ses')
                    return unit.substring(0, unit.length - 2);

                if (unit.substring(unit.length - 1) === 's')
                    return unit.substring(0, unit.length - 1);

                return unit;
            }).join('/');
        },

        // Use like {{percentToBar value}} to get a text bar representation
        // of the percentage value. e.g. {{percentToBar 51}} will return
        // '|=====|'. The maximum bar length is 21.
        percentToBar: function percentToBar(value) {
            value = Math.max(+value || 0, 0);

            var ret = '|';
            var numberOfEquals = Math.min(
                Math.round(value/10),
                20
            );

            ret += Array(numberOfEquals).join('=');

            if (value > 0) {
                ret += '|';
            }

            return ret;
        },

        // Use like {{padLeft value maxLength}} to get a right aligned
        // string filled with spaces before it. e.g. {{padLeft 'foo' 5}}
        // will return '  foo'. If the value is longer than the maxLength, the
        // result will be truncated from the end.
        padLeft: function padLeft() {
            if(arguments.length < 2 || arguments.length > 3) {
                throw new Error('invalid usage of padLeft');
            }

            var options = arguments[arguments.length-1];
            var maxLength = arguments[arguments.length-2];
            var value = undefined;

            if(options.fn) {
                // block form
                if(arguments.length !== 2) {
                    throw new Error('invalid usage of padLeft, an argument is required when used as a block');
                }

                value = options.fn(this);
            }
            else {
                // function form
                if(arguments.length !== 3) {
                    throw new Error('invalid usage of padLeft, two arguments are required when used as a function');
                }

                value = arguments[0];
            }

            value = String(value);
            maxLength = Math.max(+maxLength || 0, 0);

            var str = Array(maxLength + 1).join(' ') + value;

            return str.substring(str.length - maxLength);
        },

        // Use like {{padRight value maxLength}} to get a left aligned
        // string filled with spaces after it. e.g. {{padRight 'foo' 5}}
        // will return 'foo  '. If the value is longer than the maxLength, the
        // result will be truncated from the end.
        padRight: function padRight() {
            if(arguments.length < 2 || arguments.length > 3) {
                throw new Error('invalid usage of padRight');
            }

            var options = arguments[arguments.length-1];
            var maxLength = arguments[arguments.length-2];
            var value = undefined;

            if(options.fn) {
                // block form
                if(arguments.length !== 2) {
                    throw new Error('invalid usage of padRight, an argument is required when used as a block');
                }

                value = options.fn(this);
            }
            else {
                // function form
                if(arguments.length !== 3) {
                    throw new Error('invalid usage of padRight, two arguments are required when used as a function');
                }

                value = arguments[0];
            }

            value = String(value);
            maxLength = Math.max(+maxLength || 0, 0);

            var str = value + Array(maxLength + 1).join(' ');

            return str.substring(0, maxLength);
        },

        // Use like {{#csvEscape}}foo{{bar}}fooz{{/csvEscape}}, or {{csvEscape string}}
        // to get an escaped string that can be embedded in a CSV file.
        // e.g. 'foo " bar' will return '"foo "" bar"'
        csvEscape: function csvEscape() {
            if(arguments.length < 1 || arguments.length > 2) {
                throw new Error('invalid usage of csvEscape');
            }

            var options = arguments[arguments.length-1];
            var value = undefined;

            if(options.fn) {
                // block form
                if(arguments.length !== 1) {
                    throw new Error('invalid usage of csvEscape, no arguments should be passed when used as a block');
                }

                value = options.fn(this);
            }
            else {
                // function form
                if(arguments.length !== 2) {
                    throw new Error('invalid usage of csvEscape, an argument is required when used as a function');
                }

                value = arguments[0];
            }

            value = String(value).replace(/"/g, '""');

            if (value.indexOf(',') !== -1 || value.indexOf(' ') !== -1 || value.indexOf('\n') !== -1 || value.indexOf('"') !== -1) {
                value = '"' + value + '"';
            }

            return value;
        },
    };

    // Merge two color codes together.
    // Color codes shall be arrays containing three values (representing the
    // three HSL components of a color). If a value is missing, it will be
    // defaulted to zero.
    perfReports.mergeColor = function mergeColor(c1, c2) {
        var c = [0, 0, 0];

        if (c1) {
            c[0] = (+c1[0] || 0);
            c[1] = (+c1[1] || 0);
            c[2] = (+c1[2] || 0);
        }

        if (c2) {
            c[0] += (+c2[0] || 0);
            c[1] += (+c2[1] || 0);
            c[2] += (+c2[2] || 0);
        }

        if (c[0] < 0)   c[0] = 0;
        if (c[0] > 360) c[0] = 360;

        if (c[1] < 0)   c[1] = 0;
        if (c[1] > 100) c[1] = 100;

        if (c[2] < 0)   c[2] = 0;
        if (c[2] > 100) c[2] = 100;

        return c;
    };

    // Compute the color code of a given colorName (i.e. 'cpu.mem').
    // If the color code cannot be found, "rgb(0, 0, 0)" will be returned.
    perfReports.computeColor = function computeColor(colorData, colorName) {
        if (!colorData) {
            return "rgb(0, 0, 0)";
        }

        var color = [0, 0, 0];

        // Either 'colorName' is stored explicitly as a hsl array, or the final hsl
        // colour array should be derived by taking a 'default' value and modifying it
        // according to the deltas held in the 'non-default' values. For example:
        //
        // colorData = {
        //     "cpu.multi_core": [77, 88, 99],
        //     "cpu": {
        //          "default":     [100, 50, 50],
        //          "single_core": [  5,-10, 15]
        //     }
        // }
        //
        // If 'colorName' === "cpu.multi_core" return [77, 88, 99]
        // If 'colorName' === "cpu.single_core" return [105, 40, 65]
        // (the sum of [100, 50, 50] and [5,-10, 15])

        if (colorData[colorName]===undefined || !Array.isArray(colorData[colorName]))
        {
            // 'colorName' is either not defined, or is defined but is not a hsl array.
            var colorNames = colorName.split('.');
            for (var i in colorNames) {
                colorData = colorData[colorNames[i]];
                if (colorData === undefined) {
                    return "rgb(0, 0, 0)";
                } else if (Array.isArray(colorData)) {
                    color = perfReports.mergeColor(color, colorData);
                } else {
                    color = perfReports.mergeColor(color, colorData["default"]);
                }
            }
        }
        else
        {
            // Colour is held as an absolute value in the form of a hsl array
            color = colorData[colorName];
        }

        // Return computed color
        return perfReports.hslToRgb(
            color[0] / 360,
            color[1] / 100,
            color[2] / 100);
    };

    // From http://axonflux.com/handy-rgb-to-hsl-and-rgb-to-hsv-color-model-c
    /**
     * Converts an HSL color value to RGB. Conversion formula
     * adapted from http://en.wikipedia.org/wiki/HSL_color_space.
     * Assumes h, s, and l are contained in the set [0, 1] and
     * returns r, g, and b in the set [0, 255].
     *
     * @param   Number  h       The hue
     * @param   Number  s       The saturation
     * @param   Number  l       The lightness
     * @return  String          The RGB representation
     */
    perfReports.hslToRgb = function hslToRgb(h, s, l){
        var r, g, b;

        function hue2rgb(p, q, t){
            if(t < 0) t += 1;
            if(t > 1) t -= 1;
            if(t < 1/6) return p + (q - p) * 6 * t;
            if(t < 1/2) return q;
            if(t < 2/3) return p + (q - p) * (2/3 - t) * 6;
            return p;
        }

        var q = l < 0.5 ? l * (1 + s) : l + s - l * s;
        var p = 2 * l - q;
        r = hue2rgb(p, q, h + 1/3);
        g = hue2rgb(p, q, h);
        b = hue2rgb(p, q, h - 1/3);

        return "rgb(" +
            Math.round(Math.fround(r) * 255) + ", " +
            Math.round(Math.fround(g) * 255) + ", " +
            Math.round(Math.fround(b) * 255) + ")";
    };

    // Set the title of the document
    perfReports.setDocumentTitleFromTemplate = function setDocumentTitleFromTemplate(context) {
        if(ReportEngine.hasPartial('titleTemplate')) {
            document.title = ReportEngine.render(
                'titleTemplate',
                'html',
                context
            );
        }
    };

    // Create CSS rules for perf-report colors
    perfReports.makeCssColorRules = function makeCssColorRules(colorData, colorName, colorValue) {

        if (Array.isArray(colorData)) {
            allinea.sheet.insertRule(
                "[class='" + colorName + "'] " +
                "{ color : " +
                perfReports.hslToRgb(
                    colorValue[0] / 360,
                    colorValue[1] / 100,
                    colorValue[2] / 100
                ) +
                "; }",
                0
            );
            allinea.sheet.insertRule(
                "[class='bar'] [class='" + colorName + "'] " +
                "{ background-color : " +
                perfReports.hslToRgb(
                    colorValue[0] / 360,
                    colorValue[1] / 100,
                    colorValue[2] / 100
                ) +
                "; }",
                0
            );
        } else {
            colorValue = perfReports.mergeColor(colorValue, colorData["default"]);
            for (var key in colorData) {
                var newColorName;
                var newColorValue;
                if (key !== "default") {
                    newColorName = colorName ? colorName + "." + key : key;
                    newColorValue = perfReports.mergeColor(colorValue, colorData[key]);
                } else {
                    newColorName = colorName;
                    newColorValue = colorValue;
                }

                makeCssColorRules(colorData[key], newColorName, newColorValue);
            }
        }
    };

    if(window && window.d3) {
        // get radar chart data
        perfReports.makeRadarData = function makeRadarData(jsonData) {
            var result = {
                data: [],
                axisColors: [],
                maxAxis: null,
                options: {
                    w: 200,
                    h: 200,
                    factor: 0.7,
                    fontSize: 16,
                    radius: 0,
                    opacityArea: 0.64,
                    maxValue: 100,
                    color: function() { return '#bb58d6'; }
                }
            };

            var maxValue;

            if(!jsonData || !jsonData.summaryData || !jsonData.summaryData.rows) {
                return null;
            }

            for(var i=0; i<jsonData.summaryData.rows.length; ++i) {
                var row = jsonData.summaryData.rows[i];

                if(!perfReports.templateHelpers.isVisible(row,{data:{root:jsonData}})) {
                    continue;
                }

                // prefer the chartLabel, but fallback to the heading if not
                // specified
                var axis = row.chartLabel || row.heading;
                var value = perfReports.templateHelpers.lookupMetric(
                    row.metricId,
                    {data:{root:jsonData}}
                );

                if(result.maxAxis === null || value > maxValue) {
                    maxValue = value;
                    result.maxAxis = result.data.length;
                }

                result.data.push({
                    axis: axis,
                    value: value
                });
                result.axisColors.push(
                    perfReports.computeColor(jsonData.colorData, row.colorName)
                );
            }

            if(jsonData.summaryData.primaryBound) {
                var bound = allinea.lookup(jsonData.data, jsonData.summaryData.primaryBound);
                if(bound) {
                    result.options.color = function() {
                        return perfReports.computeColor(jsonData.colorData, bound);
                    }
                }
            }
            else if(result.maxAxis !== null) {
                result.options.color = function() {
                    return result.axisColors[result.maxAxis];
                }
            }

            return result.data.length >= 3 ? result : null;
        };
    }

    if(document && document.getElementById) {
        perfReports.toggleMetric = function toggleMetric(event, id) {
            event.preventDefault();

            var e = document.getElementById(id);

            var classes = e.className.match(/\S+/g) || [],
            index = classes.indexOf('show');

            if(index >= 0) {
                classes.splice(index, 1)
            }
            else {
                classes.push('show');
            }

            e.className = classes.join(' ');
        }
    }
})();

ReportEngine.registerHelpers({all: perfReports.templateHelpers});

if(ReportEngine.afterRender) {
    ReportEngine.afterRender(perfReports.setDocumentTitleFromTemplate);

    ReportEngine.afterRender(function createColorCss(jsonData) {
        if (jsonData && jsonData.colorData) {
            perfReports.makeCssColorRules(jsonData.colorData);
        }
    });

    if(perfReports.makeRadarData) {
        ReportEngine.afterRender(function renderRadarChar(jsonData) {
            var radarData = perfReports.makeRadarData(jsonData);

            for(var i=0; i<radarData.axisColors.length; ++i) {
                allinea.sheet.insertRule(
                    "#time_radar .legend_axis" + i + "{ fill: " + radarData.axisColors[i] + "}",
                    0
                );
            }

            RadarChart.draw("#time_radar", [ radarData.data ], radarData.options);
        });
    }
}

