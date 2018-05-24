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

	ifstream fichier(nomFichierMeta, ios::in);  // on ouvre en lecture
	string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
	getline(fichier, contenu);
	while(getline(fichier, contenu);)  
	{
			metadonnees.push_back(contenu);
	}
	fichier.close();
                
}


void Lecture::LireMaladies(vector<Maladie> &tabMaladie)
{
	ifstream fichier(nomFichierMal, ios::in);  // on ouvre en lecture
	string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
	getline(fichier, contenu);
	while(getline(fichier, contenu);)  
	{
			tabMaladie.push_back(LireUneMaladie(contenu));
	}
	fichier.close();
}

void Lecture::LireSignatures(vector<Signature> &tabSignature)
{
	ifstream fichier(nomFichierPat, ios::in);  // on ouvre en lecture
	string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
	getline(fichier, contenu);
	while(getline(fichier, contenu);)  
	{
			tabSignature.push_back(LireUneSignature(contenu));
	}
	fichier.close();
}

Signature Lecture::LireUneSignature(string line)
{
	Signature laSignature;
	int pos = 0;
	int next_pos = line.find(';');
	Attribut * attr;
	int i = 0;
	while(pos != line.length())
	{
		if(metadonnees.substr(1,';').equals("ID"))
		{
			attr = new AttributID(line.substr(pos,next_pos),metadonnees.substr(0,';').equals("ID"));
		}
		else if(metadonnees.substr(1,';').equals("double"))
		{
			attr = new AttributNum(line.substr(pos,next_pos),metadonnees.substr(0,';').equals("ID"));
		}
		else if(metadonnees.substr(1,';').equals("string"))
		{
			attr = new AttributCarac(line.substr(pos,next_pos),metadonnees[i].substr(0,';').equals("ID"));
		}
		else
		{
			attr = null;
		}
		laSignature.AjouterAttribut(attr);
		pos = next_pos+1;
		next_pos =  line.find(';');
		
		if(next_pos == std::string::npos)
		{
		}
			next_pos = line.length();
		i++;
	}
	
	return laSignature;
}

Maladie Lecture::LireUneMaladie(string line)
{
	Signature laSignature = LireUneSignature(line.substr(0,line.find_last_of(';')-1));
	string nom = line.substr(line.find_last_of(';')+1, line.length());
	Maladie laMaladie = Maladie(nom, laSignature);
	return laMaladie;
}


Lecture::~Lecture() {
#ifdef MAP
	cout << "Appel au destructeur de <Lecture>" << endl;
#endif
}
