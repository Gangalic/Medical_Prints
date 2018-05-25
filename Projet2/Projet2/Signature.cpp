using namespace std;
#include <string>
#include <vector>
#include "Signature.h"


void Signature::AjouterAttribut(Attribut * nouvAttribut) {
	tabAttributs.push_back(nouvAttribut);
}

Signature::Signature()
{
}

// maybe to add to search it by type not just assume it's the first one
int Signature::getIdSignature() {
	return (int)tabAttributs[0]->getValue();
}

vector <Attribut *> Signature::getTabAttributs() {
	return tabAttributs;
}

Signature::~Signature()
{
	// we don't give a **** about memory
	/*vector<Attribut*>::iterator vIter;
	for (vIter = tabAttributs.begin(); vIter != tabAttributs.end(); vIter++) {
		delete * vIter;
	}*/
	tabAttributs.clear();
}
