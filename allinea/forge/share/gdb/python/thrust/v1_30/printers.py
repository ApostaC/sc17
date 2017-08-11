# Pretty printers for thrust

import gdb
import re

class static:
    "Creates a 'static' method"
    def __init__(self, function):
        self.__call__ = function

thrust_pretty_printers = [ ]
def register_pretty_printer(pretty_printer):
    "Registers a Pretty Printer"
    thrust_pretty_printers.append(pretty_printer)
    return pretty_printer


@register_pretty_printer
class ThrustDeviceVector:
    "Print a thrust::device_vector"
    
    @static
    def supports(typename):
        return re.compile('^thrust::device_vector<.*>$').search(typename) 
    
    class _iterator:
        def __init__ (self, start, size):
            self.item = start
            self.size = size
            self.count = 0

        def __iter__(self):
            return self

        def next(self):
            if self.count == self.size:
                raise StopIteration
            count = self.count
            self.count = self.count + 1
            elt = self.item.dereference()
            self.item = self.item + 1
            return ('[%d]' % count, elt)

    def __init__(self, typename, val):
        self.typename = typename
        self.val = val

    def children(self):
        return self._iterator(self.val['m_storage']['m_begin'],
                            self.val['m_storage']['m_size'])

    def to_string(self):
        start = self.val['m_storage']['m_begin']
        size = self.val['m_storage']['m_size']
        return ('%s of length %d'
                % (self.typename, int (size)))

    def display_hint(self):
        return 'array'

def find_pretty_printer(value):
    "Find a pretty printer suitable for value"
    type = value.type
    
    if type.code == gdb.TYPE_CODE_REF:
        type = type.target()
        
    type = type.unqualified().strip_typedefs()
    
    typename = type.tag
    if typename == None:
        return None
    for pretty_printer in thrust_pretty_printers:
        if pretty_printer.supports(typename):
            return pretty_printer(typename,value)
        
    return None

def register_thrust_printers (obj):
    "Register Thrust pretty printers with objfile Obj."
    
    if obj == None:
        obj = gdb
    obj.pretty_printers.append (find_pretty_printer)
