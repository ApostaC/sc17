####### Definitions

objects = stl_example.o
cflags = -g -O0
lflags = 
target = stl_example

####### Implicit rules

.SUFFIXES: .cpp
.cpp.o:
	g++ -c $(cflags) -o $@ $<

####### Target
all: $(target)

$(target) : $(objects)
	g++ $(cflags) $(lflags) -o $(target) $(objects)

####### Objects

stl_example.o :

####### Clean

.PHONY : clean
clean :
	-rm -f $(target) core $(objects) *~
