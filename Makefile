make:
	g++ matrix.hpp matrix.cpp bruteForce.hpp bruteForce.cpp genetic.hpp genetic.cpp time.hpp time.cpp main.cpp
	./a.out
clear:
	rm a.out time.hpp.gch