#include "Telescope.h"

double Telescope::getRotation() const
{
	return rotation;
}

double Telescope::getInclinaison() const
{
	return inclinaison;
}




void Telescope::setRotation(double r)
{
	rotation = r;
}

void Telescope::setInclinaison(double i)
{
	inclinaison = i;
}




Telescope::Telescope(double r, double i)
: rotation(r), inclinaison(i)
{}
