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
		// updating probability of only distinct illnesses
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

// to have a controlled memory freeing
void Patient::destroySignature() {
	uneSignature.destroyS();
}

// calculating the proba of each distinct illness based on all of its signatures
void Patient::calculerProbMaladiesDistinctes() {
	multimap<string, double>::iterator it;
	map<string, double>::iterator itDist;
	for (itDist = risqueMaladiesDistinctes.begin(); itDist != risqueMaladiesDistinctes.end(); itDist++) {
		double risqueTotUneMaladie = 0;
		int nbCetteMaladie = 0;
		// calculating the sum of all probas of each signature of a certain illness
		for (it = risqueMaladies.begin(); it != risqueMaladies.end(); it++) {
			if (!itDist->first.compare(it->first)) {
				risqueTotUneMaladie += it->second;
				nbCetteMaladie++;
			}
		}
		double risqueMoyPerMaladie = 0;
		// calculating the average proba of this certain illness
		if (nbCetteMaladie!=0){
			risqueMoyPerMaladie = risqueTotUneMaladie / nbCetteMaladie;
		}
		// updating the map of distinct(unique) illnesses
		itDist->second = risqueMoyPerMaladie;
	}
}

Patient::~Patient()
{
#ifdef MAP
	cout << "Appel au destructeur de <Patient>" << endl;
#endif
}
