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

// shows only the name + maybe add Signature details later
void Maladie::AffichageMaladie() {
	cout <<"- "<< nomMaladie <<"\n";
}

string Maladie::getNom() {
	return nomMaladie;
}

Signature Maladie::getSignature() {
	return uneSignature;
}

void Maladie::destroySignature() {
	uneSignature.destroyS();
}

Maladie::~Maladie()
{
}