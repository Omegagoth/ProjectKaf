CC  = c++
CXX = c++

CXXFLAGS += `wx-config --cxxflags`
LDLIBS   = `wx-config --libs gl,core,base`

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
# CXXFLAGS += -ansi -pedantic -Wall   # pour les purs et durs
CXXFLAGS += -g                      # pour debugger
# CXXFLAGS += -pg                     # pour profiler
# LDFLAGS  += -pg                     # pour profiler
CXXFLAGS += -O2                     # pour optimiser la vitesse

all: Application




Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

Element.o : Element.cc Element.h

Particule.o : Particule.cc Particule.h

Courbe.o : Courbe.cc Courbe.h

Droit.o : Droit.cc Droit.h

Dipole.o : Dipole.cc Dipole.h

Section_droite.o : Section_droite.cc Section_droite.h

Quadrupole.o : Quadrupole.cc Quadrupole.h

Fodo.o : Fodo.cc Fodo.h

Particule.o : Particule.cc Particule.h

Faisceau.o : Faisceau.cc Faisceau.h

Faccelerateur.o : Faccelerateur.cc Faccelerateur.h

Particule3D.o : Particule3D.cc Particule3D.h

Element3D.o : Element3D.cc Element3D.h

Courbe3D.o : Courbe3D.cc Courbe3D.h

Droit3D.o : Droit3D.cc Droit3D.h

Dipole3D.o : Dipole3D.cc Dipole3D.h

Section_droite3D.o : Section_droite3D.cc Section_droite3D.h

Quadrupole3D.o : Quadrupole3D.cc Quadrupole3D.h

Fodo3D.o : Fodo3D.cc Fodo3D.h

VueOpenGL.o : VueOpenGL.cc VueOpenGL.cc

FentreGL.o : FenetreGL.cc FenetreGL.h

FenetreControle.o : FenetreControle.cc FenetreControle.h

GLUtils.o : GLUtils.cc GLUtils.h

TextureManager.o : TextureManager.cc TextureManager.h

Camera.o : Camera.cc Camera.h

Couleurs.o : Couleurs.cc Couleurs.h

Dessinable.o : Dessinable.cc Dessinable.h

Accelerateur.o : Accelerateur.cc Accelerateur.h

ExerciceP11bis.o : ExerciceP11bis.cc

Application.o : Application.cc Application.h

testFaccelerateur.o : testFaccelerateur.cc

random.o : random.cc random.h

bunch.o : bunch.cc bunch.h

ExerciceP18.o : ExerciceP18.cc


Application : Application.o Accelerateur.o Faisceau.o Faccelerateur.o Particule.o Fodo.o Quadrupole.o Section_droite.o Vecteur3D.o Element.o Droit.o Courbe.o Dipole.o Particule3D.o Element3D.o Courbe3D.o Droit3D.o Dipole3D.o Section_droite3D.o Quadrupole3D.o Fodo3D.o Couleurs.o FenetreGL.o FenetreControle.o GLUtils.o TextureManager.o VueOpenGL.o Camera.o



testFaccelerateur : testFaccelerateur.o Faisceau.o Faccelerateur.o Particule.o Fodo.o Quadrupole.o Section_droite.o Vecteur3D.o Element.o Droit.o Courbe.o Dipole.o Particule3D.o Element3D.o Courbe3D.o Droit3D.o Dipole3D.o Section_droite3D.o Quadrupole3D.o Fodo3D.o Couleurs.o

ExerciceP18 : ExerciceP18.o bunch.o random.o Faisceau.o Faccelerateur.o Particule.o Fodo.o Quadrupole.o Section_droite.o Vecteur3D.o Element.o Droit.o Courbe.o Dipole.o Particule3D.o Element3D.o Courbe3D.o Droit3D.o Dipole3D.o Section_droite3D.o Quadrupole3D.o Fodo3D.o Couleurs.o

ExerciceP11bis : ExerciceP11bis.o Accelerateur.o Particule.o Fodo.o Quadrupole.o Section_droite.o Vecteur3D.o Element.o Droit.o Courbe.o Dipole.o Particule3D.o Element3D.o Courbe3D.o Droit3D.o Dipole3D.o Section_droite3D.o Quadrupole3D.o Fodo3D.o Couleurs.o

clean :
	rm -f *.o
