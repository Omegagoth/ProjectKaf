#ifndef TELESCOPE_H
#define TELESCOPE_H

#include "wxIncludes"
#include <vector>

using namespace std;

class Telescope
{
	public :
	
		double getRotation() const;
		double getInclinaison() const;
		
		void setRotation(double);
		void setInclinaison(double);
		
		Telescope();
		Telescope(double, double);
		virtual ~Telescope();
		
		void dessine();
	
	protected :
	
		double rotation;
		double inclinaison;
};


#endif


