# Makefile
# Author: Gabor Madl

CXX = g++

CPPFLAGS = -O3

BIN = bin
DATASTRUCTURES = src/cpp/algorithm/datastructures
TEST = test/cpp/algorithm
TESTDATASTRUCTURES = $(TEST)/datastructures

all: datastructures test
	mkdir -p $(BIN)
	$(CXX) -pthread -o $(BIN)/runtests $(BIN)/Test.o $(BIN)/TestLinkedList.o $(BIN)/LinkedList.o

datastructures: LinkedList.o

LinkedList.o: $(DATASTRUCTURES)/linkedlist/LinkedList.cpp $(DATASTRUCTURES)/linkedlist/LinkedList.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(DATASTRUCTURES)/linkedlist/LinkedList.cpp -o $(BIN)/LinkedList.o

test: TestLinkedList.o Test.o

TestLinkedList.o: $(TESTDATASTRUCTURES)/TestLinkedList.cpp
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(TESTDATASTRUCTURES)/TestLinkedList.cpp -o $(BIN)/TestLinkedList.o

Test.o: $(TEST)/Test.cpp
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(TEST)/Test.cpp -o $(BIN)/Test.o

clean:
	rm $(BIN)/LinkedList.o
	rm $(BIN)/TestLinkedList.o
	rm $(BIN)/Test.o
	rm $(BIN)/runtests
