# Makefile
# Author: Gabor Madl
# Date: Created 07/2020
# Brief: Makefile to build project.
#
# https://github.com/gabemadl/algorithm
# Copyright (c) 2020 Gabor Madl, All Rights Reserved.

CXX = g++

CPPFLAGS = -O3
CPPINCLUDE = -Isrc/cpp

BIN = bin
ALGORITHM = src/cpp/algorithm
DATASTRUCTURES = $(ALGORITHM)/datastructures
TEST = test/cpp/algorithm
TESTDATASTRUCTURES = $(TEST)/datastructures

all: common datastructures test
	mkdir -p $(BIN)
	$(CXX) -pthread -o $(BIN)/runtests $(BIN)/Test.o $(BIN)/TestAvlTree.o \
	$(BIN)/TestBinaryTree.o $(BIN)/TestIterator.o $(BIN)/TestLinkedList.o \
	$(BIN)/Common.o $(BIN)/AvlTree.o $(BIN)/BinaryTree.o \
	$(BIN)/ConstIterator.o $(BIN)/LinkedList.o $(BIN)/Iterator.o

common: Common.o

Common.o: $(ALGORITHM)/Common.cpp \
    $(ALGORITHM)/Common.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) $(CPPINCLUDE) \
	-c $(ALGORITHM)/Common.cpp -o \
	$(BIN)/Common.o

datastructures: AvlTree.o BinaryTree.o ConstIterator.o Iterator.o LinkedList.o

AvlTree.o: $(DATASTRUCTURES)/avltree/AvlTree.cpp \
    $(DATASTRUCTURES)/avltree/AvlTree.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) $(CPPINCLUDE) \
	-c $(DATASTRUCTURES)/avltree/AvlTree.cpp -o \
	$(BIN)/AvlTree.o

BinaryTree.o: $(DATASTRUCTURES)/binarytree/BinaryTree.cpp \
    $(DATASTRUCTURES)/binarytree/BinaryTree.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) $(CPPINCLUDE) \
	-c $(DATASTRUCTURES)/binarytree/BinaryTree.cpp -o \
	$(BIN)/BinaryTree.o

ConstIterator.o: $(DATASTRUCTURES)/iterator/ConstIterator.cpp \
    $(DATASTRUCTURES)/iterator/ConstIterator.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) $(CPPINCLUDE) \
	-c $(DATASTRUCTURES)/iterator/ConstIterator.cpp -o \
	$(BIN)/ConstIterator.o

Iterator.o: $(DATASTRUCTURES)/iterator/Iterator.cpp \
    $(DATASTRUCTURES)/iterator/Iterator.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) $(CPPINCLUDE) \
	-c $(DATASTRUCTURES)/iterator/Iterator.cpp -o \
	$(BIN)/Iterator.o

LinkedList.o: $(DATASTRUCTURES)/linkedlist/LinkedList.cpp \
    $(DATASTRUCTURES)/linkedlist/LinkedList.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) $(CPPINCLUDE) \
	-c $(DATASTRUCTURES)/linkedlist/LinkedList.cpp -o \
	$(BIN)/LinkedList.o

test: TestAvlTree.o TestBinaryTree.o TestIterator.o TestLinkedList.o Test.o

TestAvlTree.o: $(TESTDATASTRUCTURES)/TestAvlTree.cpp \
    $(TESTDATASTRUCTURES)/TestAvlTree.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) $(CPPINCLUDE) \
	-c $(TESTDATASTRUCTURES)/TestAvlTree.cpp -o \
	$(BIN)/TestAvlTree.o

TestBinaryTree.o: $(TESTDATASTRUCTURES)/TestBinaryTree.cpp \
    $(TESTDATASTRUCTURES)/TestBinaryTree.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) $(CPPINCLUDE) \
	-c $(TESTDATASTRUCTURES)/TestBinaryTree.cpp -o \
	$(BIN)/TestBinaryTree.o

TestIterator.o: $(TESTDATASTRUCTURES)/TestIterator.cpp \
    $(TESTDATASTRUCTURES)/TestIterator.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) $(CPPINCLUDE) \
	-c $(TESTDATASTRUCTURES)/TestIterator.cpp -o \
	$(BIN)/TestIterator.o

TestLinkedList.o: $(TESTDATASTRUCTURES)/TestLinkedList.cpp \
    $(TESTDATASTRUCTURES)/TestLinkedList.h
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) $(CPPINCLUDE) \
	-c $(TESTDATASTRUCTURES)/TestLinkedList.cpp -o \
	$(BIN)/TestLinkedList.o

Test.o: $(TEST)/Test.cpp
	mkdir -p $(BIN)
	$(CXX) $(CPPFLAGS) $(CPPINCLUDE) \
	-c $(TEST)/Test.cpp -o $(BIN)/Test.o

clean:
	rm $(BIN)/AvlTree.o
	rm $(BIN)/BinaryTree.o
	rm $(BIN)/Common.o
	rm $(BIN)/ConstIterator.o
	rm $(BIN)/Iterator.o
	rm $(BIN)/LinkedList.o
	rm $(BIN)/TestAvlTree.o
	rm $(BIN)/TestBinaryTree.o
	rm $(BIN)/TestIterator.o
	rm $(BIN)/TestLinkedList.o
	rm $(BIN)/Test.o
	rm $(BIN)/runtests
