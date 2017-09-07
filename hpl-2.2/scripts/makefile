F_C11=-std=c++11

CC=gcc
CXX=g++
CXXFLAGS= ${F_C11}

all: generate


generate: generate.cpp
	${CXX} generate.cpp -o generate ${CXXFLAGS}

analysiser: analysiser.cpp
	${CXX} analysiser.cpp -o analysiser ${F_C11}
