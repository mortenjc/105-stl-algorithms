

CXXFLAGS=--std=c++17 -I.



all: utils.o heap sets


heap: heap.cpp utils.o
	g++ $(CXXFLAGS) -o heap heap.cpp utils.o

sets: sets.cpp utils.o	
	g++ $(CXXFLAGS) -o sets sets.cpp utils.o

utils.o: utils.cpp utils.h
	g++ $(CXXFLAGS) -c utils.cpp

clean:
	rm -fr imgs heap sets utils.o
