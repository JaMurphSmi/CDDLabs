<<<<<<< HEAD
# Author : Jake Murphy Smith 13/9/2017
# Topic : Improved Makefile
# Purpose : Used to contain commands to compile projects
# Quote from Joe : Equivalent(?) to a project file in VStudio -- only better!
=======
#Jake Murphy Smith 13/9/2017
#Improved Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
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

<<<<<<< HEAD
DOC:
	#@doxygen -g
	@PROJECT=Lab2 OUTPUT=./docs doxygen Doxyfile
DOC: ALL

=======
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
#this is customary and just deletes all .o files
CLEAN:
	rm *.o
