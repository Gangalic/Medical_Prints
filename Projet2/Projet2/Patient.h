#if ! defined (Patient_H)
#define Patient_H
#include "Signature.h"
#include <string>
#include <map>
#include <utility>

class Patient
{
public:
	Patient(Signature laSignature);
	void AffichagePatient(bool versionCourte);
	void ajouterRisqueMaladie(pair<string, double> risqueUneMaladie);
	void ajouterRisqueMaladieDistincte(pair<string, double> risqueUneMaladie);
	multimap<string, double> getRisqueMaladies();
	Signature getSignature();
	~Patient();

private:
	void calculerProbMaladiesDistinctes();
	Signature uneSignature;
	multimap<string, double> risqueMaladies;
	map<string, double> risqueMaladiesDistinctes;
};

#endif