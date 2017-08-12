####### Definitions

objects = simple.o
cflags = -g -O0
lflags = 
target = simple

####### Implicit rules

.SUFFIXES: .c
.c.o:
	cc -c $(cflags) -o $@ $<

####### Target
all: $(target)

$(target) : $(objects)
	cc $(cflags) $(lflags) -o $(target) $(objects)

####### Objects

simple.o :

####### Clean

.PHONY : clean
clean :
	-rm -f $(target) core $(objects) *~
