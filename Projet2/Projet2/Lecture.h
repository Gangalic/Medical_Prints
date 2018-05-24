#if ! defined (Lecture_H)
#define Lecture_H

class Lecture
{
public:
	Lecture(string fichierMeta, string fichierMal, string fichierPat);
	Maladie LireUneMaladie(ligne string);
	Signature LireUnPatient(ligne string);
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