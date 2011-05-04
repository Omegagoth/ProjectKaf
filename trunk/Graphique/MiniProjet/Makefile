CC  = g++
CXX = g++
 
CXXFLAGS= `wx-config --cxxflags`
LDLIBS   = `wx-config --libs gl,core,base`
 
all: Application
 
Application.o: Application.cc Application.h
FenetreGL.o: FenetreGL.cc FenetreGL.h
Camera.o : Camera.cc Camera.h
VueOpenGL.o: VueOpenGL.cc VueOpenGL.h
GLUtils.o: GLUtils.cc GLUtils.h
Telescope.o: Telescope.cc Telescope.h
Application: Application.o FenetreGL.o VueOpenGL.o Camera.o GLUtils.o Telescope.o
