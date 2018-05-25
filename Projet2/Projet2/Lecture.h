#if ! defined (Lecture_H)
#define Lecture_H
#include "Maladie.h"
#include "Signature.h"
#include "Attribut.h"
#include "AttributID.h"
#include "AttributCarac.h"
#include "AttributNum.h"
#include "Patient.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
class Lecture
{
public:
	Lecture(string fichierMeta, string fichierMal, string fichierPat);
    Maladie LireUneMaladie(string ligne );
    Signature LireUneSignature(string ligne);
    void LireSignatures(vector<Signature> &tabSignature);
	void LireMaladies(vector<Maladie> &tabMaladie);
	~Lecture();

protected:
	string nomFichierMeta;
	string nomFichierMal;
	string nomFichierPat;
	vector <string> metadonnees;
};

#endif
