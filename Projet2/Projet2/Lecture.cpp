
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


	ifstream fichier(nomFichierMeta, ios::in);  // on ouvre en lecture
	string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
	getline(fichier, contenu);
	while (getline(fichier, contenu))
	{
		metadonnees.push_back(contenu);
	}

	fichier.close();

}


vector<Maladie> Lecture::LireMaladies()
{
	string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
	ifstream fi;

	fi.open(nomFichierMal);
	getline(fi, contenu);

	vector<Maladie> tabMaladies;
	while (contenu != "")
	{

		getline(fi, contenu);
		if (contenu != "")
		{
			tabMaladies.push_back(LireUneMaladie(contenu));
		}

	}
	return tabMaladies;
}

vector<Patient> Lecture::LirePatients()
{
	string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
	ifstream fi;
	fi.open(nomFichierPat);
	getline(fi, contenu);
	vector<Patient> tabPatients;
	while (contenu != "")
	{

		getline(fi, contenu);
		if (contenu != "")
		{
			tabPatients.push_back(Patient(LireUneSignature(contenu)));
		}

	}
	return tabPatients;
}

Signature Lecture::LireUneSignature(string line)
{
	Signature laSignature;
	stringstream ss;
	ss.str(line);
	string info;
	Attribut * attr;
	int i = 0;
	while (getline(ss, info, ';'))
	{
		if (metadonnees[i].substr(metadonnees[i].find(';') + 1, metadonnees[i].length()) == "ID")
		{
			attr = new AttributID(info, metadonnees[i].substr(0, metadonnees[i].find(';')));
		}
		else if (metadonnees[i].substr(metadonnees[i].find(';') + 1, metadonnees[i].length()) == "double")
		{

			attr = new AttributNum(info, metadonnees[i].substr(0, metadonnees[i].find(';')));
		}
		else if (metadonnees[i].substr(metadonnees[i].find(';') + 1, metadonnees[i].length()) == "string")
		{
			attr = new AttributCarac(info, metadonnees[i].substr(0, metadonnees[i].find(';')));
		}
		else
		{
			attr = NULL;
		}

		laSignature.AjouterAttribut(attr);

		i++;
	}


	return laSignature;

}

Maladie Lecture::LireUneMaladie(string line)
{
	cout << line.find_last_of(';') << endl;
	cout << line.substr(0, line.find_last_of(';') - 1) << endl;
	string laS = line.substr(0, line.find_last_of(';') - 1);
	Signature laSignature = LireUneSignature(laS);
	string nom = line.substr(line.find_last_of(';') + 1, line.length());

	Maladie laMaladie = Maladie(nom, laSignature);
	return laMaladie;
}


Lecture::~Lecture() {
#ifdef MAP
	cout << "Appel au destructeur de <Lecture>" << endl;
#endif
}
