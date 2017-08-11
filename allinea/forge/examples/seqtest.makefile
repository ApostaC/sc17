####### Definitions

objects = seqtest.o
cflags = -g -O0
lflags = 
target = seqtest

####### Implicit rules

.SUFFIXES: .c
.c.o:
	cc -c $(cflags) -o $@ $<

####### Target
all: $(target)

$(target) : $(objects)
	cc $(cflags) $(lflags) -o $(target) $(objects)

####### Objects

seqtest.o :

####### Clean

.PHONY : clean
clean :
	-rm -f $(target) core $(objects) *~
