using namespace std;
#include "Patient.h"
#include <iostream>

Patient::Patient(Signature laSignature)
{
#ifdef MAP
	cout << "Appel au constructeur de <Patient>" << endl;
#endif
	uneSignature = laSignature;
}

void Patient::AffichagePatient() {
    cout << "\n";
	cout << "\n";
	cout << "Patient avec id " << uneSignature.getIdSignature() <<" a les maladies suivants:\n";
	for (multimap<string, double>::iterator it = risqueMaladies.begin(); it != risqueMaladies.end(); ++it) {
		cout << (*it).first << " " << (*it).second << "\n";
	}
}

void Patient::ajouterRisqueMaladie(pair<string,double> risqueUneMaladie) {
	risqueMaladies.insert(risqueUneMaladie);
}

Signature Patient::getSignature() {
	return uneSignature;
}

Patient::~Patient()
{
#ifdef MAP
	cout << "Appel au destructeur de <Patient>" << endl;
#endif
}
