prog: symbol.o main.o tests.o
	g++ -std=c++11 -g -O0 -Wall -fPIC tests.o symbol.o main.o -o prog

symbol.o: symbol.cpp symbol.hpp
	g++ -std=c++11 -c -g -O0 -Wall -fPIC $<

tests.o: tests.cpp
	g++ -std=c++11 -c -g -O0 -Wall -fPIC $<

main.o: main.cpp
	g++ -std=c++11 -c -g -O0 -Wall -fPIC $<

.PHONY: clean
clean:
	rm *.o *.a *.so
