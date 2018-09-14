all:build

build: main.o FindMaxMin.o
	g++ main.o FindMaxMin.o -o hw3
main.o: main.cc
	g++ -c main.cc FindMaxMin.cc FindMaxMin.h student.h
FindMaxMin.o: FindMaxMin.h
	g++ -c FindMaxMin.cc FindMaxMin.h main.cc
