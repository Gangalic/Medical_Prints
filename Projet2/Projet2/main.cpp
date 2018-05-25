using namespace std;
#include <iostream>
#include <string>
#include <map>
#include "Maladie.h"
#include "Patient.h"
#include "Lecture.h"
#include "Analyse.h"


void AffichageMaladiePatient(string nomFichierPatient) {

}


int main()
{
	string nomFichierMeta = "";
	string nomFichierMaladie="";
	string nomFichierPatient = "";
	cout << "Bonjour, j'espère que vous passer une bonne journée." << endl;
	cout << "Quelle est le nom du fichier de métadonnée que vous voulez analyser ? " << endl;
	while (!nomFichierMeta.find(".csv"))
	{
		cin >> nomFichierMeta;
		if (nomFichierMeta.find(".csv")) {
			cerr << "Nom du fichier incorrecte veuillez réessayer " << endl;
		}
	}

	cout << "Quelle est le nom du fichier Maladie que vous voulez analyser ? " << endl;
	while (!nomFichierMaladie.find(".csv"))
	{
	cin >> nomFichierMaladie;
		if (nomFichierMaladie.find(".csv")) {
			cerr << "Nom du fichier incorrecte veuillez réessayer " << endl;
		}
	}
	cout << "Quelle est le nom du fichier Patient que vous voulez analyser ? " << endl;
	while (!nomFichierPatient.find(".csv"))
	{
		cin >> nomFichierPatient;
		if (nomFichierPatient.find(".csv")) {
			cerr << "Nom du fichier incorrecte veuillez réessayer " << endl;
		}
	}
	Lecture lect = Lecture(nomFichierMeta, nomFichierMaladie, nomFichierPatient);

	string choix = "";
	while ((choix != "1") || (choix != "2")) {
		cout << "Que voulez-vous faire ?" << endl;
		cout << "Tapez le numéro corresondant à votre demmande." << endl;
		cout << "1. Afficher toutes les maladies" << endl;
		cout << "2. Afficher les patients avec leur risque d'être atteint par chaque maladie" << endl;
		cin >> choix;
		if (choix != "1" || choix != "2") {
			cerr << "Choix invalide, veuillez réessayer" << endl;
		}
	}
	vector <Maladie> tabMaladie = lect.LireMaladie();
	vector <Patient> tabPatient = lect.LirePatient();
	vector <Patient> tabPatientFinal;
	Analyse analyse = Analyse();

	for (int i = 0; i < tabPatient.size(); i++) {
		tabPatientFinal[i] = analyse.FaireAnalyse(tabPatient[i], tabMaladie);
	}

	if (choix==1)
		for (int j = 0; j < tabMaladie.size(); j++) {
			
		}
		break;
	case "2":
		
		break;
	default:
		break;
	}

	
		
	
		
		
	return 0;
	
}


