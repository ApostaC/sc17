####### Definitions

objects = count.o
cflags = -g -O0
lflags = 
target = count

####### Implicit rules

.SUFFIXES: .c
.c.o:
	cc -c $(cflags) -o $@ $<

####### Target
all: $(target)

$(target) : $(objects)
	cc $(cflags) $(lflags) -o $(target) $(objects)

####### Objects

count.o :

####### Clean

.PHONY : clean
clean :
	-rm -f $(target) core $(objects) *~
