CC  = c++
CXX = c++

CXXFLAGS += `wx-config --cxxflags`
LDLIBS   += `wx-config --libs gl,core,base`

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
# CXXFLAGS += -ansi -pedantic -Wall   # pour les purs et durs
CXXFLAGS += -g                      # pour debugger
# CXXFLAGS += -pg                     # pour profiler
# LDFLAGS  += -pg                     # pour profiler
CXXFLAGS += -O2                     # pour optimiser la vitesse

all: testFaisceau

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

Element.o : Element.cc Element.h

Particule.o : Particule.cc Particule.h

Courbe.o : Courbe.cc Courbe.h

Droit.o : Droit.cc Droit.h

Dipole.o : Dipole.cc Dipole.h

Section_droite.o : Section_droite.cc Section_droite.h

Quadrupole.o : Quadrupole.cc Quadrupole.h

Fodo.o : Fodo.cc Fodo.h

Accelerateur.o : Accelerateur.cc Accelerateur.h

Particule3D.o : Particule3D.cc Particule3D.h

Faisceau.o : Faisceau.cc Faisceau.h

testFaisceau.o : testFaisceau.cc

testFaisceau : testFaisceau.o  Faisceau.o Accelerateur.o Fodo.o Quadrupole.o Section_droite.o Particule.o Vecteur3D.o Element.o Droit.o Courbe.o Dipole.o

