using namespace std;
#include <iostream>
#include <string>
#include <map>
#include "Maladie.h"
#include "Patient.h"
#include "Lecture.h"
#include "Analyse.h"



int main()
{
	/*
	string nomFichierMeta = "";
	string nomFichierMaladie="";
	string nomFichierPatient = "";
	cout << "Bonjour, j'espère que vous passer une bonne journée." << endl;
	cout << "Quelle est le nom du fichier de métadonnée que vous voulez analyser ? " << endl;
	while (!nomFichierMeta.find(".csv"))
	{
		cin >> nomFichierMeta;
		if (nomFichierMeta.find(".csv")) {
			cout << "Nom du fichier incorrecte veuillez reessayer " << endl;
		}
	}

	cout << "Quelle est le nom du fichier Maladie que vous voulez analyser ? " << endl;
	while (!nomFichierMaladie.find(".csv"))
	{
	cin >> nomFichierMaladie;
		if (nomFichierMaladie.find(".csv")) {
			cout << "Nom du fichier incorrecte veuillez réessayer " << endl;
		}
	}
	cout << "Quelle est le nom du fichier Patient que vous voulez analyser ? " << endl;
	while (!nomFichierPatient.find(".csv"))
	{
		cin >> nomFichierPatient;
		if (nomFichierPatient.find(".csv")) {
			cout << "Nom du fichier incorrecte veuillez réessayer " << endl;
		}
	}
	Lecture lect = Lecture(nomFichierMeta, nomFichierMaladie, nomFichierPatient);

	string choix = "";
	vector <Maladie> tabMaladie = lect.LireMaladie();
	vector <Patient> tabPatient = lect.LirePatient();
	vector <Patient> tabPatientFinal;
	Analyse analyse = Analyse();
	bool close = false;
	for (int i = 0; i < tabPatient.size(); i++) {
		tabPatientFinal[i] = analyse.FaireAnalyse(tabPatient[i], tabMaladie);
	}

	while (!close) {
		while ((choix != "1") || (choix != "2") || (choix != "3")) {
			cout << "Que voulez-vous faire ?" << endl;
			cout << "Tapez le numéro corresondant à votre demmande." << endl;
			cout << "1. Afficher toutes les maladies" << endl;
			cout << "2. Afficher les patients avec leur risque d'etre atteint par chaque maladie" << endl;
			cout << "3. Quitter" << endl;
			cin >> choix;
			if (choix != "1" || choix != "2" || choix != "3") {
				cout << "Choix invalide, veuillez reessayer" << endl;
			}
		}

		if (choix == "1") {
			for (int j = 0; j < tabMaladie.size(); j++) {
				tabMaladie[j].AffichageMaladie();
			}
		}
		if (choix == "2") {
			for (int j = 0; j < tabPatientFinal.size(); j++) {
				tabPatientFinal[j].AffichagePatient();
			}
		}
		if (choix == "3") {
			close = true;
		}
	}
	cout << "Bonne journée à vous et a bientôt ;)" << endl;


	
		
	
		
		
	return 0;
	
	vector <Signature> tabS;
	Lecture l("/home/alan/Bureau/fichierTPGL/meta.txt", "/home/alan/Bureau/fichierTPGL/mal.txt", "/home/alan/Bureau/fichierTPGL/p.txt");
	l.LireSignatures(tabS);*/
	return 0;

}


