####### Definitions

objects = memdebug.o
cflags = -g -O0
lflags = 
target = memdebug

####### Implicit rules

.SUFFIXES: .cpp
.cpp.o:
	g++ -c $(cflags) -o $@ $<

####### Target
all: $(target)

$(target) : $(objects)
	g++ $(cflags) $(lflags) -o $(target) $(objects)

####### Objects

memdebug.o :

####### Clean

.PHONY : clean
clean :
	-rm -f $(target) core $(objects) *~
