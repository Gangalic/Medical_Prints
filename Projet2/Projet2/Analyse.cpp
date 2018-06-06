using namespace std;
#include <map>
#include <string>
#include <cmath>
#include <utility>
#include <iostream> //to delete
#include "Analyse.h"



Analyse::Analyse()
{
#ifdef MAP
	cout << "Appel au constructeur par defaut de <Analyse>" << endl;
#endif
}

//sending back a patient
Patient Analyse::FaireAnalyse(Patient unPatient, vector<Maladie> maladies)
{
	Patient * patient = new Patient(unPatient.getSignature());
	vector<vector<double>> tabTousAttributs;
	//creation of two attributs to check for type of our pointer
	AttributCarac tempCarac = AttributCarac();
	AttributNum tempNum = AttributNum();
	//going through all the attributes of an illness
	Maladie uneMaladie = maladies[0];
	Signature uneSignatureDeMaladie = uneMaladie.getSignature();
	vector <Attribut *> unTabAttributDeMaladie = uneSignatureDeMaladie.getTabAttributs();
	vector <Attribut *> unTabAttributDeCertaineMaladie;
	for (int i = 0; i < unTabAttributDeMaladie.size(); i++) {
		vector<Attribut *> unAttributChaqueMaladie;
		//getting out i-th attribute of each illness and adding it to a vector
		for (int j = 0; j < maladies.size(); j++) {
			uneMaladie = maladies[j];
			uneSignatureDeMaladie = uneMaladie.getSignature();
			unTabAttributDeCertaineMaladie = uneSignatureDeMaladie.getTabAttributs();
			unAttributChaqueMaladie.push_back(unTabAttributDeCertaineMaladie[i]);
		}
		Signature uneSignaturePatient = unPatient.getSignature();
		vector <Attribut *> unTabAttributDePatient = uneSignaturePatient.getTabAttributs();
		Attribut * unAttributPatient = unTabAttributDePatient[i];
		//send i-th attribute of Patient and all illnesses to be able to calculate 
		//individual probabilities of NOT having a certain illness
		if (typeid(*unAttributPatient) == typeid(tempNum)) {
			tabTousAttributs.push_back(risqueNumerique(unAttributPatient, unAttributChaqueMaladie));
		}
		else if (typeid(*unAttributPatient) == typeid(tempCarac)) {
			tabTousAttributs.push_back(risqueCategorique(unAttributPatient, unAttributChaqueMaladie));
		}
	}
	//calculating the average probability of having each illness
	//and adding each detail to risqueMaladie attribute of Patient
	vector<double> attributsUnPatient = tabTousAttributs[0];
	for (int i = 0; i < attributsUnPatient.size(); i++) {
		int nbAttributsNonId = (int) tabTousAttributs.size();
		double sommeRisques = 0;
		for (int j = 0; j < nbAttributsNonId; j++) {
			sommeRisques += tabTousAttributs[j][i];
		}
		double risque = 1 - (sommeRisques / nbAttributsNonId);
		uneMaladie = maladies[i];
		pair<string, double> risqueUneMaladie = make_pair((string)uneMaladie.getNom(), risque);
		patient->ajouterRisqueMaladie(risqueUneMaladie);
	}
	return *patient;
}

vector<double> Analyse::risqueNumerique(Attribut* attPatient, vector<Attribut*> attMaladie)
{
	vector<double> proba;
	double delta;
	double min = 100000.0;
	double max = -100000.0;
	// finding the ranges of an attribute
	for (unsigned int i = 0; i < attMaladie.size(); i++)
	{
		double* a = (double*)attMaladie[i]->getValue();
		if (*a < min)
		{
			min = *a;
		}
		if (*a > max)
		{
			max = *a;
		}
	}
	delta=max - min;
	
	// calculating the probabilty of them being equal
	for (unsigned int i = 0; i < attMaladie.size(); i++)
	{
		double* valMaladie = (double*)(attMaladie[i]->getValue());
		double* valPatient = (double*)(attPatient->getValue());
		double deltaUnitaire = abs(*valPatient - *valMaladie);
		double uneProba=1.0;
		// checking if prob is between 0 and 1
		// and we don't have division by 0
		if (delta == 0.0) 
		{ //fucks up here
			uneProba = (*valPatient)/(*valMaladie);
		}
		else {
			uneProba = abs(deltaUnitaire / delta);
		}

		if (uneProba > 1) {
			proba.push_back(1.0);
		}
		else {
			proba.push_back(uneProba);
		}
	}

	return (proba);
}

vector<double> Analyse::risqueCategorique(Attribut* attPatient, vector<Attribut*> attMaladie)
{
	vector<double> proba;
	for (unsigned int i = 0; i < attMaladie.size(); i++)
	{
		string* a = (string*)attMaladie[i]->getValue();
		string* b = (string*)attPatient->getValue();
		if (*a == *b) {
			proba.push_back(0.0);
		}
		else {
			proba.push_back(1.0);
		}
	}
	return (proba);
}

Analyse::~Analyse()
{
#ifdef MAP
	cout << "Appel au destructeur de <Analyse>" << endl;
#endif
}

