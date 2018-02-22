CPPFLAGS = -Wall -pedantic -std=c++14 -o

main: main.cpp containers.h
	g++ main.cpp $(CPPFLAGS) main -lGL -lglut -lGLU
