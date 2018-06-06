#if ! defined (Maladie_H)
#define Maladie_H
#include "Signature.h"

class Maladie
{
public:

	Maladie(string leNom, Signature laSignature);
	void AffichageMaladie();
	string getNom();
	Signature getSignature();
	void destroySignature();
	~Maladie();

private:
	string nomMaladie;
	Signature uneSignature;
};

#endif