using namespace std;
#include <string>
#include <iostream>
#include "Maladie.h"
#include "Signature.h"


Maladie::Maladie(string leNom, Signature laSignature)
{
	nomMaladie = leNom;
	uneSignature = laSignature;
}

// shows only the name
// possible to add signature details later, if needed
void Maladie::AffichageMaladie() {
	cout <<"- "<< nomMaladie <<"\n";
}

string Maladie::getNom() {
	return nomMaladie;
}

Signature Maladie::getSignature() {
	return uneSignature;
}

// to have controlled memory freeing
void Maladie::destroySignature() {
	uneSignature.destroyS();
}

Maladie::~Maladie()
{
}
