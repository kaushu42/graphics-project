CPPFLAGS = -Wall -pedantic -std=c++14 -o

main: main.cpp objParser.cpp containers.h
	g++ main.cpp objParser.cpp $(CPPFLAGS) main -lGL -lglut -lGLU
