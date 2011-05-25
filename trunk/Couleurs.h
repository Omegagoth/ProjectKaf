#ifndef COULEURS_H
#define COULEURS_H

class Couleurs
{
	public :
	
		unsigned int getrouge() const;
		unsigned int getvert() const;
		unsigned int getbleu() const;
		unsigned int gettransparence() const;
		
		void setrouge(unsigned int);
		void setvert(unsigned int);
		void setbleu(unsigned int);
		void settransparence(unsigned int);
		
		Couleurs();
		Couleurs(unsigned int, unsigned int, unsigned int, unsigned int);
		Couleurs(Couleurs const&);
		~Couleurs();
	
	protected :
	
		unsigned int rouge;
		unsigned int vert;
		unsigned int bleu;
		unsigned int transparence;
		
		void limiter();
};


#endif

