prog: symbol.o main.o tests.o simplify.o simplify.hpp
	g++ -std=c++11 -g -O0 -Wall -fPIC simplify.o tests.o symbol.o main.o -o prog

symbol.o: symbol.cpp symbol.hpp
	g++ -std=c++11 -c -g -O0 -Wall -fPIC $<

simplify.o: simplify.cpp simplify.hpp
	g++ -std=c++11 -c -g -O0 -Wall -fPIC $<

tests.o: tests.cpp
	g++ -std=c++11 -c -g -O0 -Wall -fPIC $<

main.o: main.cpp
	g++ -std=c++11 -c -g -O0 -Wall -fPIC $<

libsymbol.so: symbol.o simplify.o
	g++ -shared -std=c++11 -g -O0 -Wall -fPIC simplify.o symbol.o -o libsymbol.so

.PHONY: clean
clean:
	rm *.o *.a *.so
