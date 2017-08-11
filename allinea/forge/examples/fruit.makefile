all: fruit

fruit: fruit.cc
	${CXX} -g -O0 fruit.cc -o fruit

clean:
	-rm -f fruit
