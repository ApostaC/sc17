

help: 
	@echo 'usage: make <option>'
	@echo '<option> can be'
	@echo "gen 		: 	matrix generator"	
	@echo "multiMyself 	:	matrix multiply paralleled by openMP"
	@echo "prime 		:	find prime"
	@echo "multiPrime 	: 	find prime paralleled by openMP"
	@echo "Prime 		:	prime + multiPrime"
	@echo "all 		:	all of above"
	@echo "clean 		: 	clean executable files"



all: tester gen multiMyself Prime 

gen: gen.c 
	g++ gen.c -o gen

multiMyself: multiMyself.cpp
	g++ multiMyself.cpp -o multiMyself

Prime: prime multiPrime

prime: prime.cpp
	g++ prime.cpp -o prime

multiPrime: multiPrime.cpp
	g++ multiPrime.cpp -o multiPrime

tester: tester.cpp
	g++ tester.cpp -o tester

#CLEAN
clean:
	rm -f *.o
	rm -f gen multiMyself prime multiPrime tester
