#if ! defined (Analyse_H)
#define Analyse_H
#include <vector>
#include "Maladie.h"
#include "Patient.h"
#include "AttributCarac.h"
#include "AttributNum.h"

class Analyse
{
public:
	Analyse();
	Patient FaireAnalyse(Patient unPatient, vector<Maladie> maladies);
	vector<double> risqueNumerique(Attribut* attPatient, vector<Attribut*> attMaladie);
	vector<double> risqueCategorique(Attribut* attPatient, vector<Attribut*> attMaladie);
	~Analyse();

};

#endif
