#Jake Murphy Smith 10/10/2017
#Used to contain commands to compile projects
#This particular Makefile is for the barrier lab.

EXE= Philosophers
CC=g++
CFLAGS= -std=c++11 -pthread
CFILES= Semaphore.cpp Philosophers.cpp
HFILES= Semaphore.h
#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(CFILES) $(HFILES)
	$(CC) -o $(EXE) $(CFLAGS) $(CFILES) $(DEBUGFLAGS) -Wall

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
