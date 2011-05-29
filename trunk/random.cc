#include "random.h"


double uniforme(double a, double b)
{
	return a + (rand() / double(RAND_MAX)) * (b-a);
}


void init_hasard(unsigned int graine)
{
	if (graine == 0)
	{srand(time(0));}
	else 
	{srand(graine);}
}
