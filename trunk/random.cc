#include "Bunch.h"


double Random::uniforme(double a, double b)
{
	return a + (rand() / double(RAND_MAX)) * (b-a);
}


void Random::init_hasard(unsigned int graine)
{
	if (graine == 0)
	{srand(time(0));}
	else 
	{srand(graine);}
}
