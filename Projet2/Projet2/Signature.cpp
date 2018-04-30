//uselesss modif
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


Signature::~Signature()
{
	vector<Attribut*>::iterator vIter;
	for (vIter = tabAttributs.begin(); vIter != tabAttributs.end(); vIter++) {
		delete * vIter;
	}
	tabAttributs.clear();
}
