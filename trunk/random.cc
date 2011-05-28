#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

double uniforme(double a, double b)
{
	return a + (rand() / double(RAND_MAX)) * (b-a);
}


int main()
{
	srand(3);
	cout << rand() << endl;

	return 0;
}