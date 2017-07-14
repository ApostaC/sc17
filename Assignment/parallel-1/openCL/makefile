#test
SOURCE=main.cpp host_imp.cpp
HEADERS=host_imp.h

FLAGS= -lOpenCL -std=gnu++0x

all: main

main: $(HEADERS) $(SOURCE) makefile
	g++ $(SOURCE) -o main $(FLAGS)

clean:
	rm -f main
	rm -f *.o
