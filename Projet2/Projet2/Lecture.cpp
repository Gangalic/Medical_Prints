
using namespace std;
#include <sstream>
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
    while(getline(fichier, contenu))
	{
			metadonnees.push_back(contenu);
	}

	fichier.close();
                
}


void Lecture::LireMaladies(vector<Maladie> &tabMaladie)
{

	string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
    ifstream fi;
    fi.open(nomFichierMal);
    getline(fi, contenu);
    while(fi.good())
	{
        cout << contenu<<endl;
            getline(fi, contenu);
             cout << contenu<<endl;
			tabMaladie.push_back(LireUneMaladie(contenu));
	}
    fi.close();
}

void Lecture::LireSignatures(vector<Signature> &tabSignature)
{
    string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
    ifstream fi;
    fi.open(nomFichierPat);
    getline(fi, contenu);

    while(fi.good())
    {

        getline(fi, contenu);
        tabSignature.push_back(LireUneSignature(contenu));
        cout << "Apres"<<endl;
	}
    fi.close();
}

Signature Lecture::LireUneSignature(string line)
{
	Signature laSignature;
    stringstream ss;
    ss.str(line);
    string info;
	Attribut * attr;
	int i = 0;
    while(getline(ss, info,';'))
    {
        if(metadonnees[i].substr(metadonnees[i].find(';')+1,metadonnees[i].length()) == "ID")
        {
            attr = new AttributID(info,metadonnees[i].substr(0,metadonnees[i].find(';')));
		}
        else if(metadonnees[i].substr(metadonnees[i].find(';')+1,metadonnees[i].length()) == "double")
		{

            attr = new AttributNum(info,metadonnees[i].substr(0,metadonnees[i].find(';')));
		}
        else if(metadonnees[i].substr(metadonnees[i].find(';')+1,metadonnees[i].length()) == "string")
        {
            attr = new AttributCarac(info,metadonnees[i].substr(0,metadonnees[i].find(';')));
		}
		else
		{
            attr = NULL;
		}

        laSignature.AjouterAttribut(attr);

		i++;
	}
    cout << "rendu signature"<<endl;
	
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
