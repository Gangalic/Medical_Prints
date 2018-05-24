using namespace std;
#include <string>
#include <iostream>
#include "Maladie.h"
#include "Signature.h"


Maladie::Maladie(string leNom, Signature laSignature)
{
}

// shows only the name + maybe add Signature details later
void Maladie::AffichageMaladie() {
	cout << nomMaladie <<"\n";
}

Maladie::~Maladie()
{
}