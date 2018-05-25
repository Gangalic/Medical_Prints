using namespace std;
#include <map>
#include <string>
#include "Patient.h"
#include "Analyse.h"
#include "Maladie.h"


Analyse::Analyse()
{
}

//sending back a patient
Patient FaireAnalyse(Patient unPatient, vector<Maladie> maladies)
{
	Patient patient = Patient(unPatient.getSignature());
	vector<vector<double>> tabTousAttributs;
	for (int i = 0; i < maladies[0].getSignature().getTabAttributs().size(); i++) {
		vector<Attribut *> unAttributChaqueMaladie;
		//for (int j=0; )
	}
}

vector<double> risqueNumerique(Attribut* attPatient, Attribut* attMaladie)
{
	
}

vector<double> risqueCategorique(Attribut* attPatient, Attribut* attMaladie)
{

}

Analyse::~Analyse()
{
}

