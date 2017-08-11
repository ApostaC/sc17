####### Definitions

objects = matrix_mult.o
cflags = -g -O0
lflags = 
target = matrix_mult

####### Implicit rules

.SUFFIXES: .cpp
.cpp.o:
	mpicxx -c $(cflags) -o $@ $<

####### Target
all: $(target)

$(target) : $(objects)
	mpicxx $(cflags) $(lflags) -o $(target) $(objects)

####### Objects

matrix_mult.o :

####### Clean

.PHONY : clean
clean :
	-rm -f $(target) core $(objects) *~
