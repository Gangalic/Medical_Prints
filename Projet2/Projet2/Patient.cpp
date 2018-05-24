using namespace std;
#include "Patient.h"
#include <iostream>



Patient::Patient(Signature laSignature)
{
}

void Patient::AffichagePatient() {
	cout << "\n";
	cout << "Patient avec id " << uneSignature.getIdSignature() <<" a les maladies suivants:\n";
}

Signature Patient::getSignature() {
	return uneSignature;
}

Patient::~Patient()
{
}
