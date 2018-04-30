#if ! defined (Signature_H)
#define Signature_H
#include "Attribut.h"

class Signature
{
public:
	void AjouterAttribut(Attribut * nouvAttribut);
	Signature();
	~Signature();
protected:
	vector <Attribut *> tabAttributs;
};

#endif