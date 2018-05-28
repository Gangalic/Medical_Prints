/*************************************************************************
                           main  -  description
                             -------------------
    début                : 28/05/2018
    copyright            : (C) 2018 par B3350 & B33
    e-mail               : 3if@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <main> (fichier main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
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
	
	string nomFichierMeta;
	string nomFichierMaladie;
	string nomFichierPatient;
	/*cout << "Bonjour, j'espere que vous passer une bonne journee." << endl;
	cout << "Quelle est le nom du fichier de metadonnee que vous voulez analyser ? " << endl;
	cin >> nomFichierMeta;
	cout << "Vous avez choisi le fichier : " << nomFichierMeta << endl;

	cout << "Quelle est le nom du fichier Maladie que vous voulez analyser ? " << endl;
	cin >> nomFichierMaladie;
	cout << "Vous avez choisi le fichier : " << nomFichierMaladie << endl;

	cout << "Quelle est le nom du fichier Patient que vous voulez analyser ? " << endl;

	cin >> nomFichierPatient;
	cout << "Vous avez choisi le fichier : " << nomFichierPatient << endl;*/
	
	nomFichierMeta = "C:\\GL\\meta.txt";
	nomFichierMaladie = "C:\\GL\\mal.txt";
	nomFichierPatient = "C:\\GL\\p.txt";
	cout << "Vous avez choisi le fichier meta : " << nomFichierMeta << endl;
	cout << "Vous avez choisi le fichier Maladie : " << nomFichierMaladie << endl;
	cout << "Vous avez choisi le fichier Patient : " << nomFichierPatient << endl;


	Lecture lect = Lecture(nomFichierMeta, nomFichierMaladie, nomFichierPatient);

	string choix = "0";
	vector <Maladie> tabMaladie = lect.LireMaladies();
	vector <Patient> tabPatient = lect.LirePatients();
	vector <Patient> tabPatientFinal;
	Analyse analyse = Analyse();
	bool close = false;
	for (int i = 0; i < tabPatient.size(); i++) {
		Patient unPatient = tabPatient[i];
		tabPatientFinal.push_back(analyse.FaireAnalyse(tabPatient[i], tabMaladie));
	}

	while (!close) {
		while ((choix != "1") && (choix != "2") && (choix != "3")) {
			cout << "\n Que voulez-vous faire ?\n";
			cout << "Tapez le numero corresondant à votre demmande." << endl;
			cout << "1. Afficher toutes les maladies" << endl;
			cout << "2. Afficher les patients avec leur risque d'etre atteint par chaque maladie" << endl;
			cout << "3. Quitter" << endl;
			cin >> choix;
			if (choix != "1" && choix != "2" && choix != "3") {
				cout << "\n Choix invalide, veuillez reessayer" << endl;
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
		choix = "";
	}
	cout << "Bonne journée à vous et a bientôt ;)" << endl;


	return 0;

}


