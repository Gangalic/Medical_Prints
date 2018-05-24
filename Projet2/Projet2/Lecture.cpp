using namespace std;
#include <string>
#include "Lecture.h"

Lecture::Lecture(string fichierMeta, string fichierMal, string fichierPat) {
#ifdef MAP
	cout << "Appel au constructeur de <Lecture>" << endl;
#endif
	nomFichierMeta = fichierMeta;
	nomFichierMal = fichierMal;
	nomFichierPat = fichierPat;
	//some bla bla
}

Lecture::~Lecture() {
#ifdef MAP
	cout << "Appel au destructeur de <Lecture>" << endl;
#endif
}
