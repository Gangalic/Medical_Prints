using namespace std;
#include <map>
#include <string>
#include <cmath>
#include <utility>
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
	Patient patient = Patient(unPatient.getSignature());
	vector<vector<double>> tabTousAttributs;
	//creation of two attributs to check for type of our pointer
	AttributCarac tempCarac = AttributCarac();
	AttributNum tempNum = AttributNum();
	//going through all the attributes of an illness
	for (int i = 0; i < maladies[0].getSignature().getTabAttributs().size(); i++) {
		vector<Attribut *> unAttributChaqueMaladie;
		//getting out i-th attribute of each illness and adding it to a vector
		for (int j = 0; j < maladies.size(); j++) {
			unAttributChaqueMaladie.push_back(maladies[j].getSignature().getTabAttributs()[i]);
		}
		Attribut * unAttributPatient = unPatient.getSignature().getTabAttributs()[i];
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
	for (int i = 0; i < tabTousAttributs[0].size(); i++) {
		int nbAttributsNonId = tabTousAttributs.size();
		double sommeRisques = 0;
		for (int j = 0; j < nbAttributsNonId; j++) {
			sommeRisques += tabTousAttributs[j][i];
		}
		double risque = 1 - sommeRisques / nbAttributsNonId;
		pair<string, double> risqueUneMaladie = make_pair(maladies[i].getNom, risque);
		patient.ajouterRisqueMaladie(risqueUneMaladie);
	}
	return patient;
}

vector<double> Analyse::risqueNumerique(Attribut* attPatient, vector<Attribut*> attMaladie)
{
	vector<double> proba;
	vector<double> delta;
	double min = -100000.0;
	double max = 100000.0;
	for (unsigned int i = 0; i < attMaladie.size(); i++)
	{
		if ((double)attMaladie[i]->getValue() < min)
		{
			min = attMaladie[i]->getValue();
		}
		if ((double)attMaladie[i]->getValue() > max)
		{
			max = attMaladie[i]->getValue();
		}
		delta.push_back(max - min);
	}

	for (unsigned int i = 0; i < attMaladie.size(); i++)

	{
		double deltaUnitaire = abs(attMaladie[i]->getValue() - attPatient->getValue());
		if ((delta[i] == 0.0) || (deltaUnitaire>delta[i]))
		{
			proba.push_back(1.0);
		}
		else {
			proba.push_back(abs(deltaUnitaire/ delta[i]));
		}
	}

	return (proba);
}

vector<double> Analyse::risqueCategorique(Attribut* attPatient, vector<Attribut*> attMaladie)
{
	vector<double> proba;
	for (unsigned int i = 0; i < attMaladie.size(); i++)
	{
		if ((string)attMaladie[i]->getValue() == attPatient->getValue()) {
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

