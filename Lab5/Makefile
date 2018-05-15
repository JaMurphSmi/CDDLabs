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

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
