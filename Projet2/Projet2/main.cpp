using namespace std;
#include <iostream>
#include <string>
#include <map>
#include <set>


#include "Maladie.h"
#include "Patient.h"
#include "Lecture.h"
#include "Analyse.h"



int main()
{
	
	string nomFichierMeta;
	string nomFichierMaladie;
	string nomFichierPatient;
	
	cout << "Bonjour, j'espere que vous passer une bonne journee." << endl;
	cout << "\nQuelle est le nom du fichier de metadonnee que vous voulez analyser ? " << endl;
	cin >> nomFichierMeta;
	cout << "Vous avez choisi le fichier : " << nomFichierMeta << endl;

	cout << "\nQuelle est le nom du fichier Maladie que vous voulez analyser ? " << endl;
	cin >> nomFichierMaladie;
	cout << "Vous avez choisi le fichier : " << nomFichierMaladie << endl;

	cout << "\nQuelle est le nom du fichier Patient que vous voulez analyser ? " << endl;
	cin >> nomFichierPatient;
	cout << "Vous avez choisi le fichier : " << nomFichierPatient << "\n"<< endl;


	Lecture lect = Lecture(nomFichierMeta, nomFichierMaladie, nomFichierPatient);
	if (!lect.getLectureReussie()) { // if can't find the metadata file, exits
		system("pause");
		return 0;
	}

	cout << "\nAttendez\nOn prepare tous pour vous...\n\n";

	string choix = "0";
	vector <Maladie> tabMaladie = lect.LireMaladies();
	vector <Patient> tabPatient = lect.LirePatients();
	vector <Patient> tabPatientFinal;
	set <string> maladiesDistinctes;
	Analyse analyse = Analyse();
	bool close = false;

	if (!lect.getLectureReussie()) { // if can't find illness or patient files, exits
		system("pause");
		return 0;
	}

	for (int j = 0; j < tabMaladie.size(); j++) { // search distinct illnesses
		Maladie uneMaladie = tabMaladie[j];
		string nomMaladie = uneMaladie.getNom();
		maladiesDistinctes.insert(nomMaladie);
	}
	
	for (int i = 0; i < tabPatient.size(); i++) {
		Patient unPatient = tabPatient[i];
		unPatient = analyse.FaireAnalyse(unPatient, tabMaladie);
		tabPatientFinal.push_back(unPatient);
	}

	while (!close) {
		while ((choix != "1") && (choix != "2") && (choix != "3") && (choix != "4")) {
			cout << "\n Que voulez-vous faire ?\n";
			cout << "Tapez le numero corresondant a votre demmande." << endl;
			cout << "1. Afficher toutes les maladies" << endl;
			cout << "2. Afficher les patients avec leur risque d'etre malade (version courte)" << endl;
			cout << "3. Afficher les patients avec leur risque d'etre malade (version longue)" << endl;
			cout << "4. Quitter" << endl;
			cin >> choix;
			if (choix != "1" && choix != "2" && choix != "3" && choix != "4") {
				cout << "\n Choix invalide, veuillez reessayer" << endl;
			}
		}
		if (choix == "1") {
			cout << "\nNous avons les maladies suivants:\n";
			std::set<string>::iterator it;
			for (it = maladiesDistinctes.begin(); it != maladiesDistinctes.end(); ++it) {
				cout <<"- "<< *it <<"\n";
			}
		}
		else if (choix == "2") {
			for (int j = 0; j < tabPatientFinal.size(); j++) {
				Patient unPatient = tabPatientFinal[j];
				unPatient.AffichagePatient(true);
			}
		}
		else if (choix == "3") {
			for (int j = 0; j < tabPatientFinal.size(); j++) {
				Patient unPatient = tabPatientFinal[j];
				unPatient.AffichagePatient(false);
			}
		}
		else if (choix == "4") {
			close = true;
		}
		choix = "";
	}
	cout << "\nBonne journee a vous et a bientot ;)" << endl;
	system("pause"); //to let the user read the goodbye message

	for (int i = 0; i < tabMaladie.size(); i++) { // get rid of memory leaks
		Maladie uneMaladie = tabMaladie[i];
		uneMaladie.destroySignature();
	}

	for (int i = 0; i < tabPatient.size(); i++) { // get rid of memory leaks
		Patient unPatient = tabPatient[i];
		unPatient.destroySignature();
	}

	return 0;

}


