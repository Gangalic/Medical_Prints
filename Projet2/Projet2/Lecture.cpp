
using namespace std;
#include <sstream>
#include <string>
#include "Lecture.h"


Lecture::Lecture(string fichierMeta, string fichierMal, string fichierPat) {
#ifdef MAP
	<< "Appel au constructeur de <Lecture>" << endl;
#endif
	nomFichierMeta = fichierMeta;
	nomFichierMal = fichierMal;
	nomFichierPat = fichierPat;
	lectureReussie = true;


	ifstream fichier(nomFichierMeta, ios::in);  // on ouvre en lecture
	if (fichier.fail()) {
		cout << "Fichier metadonnes introuvable\n";
		lectureReussie = false;
	}
	else {
		string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
		getline(fichier, contenu);
		while (getline(fichier, contenu))
		{
			metadonnees.push_back(contenu);
		}
	}

	fichier.close();

}


vector<Maladie> Lecture::LireMaladies()
{
	string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
	ifstream fi;
	vector<Maladie> tabMaladies;

	fi.open(nomFichierMal);

	if (fi.fail()) {
		cout << "Fichier maladies introuvable\n";
		lectureReussie = false;
	}
	else {
		getline(fi, contenu);

		while (contenu != "")
		{

			getline(fi, contenu);
			if (contenu != "")
			{
				Maladie uneMaladie = LireUneMaladie(contenu);
				tabMaladies.push_back(uneMaladie);
			}

		}
	}
	return tabMaladies;
}

vector<Patient> Lecture::LirePatients()
{
	string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
	ifstream fi;
	vector<Patient> tabPatients;

	fi.open(nomFichierPat);
	
	if (fi.fail()) {
		cout << "Fichier patients introuvable\n";
		lectureReussie = false;
	}
	else {
		getline(fi, contenu);
		while (contenu != "")
		{

			getline(fi, contenu);
			if (contenu != "")
			{
				Signature uneSignature = LireUneSignature(contenu);
				Patient unPatient = Patient(uneSignature);
				tabPatients.push_back(unPatient);
			}

		}
	}
	return tabPatients;
}

Signature Lecture::LireUneSignature(string line)
{
	Signature* pLaSignature = new Signature();
	stringstream ss;
	ss.str(line);
	string info;
	Attribut * attr;
	int i = 0;
	while (getline(ss, info, ';'))
	{	
		string uneMetadonnee = metadonnees[i];
		if (uneMetadonnee.substr(uneMetadonnee.find(';') + 1, uneMetadonnee.length()) == "ID")
		{
			attr = new AttributID(info, uneMetadonnee.substr(0, uneMetadonnee.find(';')));
		}
		else if (uneMetadonnee.substr(uneMetadonnee.find(';') + 1, uneMetadonnee.length()) == "double")
		{

			attr = new AttributNum(info, uneMetadonnee.substr(0, uneMetadonnee.find(';')));
		}
		else if (uneMetadonnee.substr(uneMetadonnee.find(';') + 1, uneMetadonnee.length()) == "string")
		{
			attr = new AttributCarac(info, uneMetadonnee.substr(0, uneMetadonnee.find(';')));
		}
		else
		{
			attr = NULL;
		}

		pLaSignature->AjouterAttribut(attr);


		i++;
	}


	return *pLaSignature;

}

Maladie Lecture::LireUneMaladie(string line)
{

	string laS = line.substr(0, line.find_last_of(';'));
	Signature laSignature = LireUneSignature(laS);
	string nom = line.substr(line.find_last_of(';') + 1, line.length());
	if (nom == "")
	{
		nom = "Inconnu";
	}
	Maladie laMaladie = Maladie(nom, laSignature);
	return laMaladie;
}

bool Lecture::getLectureReussie() {
	return lectureReussie;
}


Lecture::~Lecture() {
#ifdef MAP
	cout << "Appel au destructeur de <Lecture>" << endl;
#endif
}
