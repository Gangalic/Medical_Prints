#if ! defined (Analyse_H)
#define Analyse_H

class Analyse
{
public:
	Analyse();

	

	vector<double> risqueNumerique(Attribut* attPatient,vector<Attribut*> attMaladie);

	vector<double> risqueCategorique(Attribut* attPatient, vector<Attribut*> attMaladie);

	
	~Analyse();


};

#endif
