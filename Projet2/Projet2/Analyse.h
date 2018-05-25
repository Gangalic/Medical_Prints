#if ! defined (Analyse_H)
#define Analyse_H

class Analyse
{
public:
	Analyse();

	multimap<string,double> FaireAnalyse(Patient unPatient, vector<Maladie>maladies);

	double risqueNumerique(Attribut* attPatient,Attribut* attMaladie);

	double risqueCategorique(Attribut* attPatient, Attribut* attMaladie);

	
	~Analyse();


};

#endif
