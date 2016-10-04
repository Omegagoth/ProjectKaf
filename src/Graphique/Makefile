CC  = g++
CXX = g++
 
CXXFLAGS= `wx-config --cxxflags`
LDLIBS   = `wx-config --libs gl,core,base`
 
all: Application
 
Application.o: Application.cc Application.h
FenetreGL.o: FenetreGL.cc FenetreGL.h
VueOpenGL.o: VueOpenGL.cc VueOpenGL.h
Application: Application.o FenetreGL.o VueOpenGL.o
