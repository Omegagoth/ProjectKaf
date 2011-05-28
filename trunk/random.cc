#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

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



int main()
{
	init_hasard(0);
	cout << uniforme(1, 47) << endl;
	cout << "a" << endl;
	cout << uniforme(1, 47) << endl;
	return 0;
}