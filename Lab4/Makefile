<<<<<<< HEAD
# Author : Jake Murphy Smith
# Date : 24/03/2018
# Purpose : Used to contain commands to compile projects
=======
#Jake Murphy Smith 24/03/2018
#Used to contain commands to compile projects
#This particular Makefile is for the barrier lab.
#Two versions of this lab in one directory for funsies
#CFILES(CPP) and HFILES included for both versions
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3

EXE= ReuseBarrier
CC=g++
CFLAGS= -std=c++11 -pthread -I.
CPPFILES= Semaphore.cpp Barrier.cpp BarrierMain.cpp
HFILES= Semaphore.h Barrier.h
#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(CPPFILES) $(HFILES)
	$(CC) -o $(EXE) $(CFLAGS) $(CPPFILES) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0 -Wall
DEBUG: ALL

<<<<<<< HEAD
DOC:
	#@doxygen -g
	@PROJECT=Lab4 OUTPUT=./docs doxygen Doxyfile
DOC: ALL

=======
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
#this is customary and just deletes all .o files
CLEAN:
	rm *.o
