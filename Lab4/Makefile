# Author : Jake Murphy Smith
# Date : 24/03/2018
# Purpose : Used to contain commands to compile projects

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

DOC:
	#@doxygen -g
	@PROJECT=Lab4 OUTPUT=./docs doxygen Doxyfile
DOC: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
