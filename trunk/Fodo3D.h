#ifndef FODO3D_H
#define FODO3D_H

class Fodo3D : public Droit3D, public Fodo
{
	public :
	
		Fodo3D();
		Fodo3D(Vecteur3D, Vecteur3D, double, double, double, unsigned int, unsigned int, unsigned int, unsigned int);
		Fodo3D(Fodo3D const&);
		~Fodo3D();
		
		virtual Fodo3D* copie() const;
	
	protected :
	
};

#endif
