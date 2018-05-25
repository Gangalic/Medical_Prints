using namespace std;
#include <string>
#include "AttributCarac.h"

AttributCarac::AttributCarac() {
#ifdef MAP
	cout << "Appel au constructeur par defaut de <AttributCarac>" << endl;
#endif
}

AttributCarac::AttributCarac(string valInput, string name) {
#ifdef MAP
	cout << "Appel au constructeur de <AttributCarac>" << endl;
#endif
	valeur = valInput;
	nom = name;
}

auto AttributCarac::getValue() {
	return valeur;
}

AttributCarac::~AttributCarac() {
#ifdef MAP
	cout << "Appel au destructeur de <AttributCarac>" << endl;
#endif
}