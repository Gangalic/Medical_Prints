using namespace std;
#include "Analyse.h"
#include "string"
#include "Maladie.h"
#include <map>
#include "Patient.h"
#include <utility>
#include "math.h"


Analyse::Analyse()
{
}


Patient Analyse::FaireAnalyse(Patient unPatient, vector<Maladie> maladies)
{
	Patient patient = Patient(unPatient.getSignature());
	vector<vector<double>> tabTousAttributs;
	for (int i = 0; i < maladies[0].getSignature().getTabAttributs().size(); i++) {
		vector<Attribut *> unAttributChaqueMaladie;
		//for (int j=0; )
	}
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
		if (delta[i] == 0.0) 
		{ 
			proba.push_back(1.0); 
		}
		else {
			proba.push_back(abs(attMaladie[i]->getValue() - attPatient->getValue()) / delta[i]);
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
}
