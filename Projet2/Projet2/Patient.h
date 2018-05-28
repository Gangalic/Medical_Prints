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
	void AffichagePatient();
	void ajouterRisqueMaladie(pair<string, double> risqueUneMaladie);
	Signature getSignature();
	~Patient();

private:
	Signature uneSignature;
	multimap<string, double> risqueMaladies;
};

#endif