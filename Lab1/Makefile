# Author: Jake Murphy Smith
# Date : 13/9/2017
# Topic : Improved Makefile
# Purpose: Used to contain commands to compile projects

EXE= signal
CC=g++
CFLAGS= -std=c++11 -pthread
CPPFILES= Semaphore.cpp Signal.cpp
HFILES= Semaphore.h

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(CPPFILES) $(HFILES)
	$(CC) -o $(EXE) $(CPPFILES) $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

DOC:
	#@doxygen -g
	@PROJECT=Lab1 OUTPUT=./docs doxygen Doxyfile
DOC: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
