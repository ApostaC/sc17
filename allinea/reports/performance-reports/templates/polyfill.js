// ES5.1 polyfills

// These are mostly borrowed from the Mozilla Developer Network, or
// https://github.com/es-shims/es5-shim

// Polyfill for IE<9
if (!Array.prototype.indexOf) {
    Array.prototype.indexOf = function(searchElement, fromIndex) {
        if (this == null) {
            throw new TypeError('"this" is null or not defined');
        }

        var o = Object(this);
        var len = o.length >>> 0;
        if (len === 0) {
            return -1;
        }

        var n = +fromIndex || 0;
        if (Math.abs(n) === Infinity) {
            n = 0;
        }

        if (n >= len) {
            return -1;
        }

        var k = Math.max(n >= 0 ? n : len - Math.abs(n), 0);
        while (k < len) {
            if (k in o && o[k] === searchElement) {
                return k;
            }

            k++;
        }

        return -1;
    };
}

// Polyfill for FF<4, IE<9
if (!Array.isArray) {
    Array.isArray = function(arg) {
        return Object.prototype.toString.call(arg) === '[object Array]';
    };
}

// Polyfill for IE<9
if (!String.prototype.trim) {
    (function() {
        var ws = '\x09\x0A\x0B\x0C\x0D\x20\xA0\u1680\u180E\u2000\u2001\u2002\u2003' +
            '\u2004\u2005\u2006\u2007\u2008\u2009\u200A\u202F\u205F\u3000\u2028' +
            '\u2029\uFEFF';
        var trimBeginRegexp = new RegExp('^' + wsRegexChars + wsRegexChars + '*');
        var trimEndRegexp = new RegExp(wsRegexChars + wsRegexChars + '*$');

        String.prototype.trim = function () {
            return this.replace(trimBeginRegexp, '').replace(trimEndRegexp, '');
        };
    })();
}

// Polyfill for FF<1.5, IE<9
if (!Array.prototype.map) {
  Array.prototype.map = function(callback, thisArg) {

    var T, A, k;
    if (this == null) {
      throw new TypeError(' this is null or not defined');
    }

    var O = Object(this);
    var len = O.length >>> 0;
    if (typeof callback !== 'function') {
      throw new TypeError(callback + ' is not a function');
    }

    if (arguments.length > 1) {
      T = thisArg;
    }

    A = new Array(len);
    k = 0;

    while (k < len) {
      var kValue, mappedValue;

      if (k in O) {
        kValue = O[k];
        mappedValue = callback.call(T, kValue, k, O);
        A[k] = mappedValue;
      }
      k++;
    }

    return A;
  };
}

var console;
if(!console) {
    function Console() {
        function stringifyHelper(key, value) {
            if(typeof value === 'function') {
                var str = value.toString();
                return str.substring(0, str.indexOf('{'))+'{...}';
            }
            else {
                return value;
            }
        }

        function argumentsToMessage() {
            var messages = [];
            for(var i=0; i<arguments.length; ++i) {
                messages.push(JSON.stringify(arguments[i],stringifyHelper,2));
            }

            return messages.join(' ');
        };

        this.print = function() {
            print.apply(this, arguments);
        };

        this.log = this.debug = this.info = this.warn = this.error = function() {
            print(argumentsToMessage.apply(this, arguments));
        };
    }

    // The web console is a nicer form of logging - make it available
    console = new Console();
}

