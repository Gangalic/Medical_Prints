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
using namespace std;
class Lecture
{
public:
	Lecture(string fichierMeta, string fichierMal, string fichierPat);
    Maladie LireUneMaladie(string ligne );
    Signature LireUneSignature(string ligne);
    vector<Patient> LirePatients();
    vector<Maladie>  LireMaladies();
	~Lecture();

protected:
	string nomFichierMeta;
	string nomFichierMal;
	string nomFichierPat;
	vector <string> metadonnees;
};

#endif
