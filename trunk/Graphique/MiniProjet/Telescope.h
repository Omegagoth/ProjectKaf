#ifndef TELESCOPE_H
#define TELESCOPE_H

using namespace std;

class Telescope
{
	public :
	
		double getRotation() const;
		double getInclinaison() const;
		
		void setRotation(double);
		void setInclinaison(double);
		
		Telescope(double, double);
	
	protected :
	
		double rotation;
		double inclinaison;
};


#endif


