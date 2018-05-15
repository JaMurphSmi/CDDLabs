# Author : Jake Murphy Smith 13/9/2017
# Topic : Improved Makefile
# Purpose : Used to contain commands to compile projects
# Quote from Joe : Equivalent(?) to a project file in VStudio -- only better!
#

EXE= rendezvous
CC=g++
CFLAGS= -std=c++11 -pthread
CPPFILES= Semaphore.cpp rendezvous.cpp
HFILES= Semaphore.h

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(CPPFILES) $(HFILES)
	$(CC) -o $(EXE) $(CPPFILES) $(CFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL


DOC:
	#@doxygen -g
	@PROJECT=Lab2 OUTPUT=./docs doxygen Doxyfile
DOC: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
