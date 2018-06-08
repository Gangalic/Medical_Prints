#if ! defined (Patient_H)
#define Patient_H
#include "Signature.h"
#include <string>
#include <map>
#include <utility>

/**
 * @brief The Patient class: Representation d'un patient
 */
class Patient
{
public:
    
    /**
     * @brief Patient: Constructeur avec paramètres
     * @param laSignature: La signature du patient
     */
	Patient(Signature laSignature);
    
    /**
     * @brief AffichagePatient: Affiche les caractéristiques du patient
     * @param versionCourte si true, affiche une version du patient simplifiée.
     */
	void AffichagePatient(bool versionCourte);
    
    /**
     * @brief ajouterRisqueMaladie: Ajout d'un risque pour une maladie
     * @param risqueUneMaladie le risque à ajouter
     */
	void ajouterRisqueMaladie(pair<string, double> risqueUneMaladie);
    
    /**
     * @brief ajouterRisqueMaladieDistincte: Ajout d'un risque pour une maladie distincte
     * @param risqueUneMaladie le risque à ajouter
     */
	void ajouterRisqueMaladieDistincte(pair<string, double> risqueUneMaladie);
    
    /**
     * @brief getRisqueMaladies
     * @return le risques des maladies
     */
	multimap<string, double> getRisqueMaladies();
    
    /**
     * @brief getSignature
     * @return la signture du patient
     */
	Signature getSignature();
    
    /**
     * @brief destroySignature: Détruit la signature de la maladie
     */
	void destroySignature();
    
    /**
     * @brief ~Patient: Destructeur de la classe
     */
	~Patient();

private:
    
    /**
     * @brief calculerProbMaladiesDistinctes: Calcul la probabilité des maladies distinctes
     */
	void calculerProbMaladiesDistinctes();
    
    /**
     * @brief uneSignature: La signature du patient
     */
	Signature uneSignature;
    
    /**
     * @brief risqueMaladies: L'ensemble des risques pour chaques maladies
     */
	multimap<string, double> risqueMaladies;
    
    /**
     * @brief risqueMaladiesDistinctes: L'ensemble des risques pour chaques maladies distinctes
     */
	map<string, double> risqueMaladiesDistinctes;
};

#endif
