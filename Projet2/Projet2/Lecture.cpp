using namespace std;
#include <string>
#include "Lecture.h"
//Commentaire
Lecture::Lecture(string fichierMeta, string fichierMal, string fichierPat) {
#ifdef MAP
	cout << "Appel au constructeur de <Lecture>" << endl;
#endif
	nomFichierMeta = fichierMeta;
	nomFichierMal = fichierMal;
	nomFichierPat = fichierPat;
<<<<<<< HEAD
	string s;
=======
	//some bla bla
>>>>>>> dabcdcf547f9dfb24f4cae8cbb6626b72dab0241
}

Lecture::~Lecture() {
#ifdef MAP
	cout << "Appel au destructeur de <Lecture>" << endl;
#endif
}
