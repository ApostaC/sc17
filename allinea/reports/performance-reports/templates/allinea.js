// General, useful functions
var allinea = {};

// Initialise functions that only require ECMAScript, and no browser API
(function initAllinea() {
    function isArrayLike(obj) {
        if (!obj || obj.window === obj) {
            return false;
        }

        // Support: iOS 8.2 (not reproducible in simulator)
        // "length" in obj used to prevent JIT error (gh-11508)
        var length = "length" in Object(obj) && obj.length;

        if (obj.nodeType === 1 && length) {
            return true;
        }

        return allinea.isString(obj) || allinea.isArray(obj) || length === 0 ||
            (typeof length === 'number' && length > 0 && (length - 1) in obj);
    }

    allinea.isArray = Array.isArray;

    allinea.isString = function isString(value) {
        return typeof value === 'string';
    };

    allinea.isFunction = function isFunction(value) {
        return typeof value === 'function';
    };

    allinea.isObject = function isObject(value) {
        return value !== null && typeof value === 'object';
    };

    // This forEach implementation is adapted from Angular.js
    // angular.js is Copyright (c) 2010-2015 Google, Inc. http://angularjs.org
    // angular.js is MIT Licensed
    allinea.forEach = function forEach(obj, iterator, context) {
        var key, length;
        if (obj) {
            if (allinea.isFunction(obj)) {
                for (key in obj) {
                    // Need to check if hasOwnProperty exists,
                    // as on IE8 the result of querySelectorAll is an object without a hasOwnProperty function
                    if (key != 'prototype' && key != 'length' && key != 'name' && (!obj.hasOwnProperty || obj.hasOwnProperty(key))) {
                        iterator.call(context, obj[key], key, obj);
                    }
                }
            }
            else if (allinea.isArray(obj) || isArrayLike(obj)) {
                var isPrimitive = typeof obj !== 'object';
                for (key = 0, length = obj.length; key < length; key++) {
                    if (isPrimitive || key in obj) {
                        iterator.call(context, obj[key], key, obj);
                    }
                }
            }
            else if (obj.forEach && obj.forEach !== forEach) {
                obj.forEach(iterator, context, obj);
            }
            else if (typeof obj.hasOwnProperty === 'function') {
                // Slow path for objects inheriting Object.prototype, hasOwnProperty check needed
                for (key in obj) {
                    if (obj.hasOwnProperty(key)) {
                        iterator.call(context, obj[key], key, obj);
                    }
                }
            }
            else {
                // Slow path for objects which do not have a method `hasOwnProperty`
                for (key in obj) {
                    if (Object.prototype.hasOwnProperty.call(obj, key)) {
                        iterator.call(context, obj[key], key, obj);
                    }
                }
            }
        }
        return obj;
    };

    // Find the first element of an array that the predicate returns truthy for
    allinea.find = function find(obj, predicate, context) {
        var key, length;
        if (obj) {
            if (allinea.isFunction(obj)) {
                for (key in obj) {
                    // Need to check if hasOwnProperty exists,
                    // as on IE8 the result of querySelectorAll is an object without a hasOwnProperty function
                    if (key != 'prototype' && key != 'length' && key != 'name' && (!obj.hasOwnProperty || obj.hasOwnProperty(key))) {
                        if(predicate.call(context, obj[key], key, obj)) {
                            return obj[key];
                        }
                    }
                }
            }
            else if (allinea.isArray(obj) || isArrayLike(obj)) {
                var isPrimitive = typeof obj !== 'object';
                for (key = 0, length = obj.length; key < length; key++) {
                    if (isPrimitive || key in obj) {
                        if(predicate.call(context, obj[key], key, obj)) {
                            return obj[key];
                        }
                    }
                }
            }
            else if (typeof obj.hasOwnProperty === 'function') {
                for (key in obj) {
                    if (obj.hasOwnProperty(key)) {
                        if(predicate.call(context, obj[key], key, obj)) {
                            return obj[key];
                        }
                    }
                }
            }
            else {
                for (key in obj) {
                    if (Object.prototype.hasOwnProperty.call(obj, key)) {
                        if(predicate.call(context, obj[key], key, obj)) {
                            return obj[key];
                        }
                    }
                }
            }
        }
        return undefined;
    };

    allinea.replaceAll = function replaceAll(inputStr, replaceStr, withStr) {
        return inputStr.split(replaceStr).join(withStr);
    };

    // Remove all elements from an array that predicate returns truthy for and
    // return all removed elements.
    allinea.remove = function remove(array, predicate) {
        var i = array.length;
        var result = [];
        while(i--) {
            if(predicate(array[i], i, array)) {
                result.unshift(array.splice(i, 1)[0]);
            }
        }
        return result;
    };

    // Remove CDATA wrappers from a string
    allinea.removeCdata = function removeCdata(s) {
        var cdataRe = /<!\[CDATA\[([\s\S]*?)\]\]>/g;
        return s.replace(cdataRe, '$1');
    };

    // Generates a unique ID based on given string that is suitable for the
    // global "id" HTML attribute.
    //
    // Calling this function twice (or more) with the same input string will
    // result in different results to ensure uniqueness, for example:
    //    1st: name -> name
    //    2nd: name -> name2
    allinea.makeId = function makeId(str) {
        // From https://developer.mozilla.org/en-US/docs/Web/HTML/Global_attributes/id
        //  "Using characters except ASCII letters and digits, '_', '-' and '.' may cause
        //   compatibility problems, as they weren't allowed in HTML 4.
        //   Though this restriction has been lifted in HTML 5, an ID should start
        //   with a letter for compatibility."
        var filterAway = /[^a-zA-Z0-9_\-.]/gi;
        var cleanId = str.replace(filterAway, '').toLowerCase();

        // Additionally, we filter trailing numbers away as we don't want them
        // to conflict with our counter we might add to ensure uniqueness, i.e.
        // we don't want that to happen:
        //   1st: name2 -> name2
        //   2nd: name  -> name
        //   3rd: name  -> name2 # conflicts with 1st!
        var filterTrailingNumberAway = /[0-9]*$/;
        cleanId = cleanId.replace(filterTrailingNumberAway, '');

        // Ensure ID starts with letter.
        var hasLeadingLetter = /^[a-z]/;
        if (cleanId.match(hasLeadingLetter) === null) {
            cleanId = "x" + cleanId;
        }

        // If we already have such ID, add counter to ensure uniqueness
        if (this.idCounters.hasOwnProperty(cleanId)) {
            var counter = ++this.idCounters[cleanId];
            this.idCounters[cleanId] = counter;
            return cleanId + counter;
        }

        this.idCounters[cleanId] = 1;
        return cleanId;
    };
    allinea.idCounters = {};

    // Lookup an object or array member using dot notation
    allinea.lookup = function lookup(obj, path) {
        if(path) {
            path = path.split('.');
            while(path.length > 0 && obj !== undefined) {
                if(allinea.isObject(obj)) {
                    obj = obj[path.shift()];
                }
                else {
                    return undefined;
                }
            }
        }
        return obj;
    };

    // Convert a value to a boolean, with tolerance for falsy values that have
    // been converted to strings
    allinea.toBool = function toBool(value) {
        var falsyStrings = [
            ''+false,
            ''+0,
            ''+-0,
            ''+null,
            ''+undefined,
            ''+NaN
        ];

        if (falsyStrings.indexOf(value) >= 0) {
            return false;
        }
        else {
            return !!value;
        }
    };
})();

// Initialise functions that require the browser API
var document;
(function initAllineaBrowser() {
    if(document && document.getElementById) {
        // Retrieve JSON content from an element with the specified id, or return
        // null if the element was not found
        allinea.getElementJson = function getElementJson(id) {
            var elem = document.getElementById(id);
            if(elem) {
                return JSON.parse(allinea.removeCdata(elem.innerHTML));
            }
            else {
                return null;
            }
        };
    }

    if(document && document.getElementById) {
        // set the innerHTML of an element with the specified id
        allinea.setElementInnerHtml = function setElementInnerHtml(id, html) {
            var elem = document.getElementById(id);
            if(elem) {
                elem.innerHTML = html;
            }
        };
    }

    if(document && document.createElement && document.getElementsByTagName) {
        // Use to insert CSS rules dynamically (adapted from
        // https://davidwalsh.name/add-rules-stylesheets)
        allinea.sheet = (function sheet() {
            // Create the <style> tag
            var style = document.createElement("style");

            // WebKit hack :(
            try {
                style.appendChild(document.createTextNode(""));
            } catch (err) { /* ignore silently in IE8 */ }

            // Add the <style> element to the page
            var head = document.head;
            if (typeof head == 'undefined') {
                // for IE8
                head = document.getElementsByTagName('head')[0];
            }
            head.appendChild(style);
            return style.sheet;
        })();
    }
})();
