#if ! defined (Lecture_H)
#define Lecture_H
#include "Maladie.h"
#include "Signature.h"
#include "Attribut.h"
#include "Patient.h"
#include <fstream>
#include <iostream>
using namespace std;
class Lecture
{
public:
	Lecture(string fichierMeta, string fichierMal, string fichierPat);
    Maladie LireUneMaladie(string ligne );
    Patient LireUnPatient(string ligne);
	void LirePatients(vector<Patient> &tabPatient);
	void LireMaladies(vector<Maladie> &tabMaladie);
	~Lecture();

protected:
	string nomFichierMeta;
	string nomFichierMal;
	string nomFichierPat;
	vector <string> metadonnees;
};

#endif
