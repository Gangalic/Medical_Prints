using namespace std;
#include "Patient.h"
#include <iostream>

Patient::Patient(Signature laSignature)
{
}

void Patient::AffichagePatient() {
	cout << "\n";
	cout << "Patient avec id " << uneSignature.getIdSignature() <<" a les maladies suivants:\n";
	for (multimap<string, double>::iterator it = risqueMaladie.begin(); it != risqueMaladie.end(); ++it) {
		cout << (*it).first << " " << (*it).second <<"\n";
	}
}

Signature Patient::getSignature() {
	return uneSignature;
}

Patient::~Patient()
{
}
