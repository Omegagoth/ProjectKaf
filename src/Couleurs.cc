#include "Couleurs.h"
#define DEFAUT_ROUGE 255
#define DEFAUT_VERT 255
#define DEFAUT_BLEU 255
#define DEFAUT_TRANSPARENCE 255



unsigned int Couleurs::getrouge() const
{
	return rouge;
}

unsigned int Couleurs::getvert() const
{
	return vert;
}

unsigned int Couleurs::getbleu() const
{
	return bleu;
}

unsigned int Couleurs::gettransparence() const
{
	return transparence;
}




void Couleurs::setrouge(unsigned int r)
{
	rouge = r;
	limiter();
}

void Couleurs::setvert(unsigned int v)
{
	vert = v;
	limiter();
}

void Couleurs::setbleu(unsigned int b)
{
	bleu = b;
	limiter();
}

void Couleurs::settransparence(unsigned int t)
{
	limiter();
	transparence = t;
}




Couleurs::Couleurs()
: rouge(DEFAUT_ROUGE), vert(DEFAUT_VERT), bleu(DEFAUT_BLEU), transparence(DEFAUT_TRANSPARENCE)
{}

Couleurs::Couleurs(unsigned int r, unsigned int v, unsigned int b, unsigned int t)
: rouge(r), vert(v), bleu(b), transparence(t)
{
	limiter();
}

Couleurs::Couleurs(Couleurs const& c)
: rouge(c.getrouge()), vert(c.getvert()), bleu(c.getbleu()), transparence(c.gettransparence())
{}

Couleurs::~Couleurs()
{}



void Couleurs::limiter()
{
	if(rouge > 255)
	{
		rouge = 255;
	}
	if(vert > 255)
	{
		vert = 255;
	}
	if(bleu > 255)
	{
		bleu = 255;
	}
	if(transparence > 255)
	{
		transparence = 255;
	}
}

