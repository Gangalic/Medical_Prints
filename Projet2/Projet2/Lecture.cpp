using namespace std;
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
    while(getline(fichier, contenu))
	{
			metadonnees.push_back(contenu);
	}
	fichier.close();
                
}


vector<Maladie> Lecture::LireMaladies()
{
<<<<<<< HEAD
    string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
    ifstream fi;

    fi.open(nomFichierMal);
    getline(fi, contenu);

    vector<Maladie> tabMaladies;
    while(contenu != "")
    {

        getline(fi, contenu);
        if(contenu != "")
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
    while(contenu != "")
    {

        getline(fi, contenu);
        if(contenu != "")
        {
            tabPatients.push_back(Patient(LireUneSignature(contenu)));
        }

    }
     return tabPatients;
=======
	ifstream fichier(nomFichierMal, ios::in);  // on ouvre en lecture
	string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
	getline(fichier, contenu);
    while(getline(fichier, contenu))
	{
			tabMaladie.push_back(LireUneMaladie(contenu));
	}
	fichier.close();
}

void Lecture::LirePatients(vector<Patient> &tabPatient)
{
	ifstream fichier(nomFichierPat, ios::in);  // on ouvre en lecture
	string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
	getline(fichier, contenu);
    while(getline(fichier, contenu))
	{
            tabPatient.push_back(LireUnPatient(contenu));
	}
	fichier.close();
>>>>>>> 12abb18be23baf3314bda12d7462be150940dee0
}

Patient Lecture::LireUnPatient(string line)
{
	Signature laSignature;
	int pos = 0;
	int next_pos = line.find(';');
	Attribut * attr;
	int i = 0;
	while(pos != line.length())
	{
        if(metadonnees[i].substr(1,';') == "ID")
		{
            attr = new AttributID(line.substr(pos,next_pos),metadonnees[i].substr(1,';'));
		}
        else if((metadonnees[0].substr(1,';') == "double"))
		{
            attr = new AttributNum(line.substr(pos,next_pos),metadonnees[i].substr(1,';'));
		}
        else if((metadonnees[0].substr(1,';') == "string"))
		{
            attr = new AttributCarac(line.substr(pos,next_pos),metadonnees[i].substr(1,';'));
		}
		else
        {
            attr = NULL;
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
<<<<<<< HEAD

=======
>>>>>>> 12abb18be23baf3314bda12d7462be150940dee0
	
	return laSignature;

}

Maladie Lecture::LireUneMaladie(string line)
{
<<<<<<< HEAD
    cout <<line.find_last_of(';')<<endl;
    cout << line.substr(0,line.find_last_of(';')-1)<<endl;
    string laS = line.substr(0,line.find_last_of(';')-1);
    Signature laSignature = LireUneSignature(laS);
=======
    Patient laSignature = LireUnPatient(line.substr(0,line.find_last_of(';')-1));
>>>>>>> 12abb18be23baf3314bda12d7462be150940dee0
	string nom = line.substr(line.find_last_of(';')+1, line.length());

	Maladie laMaladie = Maladie(nom, laSignature);
	return laMaladie;
}


Lecture::~Lecture() {
#ifdef MAP
	cout << "Appel au destructeur de <Lecture>" << endl;
#endif
}
