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
<<<<<<< HEAD
    Signature LireUneSignature(string ligne);
    vector<Patient> LirePatients();
    vector<Maladie>  LireMaladies();
=======
    Patient LireUnPatient(string ligne);
	void LirePatients(vector<Patient> &tabPatient);
	void LireMaladies(vector<Maladie> &tabMaladie);
>>>>>>> 12abb18be23baf3314bda12d7462be150940dee0
	~Lecture();

protected:
	string nomFichierMeta;
	string nomFichierMal;
	string nomFichierPat;
	vector <string> metadonnees;
};

#endif
