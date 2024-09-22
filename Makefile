

CXXFLAGS=--std=c++17

all:
	g++ $(CXXFLAGS) -o heap heap.cpp

clean:
	rm -fr imgs
