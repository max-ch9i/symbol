prog: main.o tests.o
	g++ -std=c++11 -g -O0 -Wall -fPIC tests.o main.o -o prog

tests.o: tests.cpp simplify.hpp
	g++ -std=c++11 -c -g -O0 -Wall -fPIC $<

main.o: main.cpp simplify.hpp
	g++ -std=c++11 -c -g -O0 -Wall -fPIC $<

# not in use
libsymbol.so: symbol.o simplify.o
	g++ -shared -std=c++11 -g -O0 -Wall -fPIC simplify.o symbol.o -o libsymbol.so

.PHONY: clean
clean:
	rm *.o *.a *.so
