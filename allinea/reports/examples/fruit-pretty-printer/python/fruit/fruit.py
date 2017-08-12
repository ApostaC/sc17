# This example is licensed by Red Hat under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
# Original: https://access.redhat.com/site/documentation/en-US/Red_Hat_Enterprise_Linux/6/html/Developer_Guide/debuggingprettyprinters.html

class FruitPrinter:
    def __init__(self, val):
        self.val = val

    def to_string (self):
        fruit = self.val['fruit']
        
        if (fruit == 0):
            name = "Orange"
        elif (fruit == 1):
            name = "Apple"
        elif (fruit == 2):
            name = "Banana"
        else:
            name = "unknown"
        return "Our fruit is " + name

def lookup_type (val):
    if str(val.type) == 'Fruit':
        return FruitPrinter(val)
    return None

def register_fruit_printers (obj):
    if obj == None:
        obj = gdb

    obj.pretty_printers.append (lookup_type)
