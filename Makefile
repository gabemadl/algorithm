# Makefile
# Author: Gabor Madl
# Date: Created 07/2020
# Brief: Makefile to build project.
#
# https://github.com/gabemadl/algorithm
# Copyright (c) 2020 Gabor Madl, All Rights Reserved.

CXX = g++

CPPFLAGS = -O3

BIN = bin
DATASTRUCTURES = src/cpp/algorithm/datastructures
TEST = test/cpp/algorithm
TESTDATASTRUCTURES = $(TEST)/datastructures

all: datastructures test
	mkdir -p $(BIN)
	$(CXX) -pthread -o $(BIN)/runtests $(BIN)/Test.o $(BIN)/TestLinkedList.o \
    $(BIN)/LinkedList.o $(BIN)/Iterator.o $(BIN)/ConstIterator.o

datastructures: LinkedList.o Iterator.o ConstIterator.o

Iterator.o: $(DATASTRUCTURES)/iterator/Iterator.cpp \
    $(DATASTRUCTURES)/iterator/Iterator.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(DATASTRUCTURES)/iterator/Iterator.cpp -o \
	$(BIN)/Iterator.o

ConstIterator.o: $(DATASTRUCTURES)/iterator/ConstIterator.cpp \
    $(DATASTRUCTURES)/iterator/ConstIterator.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(DATASTRUCTURES)/iterator/ConstIterator.cpp -o \
	$(BIN)/ConstIterator.o

LinkedList.o: $(DATASTRUCTURES)/linkedlist/LinkedList.cpp \
    $(DATASTRUCTURES)/linkedlist/LinkedList.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(DATASTRUCTURES)/linkedlist/LinkedList.cpp -o \
	$(BIN)/LinkedList.o

test: TestLinkedList.o Test.o

TestLinkedList.o: $(TESTDATASTRUCTURES)/TestLinkedList.cpp
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(TESTDATASTRUCTURES)/TestLinkedList.cpp -o \
	$(BIN)/TestLinkedList.o

Test.o: $(TEST)/Test.cpp
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(TEST)/Test.cpp -o $(BIN)/Test.o

clean:
	rm $(BIN)/LinkedList.o
	rm $(BIN)/Iterator.o
	rm $(BIN)/ConstIterator.o
	rm $(BIN)/TestLinkedList.o
	rm $(BIN)/Test.o
	rm $(BIN)/runtests
