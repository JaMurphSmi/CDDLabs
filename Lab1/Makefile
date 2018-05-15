<<<<<<< HEAD
# Author: Jake Murphy Smith
# Date : 13/9/2017
# Topic : Improved Makefile
# Purpose: Used to contain commands to compile projects
=======
#Jake Murphy Smith 13/9/2017
#Improved Makefile
#Used to contain commands to compile projects
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3

EXE= signal
CC=g++
CFLAGS= -std=c++11 -pthread
<<<<<<< HEAD
CPPFILES= Semaphore.cpp Signal.cpp
=======
CPPFILES= Semaphore.cpp signal.cpp
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
HFILES= Semaphore.h

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(CPPFILES) $(HFILES)
	$(CC) -o $(EXE) $(CPPFILES) $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

<<<<<<< HEAD
DOC:
	#@doxygen -g
	@PROJECT=Lab1 OUTPUT=./docs doxygen Doxyfile
DOC: ALL

=======
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
#this is customary and just deletes all .o files
CLEAN:
	rm *.o
