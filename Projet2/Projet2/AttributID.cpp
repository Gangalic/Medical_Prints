using namespace std;
#include <string>
#include "AttributID.h"

AttributID::AttributID(string valInput, string name) {
#ifdef MAP
	cout << "Appel au constructeur de <AttributID>" << endl;
#endif
	valeur = stoi(valInput);
	nom = name;
}

auto AttributID::getValue() {
	return valeur;
}

AttributID::~AttributID() {
#ifdef MAP
	cout << "Appel au destructeur de <AttributID>" << endl;
#endif
}