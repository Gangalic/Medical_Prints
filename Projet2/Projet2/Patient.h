#if ! defined (Patient_H)
#define Patient_H
#include "Signature.h"
#include <string>
#include <map>

class Patient
{
public:
	Patient(Signature laSignature);
	void AffichagePatient();
	Signature getSignature();
	~Patient();

private:
	Signature uneSignature;
};

#endif