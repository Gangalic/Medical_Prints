#if ! defined (Signature_H)
#define Signature_H
#include "Attribut.h"
#include <vector>

class Signature
{
public:
	void AjouterAttribut(Attribut * nouvAttribut);
	auto getIdSignature();
	Signature();
	~Signature();
protected:
	vector <Attribut *> tabAttributs;
};

#endif