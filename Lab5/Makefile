<<<<<<< HEAD
# Author : Jake Murphy Smith
# Date : 10/10/2017
# Purpose : Used to contain commands to compile projects
# Topic : This particular Makefile is to show an implementation of
# the producer consumer problem.

EXE= ProduceConsume
CC=g++
CFLAGS= -std=c++11 -pthread
CPPFILES= Semaphore.cpp ProduceConsume.cpp ProdConsumeMain.cpp
HFILES= Semaphore.h ProduceConsume.h

ALL: $(CPPFILES) $(HFILES)
	$(CC) -o $(EXE) $(CPPFILES) $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0 -Wall
DEBUG: ALL

DOC:
	#@doxygen -g
	@PROJECT=Lab5 OUTPUT=./docs doxygen Doxyfile
DOC: ALL

=======
#Jake Murphy Smith 10/10/2017
#Used to contain commands to compile projects
#This particular Makefile is for the barrier lab.

EXE= LeadFollow
CC=g++
CFLAGS= -std=c++11 -pthread
CPPFILES= Semaphore.cpp Folleader.cpp
HFILES= Semaphore.h
#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(CPPFILES) $(HFILES)
	$(CC) -o $(EXE) $(CPPFLAGS) $(CFILES) $(DEBUGFLAGS) -Wall

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
#this is customary and just deletes all .o files
CLEAN:
	rm *.o
