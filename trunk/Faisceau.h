#include <iosream>
#include <vector>

using namespace std;


class Faisceau
{
	protected :
	
	Particule reference;
	double nb_particule;
	double lambda;
	vector<Particule*> Vpart;
	
	public :
	
	Faisceau(Particule, double, double);
	Faisceau(Faisceau const&);
	Faisceau();
	~Faisceau();
	
	void setreference(Particule const&);
	void setnb_particule(double);
	void setlambda(double);
	
	
	Particule getreference() const;
	double getnb_particule() const;
	double getlambda() const;
	vector<Particule> getVpart() const;
	
	Faisceau& ajoute_Vpart(Particule const&);
	Faisceau& clear Vpart();
	
	double getenergie_moy() const;
	
	double getemittance() const;
	
};
