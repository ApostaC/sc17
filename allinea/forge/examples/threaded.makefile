####### Definitions
MPICC=mpicc

objects = threaded.o
cflags = -g -O0 -pthread
lflags = 
target = threaded

####### Implicit rules

.SUFFIXES: .c
.c.o:
	${MPICC} -c $(cflags) -o $@ $<

####### Target
all: $(target)

$(target) : $(objects)
	${MPICC} $(cflags) $(lflags) -o $(target) $(objects)

####### Objects

threaded.o :

####### Clean

.PHONY : clean
clean :
	-rm -f $(target) core $(objects) *~
