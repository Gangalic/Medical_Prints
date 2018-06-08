#if ! defined (Lecture_H)
#define Lecture_H
#include "Maladie.h"
#include "Signature.h"
#include "Attribut.h"
#include "AttributID.h"
#include "AttributCarac.h"
#include "AttributNum.h"
#include "Patient.h"
#include <fstream>
#include <iostream>
using namespace std;

/**
 * @brief The Lecture class: Classe qui lit des fichiers et permet d'initialiser notre application
 */
class Lecture
{
public:
    
    /**
     * @brief Lecture: Constructeur avec paramètres
     * @param fichierMeta: Le nom du fichier des métadonnées
     * @param fichierMal: Le nom du fichier des maladies
     * @param fichierPat: Le nom du fichier des patients
     */
	Lecture(string fichierMeta, string fichierMal, string fichierPat);
    
    /**
     * @brief LireUneMaladie: Permet de créer une maladie à partir d'une ligne d'un fichier
     * @param ligne: La ligne à analyser
     * @return une maladie
     */
	Maladie LireUneMaladie(string ligne);
    
    /**
     * @brief LireUneSignature: Permet de créer une signature à partir d'une ligne d'un fichier
     * @param ligne: La ligne à analyser
     * @return une signature
     */
	Signature LireUneSignature(string ligne);
    
    /**
     * @brief LirePatients: Permet de créer l'ensemble des patients du fichier correspondant
     * @return L'ensemble des patients
     */
	vector<Patient> LirePatients();
    
    /**
     * @brief LireMaladies: Permet de créer l'ensemble des maladies du fichier correspondant
     * @return L'ensemble des maladies
     */
	vector<Maladie>  LireMaladies();
    
    /**
     * @brief getLectureReussie
     * @return true si la lecture c'est bien déroulée
     */
	bool getLectureReussie();
    
    /**
     * @brief ~Lecture: Desctructeur de la classe
     */
	~Lecture();

protected:
    
    /**
     * @brief nomFichierMeta: Le nom du fichier de métadonnées
     */
	string nomFichierMeta;
    
    /**
     * @brief nomFichierMal: Le nom du fichier de maladies
     */
	string nomFichierMal;
    
    /**
     * @brief nomFichierPat: Le nom du fichier de patient
     */
	string nomFichierPat;
    
    /**
     * @brief metadonnees: Vecteur de metadonnees
     */
	vector <string> metadonnees;
    
    /**
     * @brief lectureReussie
     */
	bool lectureReussie;
};

#endif
