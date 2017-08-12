var ReportEngine;
var document;

(function initReportEngine() {
    // Map of helpers the report engine automatically provides
    var builtinHelpers = {
        all: {
            // Use like {{#condenseSpace}}any template text{{/condenseSpace}} to
            // trim the string and replace all blocks of whitespace with a single
            // space.
            condenseSpace: function condenseSpace(options) {
                if(arguments.length !== 1 || !options.fn) {
                    throw new Error('invalid usage of condenseSpace');
                }

                var output = options.fn(this);
                return output.trim().replace(/\s+/g, ' ');
            },

            // Use like {{#trim}}any template text{{/trim}} to trim a string, or
            // like {{trim variable}} to trim the value of the specified variable
            trim: function trim() {
                if(arguments.length < 1 || arguments.length > 2) {
                    throw new Error('invalid usage of trim');
                }

                var options = arguments[arguments.length-1];

                if(options.fn) {
                    // block form
                    if(arguments.length !== 1) {
                        throw new Error('invalid usage of trim, no arguments should be passed when used as a block');
                    }

                    return options.fn(this).trim();
                }
                else {
                    // function form
                    if(arguments.length !== 2) {
                        throw new Error('invalid usage of trim, an argument is required when used as a function');
                    }

                    var string = ''+arguments[0];
                    return string.trim();
                }
            },

            // Use like {{#trimLeft}}any template text{{/trimLeft}} to left-trim a string, or
            // like {{trimLeft variable}} to left-trim the value of the specified variable
            trimLeft: function trimLeft() {
                if(arguments.length < 1 || arguments.length > 2) {
                    throw new Error('invalid usage of trimLeft');
                }

                var options = arguments[arguments.length-1];

                if(options.fn) {
                    // block form
                    if(arguments.length !== 1) {
                        throw new Error('invalid usage of trimLeft, no arguments should be passed when used as a block');
                    }

                    return options.fn(this).replace(/^\s+/, "");
                }
                else {
                    // function form
                    if(arguments.length !== 2) {
                        throw new Error('invalid usage of trimLeft, an argument is required when used as a function');
                    }

                    var string = ''+arguments[0];
                    return string.replace(/^\s+/, "");
                }
            },

            // Use like {{toFixed value precision}} to format a number using
            // fixed-point notation.
            toFixed: function toFixed(value, precision) {
                if(arguments.length !== 3) {
                    throw new Error('invalid usage of toFixed');
                }

                return (+value || 0).toFixed(+precision || 0);
            },

            // Use like {{toPrecision value precision}} to format a number to
            // specified precision. Precision must be between 1 and 21.
            // Any other precision will be changed to the closest one.
            toPrecision: function toPrecision(value, precision) {
                if(arguments.length !== 3) {
                    throw new Error('invalid usage of toPrecision');
                }

                if (isFinite(precision)) {
                    if (precision > 21)
                        precision = 21;
                    if (precision < 1)
                        precision = 1;
                } else {
                    precision = undefined;
                }

                return (+value || 0).toPrecision(precision);
            },

            // Use like {{#makeId}}{{name}}{{/makeId}} to generate an ID based on
            // name.
            makeId: function makeId(options) {
                return allinea.makeId(options.fn(this));
            },

            // Use like {{#if (toBool value)}}...{{/if}} to convert value to a boolean with
            // parsing of strings containing falsy values.
            toBool: allinea.toBool,

            // Use like {{#if (greater a b)}}...{{/if}} to test a>b
            greater: function greater(a, b, options) {
                if(arguments.length !== 3) {
                    throw new Error('invalid usage of greater');
                }

                return a > b;
            },

            // Use like {{#if (less a b)}}...{{/if}} to test a<b
            less: function less(a, b, options) {
                if(arguments.length !== 3) {
                    throw new Error('invalid usage of less');
                }

                return a < b;
            },

            // Use like {{isEqual x y}} to test if a === b
            // As you might expect, a boolean is returned
            isEqual: function isEqual(lhs, rhs, options) {
                return lhs === rhs;
            },

            // Use like {{add x y}} to calculate x+y
            // x and y will be cast to numbers, and treated as 0 if undefined
            add: function add(x, y, options) {
                if(arguments.length !== 3) {
                    throw new Error('invalid usage of add');
                }

                return (+x||0)+(+y||0);
            },

            // Use like {{sub x y}} to calculate x-y
            // x and y will be cast to numbers, and treated as 0 if undefined
            sub: function sub(x, y, options) {
                if(arguments.length !== 3) {
                    throw new Error('invalid usage of sub');
                }

                return (+x||0)-(+y||0);
            },

            // Use like {{div x y}} to calculate x/y
            // x and y will be cast to numbers, and treated as 0 if undefined
            div: function div(x, y, options) {
                if(arguments.length !== 3) {
                    throw new Error('invalid usage of div');
                }

                return (+x||0)/(+y||0);
            },

            // Use like {{if (notNull x)}} to test if any arguments are null or undefined
            anyNotNull: function anyNotNull() {
                // NB: the last argument to a helper is always the Handlebars
                // options structure
                var options = arguments[arguments.length-1];

                for(var i=0; i<arguments.length-1; ++i) {
                    // note: intentional weak equality to cover null and undefined
                    if(arguments[i] != null) {
                        return true;
                    }
                }

                return false;
            },

            // Use like {{if (allNull x)}} to test if all arguments are null or undefined
            allNull: function allNull() {
                return !builtinHelpers.all.anyNotNull.apply(this, arguments);
            },

            // Use like {{increment 'myCounter'}} to add one to "myCounter" in the
            // current scope. If the counter does not exist it is initialised to 0.
            // Optionally, the scope can be passed with
            // {{increment 'myCounter' scope=..}}
            increment: function increment(key, options) {
                if(arguments.length !== 2) {
                    throw new Error('invalid usage of increment');
                }

                var scope = this;
                if(options.hash && options.hash.scope) {
                    scope = options.hash.scope;
                }

                if(!allinea.isObject(scope)) {
                    throw new Error('scope for increment must be an object');
                }

                if(typeof scope[key] === 'number') {
                    ++scope[key];
                }
                else {
                    scope[key] = 0;
                }
            },

            // Use like {{#if (isOdd value)}}...{{/if}} to conditionally include
            // content if a value is odd
            isOdd: function isOdd(value, options) {
                if(arguments.length !== 2) {
                    throw new Error('invalid usage of increment');
                }

                return (Math.abs(value)%2) === 1;
            },

            // Use like {{lookup object path}} to read a dotted path from an object
            lookup: function lookup(object, path, options) {
                if(arguments.length !== 3) {
                    throw new Error('invalid usage of lookup');
                }

                if(path && !allinea.isString(path)) {
                    throw new Error('path for lookup must be a string or falsy value');
                }

                return allinea.lookup(object, path);
            },

            // Use like {{find array key-path value [path]}} to find an object in an
            // array with the specified value, optionally returning the specified path
            find: function find(array, keyPath, value, resultPath, options) {
                if(arguments.length < 4 || arguments.length > 5) {
                    throw new Error('invalid usage of find');
                }

                if(arguments.length === 4) {
                    options = resultPath;
                    resultPath = '';
                }

                if(!allinea.isArray(array)) {
                    throw new Error('array parameter to find must be an array');
                }

                if(keyPath && !allinea.isString(keyPath)) {
                    throw new Error('keyPath parameter to find must be a string or falsy');
                }

                if(resultPath && !allinea.isString(resultPath)) {
                    throw new Error('resultPath parameter to find must be a string or falsy');
                }

                for(var i=0; i<array.length; ++i) {
                    if(allinea.lookup(array[i], keyPath) === value) {
                        return allinea.lookup(array[i], resultPath);
                    }
                }

                return undefined;
            },

            // Use like {{textToHtml string}} to convert a string to HTML
            textToHtml: function textToHtml(string, options) {
                return new Handlebars.SafeString(ReportEngine.textToHtml(string));
            },

            // Use like {{htmlToText string}} to convert HTML to text
            // Note: use {{{triple-stashes}}} if you don't want Handlebars to
            // escape the result!
            htmlToText: function htmlToText(string, options) {
                return ReportEngine.htmlToText(string, options.hash);
            },

            // Use like {{#if isHtml}}...{{/if}} to test whether the template
            // engine is running in HTML mode
            isHtml: function isHtml() {
                return false;
            },

            // Use like {{wrappablePath string}} to add zero width spaces after
            // forward slashes (HTML only)
            wrappablePath: function wrappablePath(string, options) {
                if(arguments.length != 2) {
                    throw new Error('invalid usage of wrappablePath');
                }

                return string;
            },

            // Use like {{formatToMimeType "all"}} to get a suitable mime type
            // for a partial type
            formatToMimeType: function formatToMimeType(format, options) {
                if(arguments.length != 2) {
                    throw new Error('invalid usage of formatToMimeType');
                }

                switch(format) {
                case 'text':
                    return 'text/plain';
                case 'html':
                    return 'text/html';
                case 'all':
                    return 'text/x.allinea-template';
                }

                return '';
            },
        },

        html: {
            isHtml: function isHtml() {
                return true;
            },

            wrappablePath: function wrappablePath(string, options) {
                if(arguments.length != 2) {
                    throw new Error('invalid usage of wrappablePath');
                }

                string = Handlebars.escapeExpression(string);
                return new Handlebars.SafeString(string.replace(/\//g, '/&#x200b;'));
            }
        }
    };

    // Constructor for a ReportEngine, this lets us create multiple ReportEngine
    // instances e.g. for unit tests to create clean environments.
    function ReportEngineObject() {
        var self = this;

        // Map of format to Handlebars template rendering engines
        self.engines = {
            html: Handlebars.create(),
            text: Handlebars.create()
        };

        // Map from format to partial name to partial rendering function
        self.partials = {
            html: {},
            text: {}
        };

        // Initialisation functions
        self.initFunctions = [];
        self.afterRenderFunctions = [];

        self.registerHelpers(builtinHelpers);

        // The "eval" helper is special, it needs to know about the engine
        // for the format it is being invoked under

        // Use like {{eval templateText context}} to dynamically evaluate a template
        // Use like {{#with (eval templateText context)}}...{{/with}} to dynamically
        // evaluate templateText, then render it into the body as "this"
        // Use like {{#each (eval templateArray context)}}...{{/each}} to dynamically
        // evaluate every member of the array, then render it into the body as
        // "this".
        // NB: avoid where possible, compiling templates is expensive
        allinea.forEach(self.engines, function registerEvalHelper(engine, format) {
            engine.registerHelper('eval', function evalHelper(templateText, context, options) {
                if(arguments.length < 2 || arguments.length > 3) {
                    throw new Error('invalid usage of eval');
                }

                if(arguments.length === 2) {
                    // if the context is not specified, default it to this
                    options = context;
                    context = this;
                }

                for (var key in options.hash) {
                    context[key] = options.hash[key];
                }

                var innerOptions = {data:{root:options.data.root}};

                if(allinea.isArray(templateText)) {
                    var result = [];
                    allinea.forEach(templateText, function evalArrayElement(template) {
                        if(template && !allinea.isString(template)) {
                            throw new Error('template text for eval must be a string or falsy');
                        }

                        var val = template
                            ? new engine.SafeString(engine.compile(template)(context,innerOptions))
                            : '';
                        result.push(val);
                    });
                    return result;
                }
                else if(templateText) {
                    if(!allinea.isString(templateText)) {
                        throw new Error('template text for eval must be a string or falsy');
                    }

                    return new engine.SafeString(engine.compile(templateText)(context,innerOptions));
                }
                else {
                    return '';
                }
            });
        });

        if(document && document.addEventListener) {
            document.addEventListener('DOMContentLoaded', function invokeInitFunctions() {
                self.invokeInitFunctions();
            }, false);
        }

        // Ensure there is an error template
        self.registerPartial('errorTemplate', 'text', '{{{message}}}\n\n{{#if stack}}<pre>{{{stack}}}</pre>{{/if}}');

        if(self.loadHtmlTemplates) {
            self.onInit(self.loadHtmlTemplates);
        }
    }

    // Initialise functions that only require ECMAScript, and no browser API

    // Function to create a new ReportEngine instance, e.g. call ReportEngine.create()
    // to create an isolated instance for unit tests.
    ReportEngineObject.prototype.create = function createReportEngine() {
        return new ReportEngineObject();
    };

    // Helper function to convert text to HTML (with proper escaping and respect
    // for newlines)
    ReportEngineObject.prototype.textToHtml = function escapeString(string) {
        if(!allinea.isString(string)) {
            throw new Error('textToHtml expected string argument');
        }

        return '<span style="white-space:pre-line">'+Handlebars.escapeExpression(string)+'</span>';
    };

    // given a string, apply word wrapping (at spaces) at the specified column
    function wrapText(string, wrapColumn) {
        var wrappableChars = [
            // conventional spaces
            ' ',
            '\t',
            // fixed width spaces
            '\u2000','\u2001','\u2002','\u2003','\u2004','\u2005','\u2006',
            '\u2007','\u2008','\u2009','\u200a',
            // zero width space
            '\u200b',
            // medium mathematical space
            '\u205f',
            // ideographic space
            '\u3000',
        ];
        var len = string.length;
        var result = string.split(''); // JS string are immutable, convert to array

        var startOfLine = 0;
        var lastSpaceOnLine = undefined;

        for (var i=0; i<len; ++i) {
            var c = string[i];

            if (c === '\n') {
                startOfLine = i+1;
                lastSpaceOnLine = undefined;
            }
            else if (wrappableChars.indexOf(c) !== -1) {
                lastSpaceOnLine = i;
            }

            var lineLength = i-startOfLine+1;
            if (lineLength > wrapColumn && lastSpaceOnLine !== undefined) {
                result[lastSpaceOnLine] = '\n';
                startOfLine = lastSpaceOnLine+1;
                lastSpaceOnLine = undefined;
            }
        }

        return result.join('');
    }

    // given a string, replace all blocks of whitespace with a single space
    // note: does not adjust non-breaking or fixed width spaces.
    function collapseWhitespace(string) {
        return string.replace(/[ \r\n\t]+/g, ' ');
    }

    // table mapping HTML entity name to a unicode character
    var htmlEntities = {
        apos:'\u0027',quot:'\u0022',amp:'\u0026',lt:'\u003C',gt:'\u003E',nbsp:'\u00A0',iexcl:'\u00A1',cent:'\u00A2',pound:'\u00A3',
        curren:'\u00A4',yen:'\u00A5',brvbar:'\u00A6',sect:'\u00A7',uml:'\u00A8',copy:'\u00A9',ordf:'\u00AA',laquo:'\u00AB',
        not:'\u00AC',shy:'\u00AD',reg:'\u00AE',macr:'\u00AF',deg:'\u00B0',plusmn:'\u00B1',sup2:'\u00B2',sup3:'\u00B3',
        acute:'\u00B4',micro:'\u00B5',para:'\u00B6',middot:'\u00B7',cedil:'\u00B8',sup1:'\u00B9',ordm:'\u00BA',raquo:'\u00BB',
        frac14:'\u00BC',frac12:'\u00BD',frac34:'\u00BE',iquest:'\u00BF',Agrave:'\u00C0',Aacute:'\u00C1',Acirc:'\u00C2',Atilde:'\u00C3',
        Auml:'\u00C4',Aring:'\u00C5',AElig:'\u00C6',Ccedil:'\u00C7',Egrave:'\u00C8',Eacute:'\u00C9',Ecirc:'\u00CA',Euml:'\u00CB',
        Igrave:'\u00CC',Iacute:'\u00CD',Icirc:'\u00CE',Iuml:'\u00CF',ETH:'\u00D0',Ntilde:'\u00D1',Ograve:'\u00D2',Oacute:'\u00D3',
        Ocirc:'\u00D4',Otilde:'\u00D5',Ouml:'\u00D6',times:'\u00D7',Oslash:'\u00D8',Ugrave:'\u00D9',Uacute:'\u00DA',Ucirc:'\u00DB',
        Uuml:'\u00DC',Yacute:'\u00DD',THORN:'\u00DE',szlig:'\u00DF',agrave:'\u00E0',aacute:'\u00E1',acirc:'\u00E2',atilde:'\u00E3',
        auml:'\u00E4',aring:'\u00E5',aelig:'\u00E6',ccedil:'\u00E7',egrave:'\u00E8',eacute:'\u00E9',ecirc:'\u00EA',euml:'\u00EB',
        igrave:'\u00EC',iacute:'\u00ED',icirc:'\u00EE',iuml:'\u00EF',eth:'\u00F0',ntilde:'\u00F1',ograve:'\u00F2',oacute:'\u00F3',
        ocirc:'\u00F4',otilde:'\u00F5',ouml:'\u00F6',divide:'\u00F7',oslash:'\u00F8',ugrave:'\u00F9',uacute:'\u00FA',ucirc:'\u00FB',
        uuml:'\u00FC',yacute:'\u00FD',thorn:'\u00FE',yuml:'\u00FF',OElig:'\u0152',oelig:'\u0153',Scaron:'\u0160',scaron:'\u0161',
        Yuml:'\u0178',fnof:'\u0192',circ:'\u02C6',tilde:'\u02DC',Alpha:'\u0391',Beta:'\u0392',Gamma:'\u0393',Delta:'\u0394',
        Epsilon:'\u0395',Zeta:'\u0396',Eta:'\u0397',Theta:'\u0398',Iota:'\u0399',Kappa:'\u039A',Lambda:'\u039B',Mu:'\u039C',
        Nu:'\u039D',Xi:'\u039E',Omicron:'\u039F',Pi:'\u03A0',Rho:'\u03A1',Sigma:'\u03A3',Tau:'\u03A4',Upsilon:'\u03A5',
        Phi:'\u03A6',Chi:'\u03A7',Psi:'\u03A8',Omega:'\u03A9',alpha:'\u03B1',beta:'\u03B2',gamma:'\u03B3',delta:'\u03B4',
        epsilon:'\u03B5',zeta:'\u03B6',eta:'\u03B7',theta:'\u03B8',iota:'\u03B9',kappa:'\u03BA',lambda:'\u03BB',mu:'\u03BC',
        nu:'\u03BD',xi:'\u03BE',omicron:'\u03BF',pi:'\u03C0',rho:'\u03C1',sigmaf:'\u03C2',sigma:'\u03C3',tau:'\u03C4',
        upsilon:'\u03C5',phi:'\u03C6',chi:'\u03C7',psi:'\u03C8',omega:'\u03C9',thetasym:'\u03D1',upsih:'\u03D2',piv:'\u03D6',
        ensp:'\u2002',emsp:'\u2003',thinsp:'\u2009',zwnj:'\u200C',zwj:'\u200D',lrm:'\u200E',rlm:'\u200F',ndash:'\u2013',
        mdash:'\u2014',lsquo:'\u2018',rsquo:'\u2019',sbquo:'\u201A',ldquo:'\u201C',rdquo:'\u201D',bdquo:'\u201E',dagger:'\u2020',
        Dagger:'\u2021',bull:'\u2022',hellip:'\u2026',permil:'\u2030',prime:'\u2032',Prime:'\u2033',lsaquo:'\u2039',rsaquo:'\u203A',
        oline:'\u203E',frasl:'\u2044',euro:'\u20AC',image:'\u2111',weierp:'\u2118',real:'\u211C',trade:'\u2122',alefsym:'\u2135',
        larr:'\u2190',uarr:'\u2191',rarr:'\u2192',darr:'\u2193',harr:'\u2194',crarr:'\u21B5',lArr:'\u21D0',uArr:'\u21D1',
        rArr:'\u21D2',dArr:'\u21D3',hArr:'\u21D4',forall:'\u2200',part:'\u2202',exist:'\u2203',empty:'\u2205',nabla:'\u2207',
        isin:'\u2208',notin:'\u2209',ni:'\u220B',prod:'\u220F',sum:'\u2211',minus:'\u2212',lowast:'\u2217',radic:'\u221A',
        prop:'\u221D',infin:'\u221E',ang:'\u2220',and:'\u2227',or:'\u2228',cap:'\u2229',cup:'\u222A',int:'\u222B',
        there4:'\u2234',sim:'\u223C',cong:'\u2245',asymp:'\u2248',ne:'\u2260',equiv:'\u2261',le:'\u2264',ge:'\u2265',
        sub:'\u2282',sup:'\u2283',nsub:'\u2284',sube:'\u2286',supe:'\u2287',oplus:'\u2295',otimes:'\u2297',perp:'\u22A5',
        sdot:'\u22C5',lceil:'\u2308',rceil:'\u2309',lfloor:'\u230A',rfloor:'\u230B',lang:'\u2329',rang:'\u232A',loz:'\u25CA',
        spades:'\u2660',clubs:'\u2663',hearts:'\u2665',diams:'\u2666',
    };

    // given a string, decode all HTML entities
    function decode(string) {
        return string.replace(/&([a-zA-Z0-9]+);/g, function replaceHtmlNamedEnt(match, name) {
            return htmlEntities[name];
        }).replace(/&#([0-9]+);/g, function replaceHtmlDecEnt(match, number) {
            return String.fromCharCode(+number);
        }).replace(/&#x([0-9a-fA-F]+);/g, function replaceHtmlHexEnt(match, number) {
            return String.fromCharCode(parseInt(number,16));
        });
    }

    // given parsed html, convert it to plain text, see htmlToText for options
    function parsedHtmlToText(parsed, options) {
        var blockElements = [
            'p',
            'div',
            'h1',
            'h2',
            'h3',
            'h4',
            'h5',
            'h6',
            'ul',
            'ol',
            'pre',
        ];

        var result = '';
        allinea.forEach(parsed, function htmlElementToText(element) {
            switch(element.type) {
            case 'tag':
                if(element.name === 'br') {
                    result += '\n';
                }
                else if(blockElements.indexOf(element.name) !== -1) {
                    if(result.length > 0 && result.slice(-1) !== '\n') {
                        result += '\n';
                    }
                }

                result += parsedHtmlToText(element.children, options);

                if(element.name === 'p') {
                    result += '\n\n';
                }
                else if(blockElements.indexOf(element.name) !== -1) {
                    if(result.length === 0 || result.slice(-1) !== '\n') {
                        result += '\n';
                    }
                }
                break;

            case 'text':
                element.data = decode(element.data);

                if(options.collapseWhitespace) {
                    element.data = collapseWhitespace(element.data);
                }

                if(options.wrap) {
                    element.data = wrapText(element.data, options.wrap);
                }

                result += element.data;
                break;
            }
        });
        return result;
    }

    // Helper function to convert HTML to text (stripping tags)
    // options is an optional object (hash), which may contain some or all of
    // the following keys:
    //    wrap:               column to wrap text at (or false to disable wrapping)
    //    collapseWhitespace: truthy to replace all consecutive whitespace with
    //                        a single space
    ReportEngineObject.prototype.htmlToText = function htmlToText(string, options) {
        if(!allinea.isString(string)) {
            if (typeof string === 'object' && string.toString && typeof string.toString === 'function') {
                string = string.toString();
            } else {
                throw new Error('htmlToText expected string argument');
            }
        }

        if(options !== undefined && !allinea.isObject(options)) {
            throw new Error('htmlToText options must be object');
        }

        var handler = new htmlparser.HtmlBuilder(function handleHtmlResult(error, dom) {
            if(error) {
                throw new Error(error);
            }
        });
        var parser = new htmlparser.Parser(handler);

        parser.parseComplete(string);

        var defaultOptions = {
            wrap: false,
            collapseWhitespace: true
        };

        options = options || {};

        for(key in defaultOptions) {
            if(!(key in options)) {
                options[key] = defaultOptions[key];
            }
        }

        return parsedHtmlToText(handler.dom, options);
    };

    // Internal map used to convert between formats
    var formatMap = {
        html: {
            text: function htmlPartialToText(partial) {
                return ReportEngineObject.prototype.htmlToText(
                    partial.replace(/\{\{([^>#\/{}][^{}]*?)\}\}(?!})/g, function(match, key) {
                        if(key === 'else') {
                            return match;
                        }
                        else {
                            return '{{{'+key+'}}}';
                        }
                    })
                );
            }
        },

        text: {
            html: function textPartialToHtml(partial) {
                return ReportEngineObject.prototype.textToHtml(
                    partial.replace(/\{\{\{(.*?)\}\}\}/g, '{{$1}}')
                );
            }
        }
    };

    // Internal helper to compile a partial and put it in the right place
    function compileAndRegisterPartial(reportEngine, name, format, partial) {
        var engine = reportEngine.engines[format];
        var compiledPartial = engine.compile(partial);
        reportEngine.partials[format][name] = compiledPartial;
        engine.registerPartial(name, compiledPartial);
    }

    /*
        Register a partial template with the report engine.

        Where possible this will generate partials for other formats that have
        not already been specified.

        name:    The name of the partial
        format:  The format of the partial - either "text", "html" or "all"
        partial: The content of the partial.
    */
    ReportEngineObject.prototype.registerPartial = function registerPartial(name, format, partial) {
        if(!allinea.isString(name)) {
            throw new Error('name must be a string');
        }

        if(!allinea.isString(format)) {
            throw new Error('format must be a string');
        }

        if(!allinea.isString(partial)) {
            throw new Error('partial must be a string');
        }

        var self = this;

        if(format === 'all') {
            allinea.forEach(this.partials, function(otherPartials, otherFormat) {
                compileAndRegisterPartial(self, name, otherFormat, partial);
            });
        }
        else {
            if(!this.partials[format]) {
                throw new Error('Invalid format "'+format+'"');
            }

            compileAndRegisterPartial(this, name, format, partial);

            if(formatMap[format]) {
                allinea.forEach(this.partials, function(otherPartials, otherFormat) {
                    if(format !== otherFormat && formatMap[format][otherFormat] && otherPartials[name] === undefined) {
                        compileAndRegisterPartial(
                            self,
                            name,
                            otherFormat,
                            formatMap[format][otherFormat](partial)
                        );
                    }
                });
            }
        }
    };

    /*
        Determine if a partial exists, if format is unspecified will test all
        formats
    */
    ReportEngineObject.prototype.hasPartial = function hasPartial(name, format) {
        if(!allinea.isString(name)) {
            throw new Error('name must be a string');
        }

        if(format !== undefined && !allinea.isString(format)) {
            throw new Error('format must be a string');
        }

        if(format === undefined) {
            for(format in this.partials) {
                if(this.partials.hasOwnProperty(format) && !this.hasPartial(name, format))
                    return false;
            }

            return true;
        }
        else {
            return this.partials[format] && this.partials[format][name] !== undefined;
        }
    };

    /*
        Register helper functions with the report engine. Helper functions
        are used by the Handlebars engine - see the Handlebars.js documentation
        for more details.

        The parameter is a map from format, to helper name to function, e.g.

        {
            all: {
                isText: function() { return false; }
            },

            text: {
                isText: function() { return true; }
            }
        }

        Could be used to install a helper called isText with one implementation
        for all formats other than text, and one implementation for the text
        format.

        fns: An object mapping formats to sets of functions to install, the
             Special format "all" may be used to register helpers with all
             formats.
    */
    ReportEngineObject.prototype.registerHelpers = function registerHelpers(fns) {
        if(!allinea.isObject(fns)) {
            throw new Error('fns must be an object');
        }

        allinea.forEach(this.engines, function registerHelpersWithEngine(engine, format) {
            if(fns.all) {
                engine.registerHelper(fns.all);
            }
            if(fns[format]) {
                engine.registerHelper(fns[format]);
            }
        });
    };

    /*
        Render the named template of the specified format data as the context
    */
    ReportEngineObject.prototype.render = function render(templateName, format, data ) {
        if(!allinea.isString(templateName)) {
            throw new Error('templateName must be a string');
        }

        if(!allinea.isString(format)) {
            throw new Error('format must be a string');
        }

        if(!allinea.isObject(data)) {
            throw new Error('data must be an object');
        }

        if(!this.partials[format]) {
            throw new Error('Invalid format "'+format+'"');
        }

        if(!this.partials[format][templateName]) {
            throw new Error('Invalid template "'+templateName+'" for '+format);
        }

        return this.partials[format][templateName](data);
    };

    // Initialise functions that require the browser API

    if(document && document.addEventListener && document.getElementsByTagName) {
        function invokeFunctions(fns, config, args) {
            if(config !== undefined && !allinea.isObject(config)) {
                throw new Error('config must be an object');
            }

            try {
                var self = this;
                allinea.forEach(fns, function invokeFunction(fn) {
                    fn.apply(self, args);
                });
            }
            catch(e) {
                if(!config || !config.quiet) {
                    console.error(e);
                }

                if(document && document.body && this.partials.html.errorTemplate) {
                    document.body.innerHTML = this.partials.html.errorTemplate(e);
                }
            }
        }
        /*
          Register a function to be called when a template has been fully loaded.

          Note, this allows the report engine to trap errors from dynamic
          content during initialisation.

          fn: The function to call.
        */
        ReportEngineObject.prototype.onInit = function onInit(fn) {
            if(!allinea.isFunction(fn)) {
                throw new Error('fn must be a function');
            }

            this.initFunctions.push(fn);
        };

        /*
            Invoke all the init functions registered with this ReportEngine via
            onInit.
        */
        ReportEngineObject.prototype.invokeInitFunctions = function invokeInitFunctions(config) {
            // NB: arguments is not an array, but it behaves like one so we
            // can use Array functions on it
            var args = Array.prototype.slice.call(arguments, 1)

            return invokeFunctions.call(this, this.initFunctions, config, args);
        };

        /*
          Register a function to be called when the DOM has been built from a
          template

          Note, this allows the report engine to trap errors from dynamic
          content during initialisation.

          fn: The function to call.
        */
        ReportEngineObject.prototype.afterRender = function onInit(fn) {
            if(!allinea.isFunction(fn)) {
                throw new Error('fn must be a function');
            }

            this.afterRenderFunctions.push(fn);
        };

        /*
            Invoke all the post-render functions registered with this ReportEngine via
            afterRender.
        */
        ReportEngineObject.prototype.invokeAfterRenderFunctions = function invokeAfterRenderFunctions(config) {
            // NB: arguments is not an array, but it behaves like one so we
            // can use Array functions on it
            var args = Array.prototype.slice.call(arguments, 1)

            return invokeFunctions.call(this, this.afterRenderFunctions, config, args);
        };

        /*
            Dynamically register HTML templates from <script> tags with
            type="text/html" and an id.

            The <script> tags will be removed from the page.
        */
        ReportEngineObject.prototype.loadHtmlTemplates = function loadHtmlTemplates() {
            var scripts = document.getElementsByTagName('script');
            var loadedScripts = [];
            var self = this;

            allinea.forEach(scripts, function loadScriptAsTemplate(script) {
                if (script && script.innerHTML && script.id) {
                    // text/html mime type for HTML templates
                    if(script.type === "text/html") {
                        self.registerPartial(script.id, 'html', script.innerHTML.trim());
                        loadedScripts.unshift(script);
                    }
                    // text/plain mime type for text templates
                    else if(script.type === "text/plain") {
                        self.registerPartial(script.id, 'text', script.innerHTML.trim());
                        loadedScripts.unshift(script);
                    }
                    // private/internal mime type for "all"
                    else if(script.type === "text/x.allinea-template") {
                        self.registerPartial(script.id, 'all', script.innerHTML.trim());
                        loadedScripts.unshift(script);
                    }
                }
            });

            for (i = 0, l = loadedScripts.length; i < l; i++) {
                loadedScripts[i].parentNode.removeChild(loadedScripts[i]);
            }
        };
    }


    // Create the global instance
    ReportEngine = new ReportEngineObject();
})();
