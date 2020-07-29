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
	$(CXX) -pthread -o $(BIN)/runtests $(BIN)/Test.o $(BIN)/TestBinaryTree.o \
	$(BIN)/TestLinkedList.o $(BIN)/BinaryTree.o $(BIN)/ConstIterator.o \
	$(BIN)/LinkedList.o $(BIN)/Iterator.o

datastructures: BinaryTree.o ConstIterator.o Iterator.o LinkedList.o

BinaryTree.o: $(DATASTRUCTURES)/binarytree/BinaryTree.cpp \
    $(DATASTRUCTURES)/binarytree/BinaryTree.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(DATASTRUCTURES)/binarytree/BinaryTree.cpp -o \
	$(BIN)/BinaryTree.o

ConstIterator.o: $(DATASTRUCTURES)/iterator/ConstIterator.cpp \
    $(DATASTRUCTURES)/iterator/ConstIterator.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(DATASTRUCTURES)/iterator/ConstIterator.cpp -o \
	$(BIN)/ConstIterator.o

Iterator.o: $(DATASTRUCTURES)/iterator/Iterator.cpp \
    $(DATASTRUCTURES)/iterator/Iterator.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(DATASTRUCTURES)/iterator/Iterator.cpp -o \
	$(BIN)/Iterator.o

LinkedList.o: $(DATASTRUCTURES)/linkedlist/LinkedList.cpp \
    $(DATASTRUCTURES)/linkedlist/LinkedList.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(DATASTRUCTURES)/linkedlist/LinkedList.cpp -o \
	$(BIN)/LinkedList.o

test: TestBinaryTree.o TestIterator.o TestLinkedList.o Test.o

TestBinaryTree.o: $(TESTDATASTRUCTURES)/TestBinaryTree.cpp
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(TESTDATASTRUCTURES)/TestBinaryTree.cpp -o \
	$(BIN)/TestBinaryTree.o

TestIterator.o: $(TESTDATASTRUCTURES)/TestIterator.cpp
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(TESTDATASTRUCTURES)/TestIterator.cpp -o \
	$(BIN)/TestIterator.o

TestLinkedList.o: $(TESTDATASTRUCTURES)/TestLinkedList.cpp
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(TESTDATASTRUCTURES)/TestLinkedList.cpp -o \
	$(BIN)/TestLinkedList.o

Test.o: $(TEST)/Test.cpp
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) -c $(TEST)/Test.cpp -o $(BIN)/Test.o

clean:
	rm $(BIN)/BinaryTree.o
	rm $(BIN)/ConstIterator.o
	rm $(BIN)/Iterator.o
	rm $(BIN)/LinkedList.o
	rm $(BIN)/TestBinaryTree.o
	rm $(BIN)/TestIterator.o
	rm $(BIN)/TestLinkedList.o
	rm $(BIN)/Test.o
	rm $(BIN)/runtests
