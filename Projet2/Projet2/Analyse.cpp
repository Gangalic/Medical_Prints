using namespace std;
#include "Analyse.h"
#include "string"
#include "Maladie.h"
#include <map>
#include "Patient.h"
#include <utility>


Analyse::Analyse()
{
}




vector<double> risqueNumerique(Attribut* attPatient, vector<Attribut*> attMaladie)
{
	vector<double> proba;
	double min = -100000.0;
	double max = 100000.0;
	for (unsigned int i = 0; i < attMaladie.size(); i++) 
	{
		if (attMaladie[i]->getValue() < min)
		{
			min = attMaladie[i]->getValue();
		}
		if (attMaladie[i]->getValue() > max)
		{
			max = attMaladie[i]->getValue();
		}

	}
	double delta = max - min;
	for (unsigned int i = 0; i < attMaladie.size(); i++)
	{
		proba.push_back(attMaladie[i]->getValue() / attPatient->getValue() /delta);
	}
	
	return (proba);
}

vector<double> risqueCategorique(Attribut* attPatient, vector<Attribut*> attMaladie)
{
	vector<double> proba;
	for (unsigned int i = 0; i < attMaladie.size(); i++)
	{
		if (attMaladie[i]->getValue() == attPatient->getValue()) {
			proba.push_back(1.0);
		}
		else {
			proba.push_back(0.0);
		}
	}
	return (proba);
}

Analyse::~Analyse()
{
}
