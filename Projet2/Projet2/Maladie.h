#if ! defined (Maladie_H)
#define Maladie_H
#include "Signature.h"

class Maladie
{
public:

	Maladie(string leNom, Signature laSignature);
	void AffichageMaladie();
	~Maladie();

private:
	string nomMaladie;
};

#endif