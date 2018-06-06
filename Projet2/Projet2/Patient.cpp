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

void Patient::AffichagePatient(bool versionCourte) {
    cout << "\n";
	cout << "\n";
	cout << "Patient avec id " << uneSignature.getIdSignature() <<" peut avoir les maladies suivants:\n"; //we put *(int*) to get the value not the @ YOLO!
	if (versionCourte) {
		calculerProbMaladiesDistinctes();
		map<string, double>::iterator it;
		for (it = risqueMaladiesDistinctes.begin(); it != risqueMaladiesDistinctes.end(); ++it) {
			cout << "- " << (*it).first << " " << (*it).second*100 << "%\n";
		}
	}
	else {
		multimap<string, double>::iterator it;
		for (it = risqueMaladies.begin(); it != risqueMaladies.end(); ++it) {
		cout <<"- "<<(*it).first << " " << (*it).second*100 << "%\n";
		}
	}
}

void Patient::ajouterRisqueMaladie(pair<string,double> risqueUneMaladie) {
	risqueMaladies.insert(risqueUneMaladie);
}

void Patient::ajouterRisqueMaladieDistincte(pair<string, double> risqueUneMaladie) {
	risqueMaladiesDistinctes.insert(risqueUneMaladie);
}

multimap<string, double> Patient::getRisqueMaladies() {
	return risqueMaladies;
}

Signature Patient::getSignature() {
	return uneSignature;
}

void Patient::destroySignature() {
	uneSignature.destroyS();
}

void Patient::calculerProbMaladiesDistinctes() { // to insert the average of proba of each distinct maladie
	multimap<string, double>::iterator it;
	map<string, double>::iterator itDist;
	for (itDist = risqueMaladiesDistinctes.begin(); itDist != risqueMaladiesDistinctes.end(); itDist++) {
		double risqueTotUneMaladie = 0;
		int nbCetteMaladie = 0;
		for (it = risqueMaladies.begin(); it != risqueMaladies.end(); it++) {
			if (!itDist->first.compare(it->first)) {
				risqueTotUneMaladie += it->second;
				nbCetteMaladie++;
			}
		}
		double risqueMoyPerMaladie = risqueTotUneMaladie / nbCetteMaladie;
		itDist->second = risqueMoyPerMaladie;
	}
}

Patient::~Patient()
{
#ifdef MAP
	cout << "Appel au destructeur de <Patient>" << endl;
#endif
}
