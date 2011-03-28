#include <iostream>
#include "Section_droite.h"
using namespace std;

Section_droite::Section_droite()
:Droit()  {}

Section_droite::Section_droite(Vecteur3D v1, Vecteur3D v2, double d)
:Droit(v1,v2, d)  {}

Section_droite::Section_droite(Section_droite const& s)
:Droit(s), champs_magnetique(s.getchamps_magnetique)  {}

Section_droite::~Sectiondroite()  {}