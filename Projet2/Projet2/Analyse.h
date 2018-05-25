#if ! defined (Analyse_H)
#define Analyse_H
#include <vector>

class Analyse
{
public:
    Analyse();

	Patient FaireAnalyse(Patient unPatient, vector<Maladie> maladies);

	vector<double> risqueNumerique(Attribut* attPatient, Attribut* attMaladie);

	vector<double> risqueCategorique(Attribut* attPatient, Attribut* attMaladie);

	
	~Analyse();


};

#endif
