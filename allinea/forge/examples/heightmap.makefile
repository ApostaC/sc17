####### Definitions
MPICC=mpicc

objects = heightmap.o
cflags = -g -O0
lflags = -lm
target = heightmap

####### Implicit rules

.SUFFIXES: .c
.c.o:
	${MPICC} -c $(cflags) -o $@ $<

####### Target
all: $(target)

$(target) : $(objects)
	${MPICC} -o $(target) $(objects) $(lflags)

####### Objects

hello.o :

####### Clean

.PHONY : clean
clean :
	-rm -f $(target) core $(objects) *~
