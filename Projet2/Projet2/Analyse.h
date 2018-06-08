#if ! defined (Analyse_H)
#define Analyse_H
#include <vector>
#include "Maladie.h"
#include "Patient.h"
#include "AttributCarac.h"
#include "AttributNum.h"

/**
 * @brief The Analyse class: permet l'analyse du risque d'obtention de maladies
 */
class Analyse
{
public:
    
    /**
     * @brief Analyse: Constructeur de la classe
     */
	Analyse();
    
    /**
     * @brief FaireAnalyse: Fait l'analyse du risque d'obtention d'une ou plusieurs maladies pour un patient données
     * @param unPatient le patient qui risque d'avoir une maladie
     * @param maladies l'ensemble des maladies évaluées
     * @return un patient
     */
	Patient FaireAnalyse(Patient unPatient, vector<Maladie> maladies);
    
    /**
     * @brief risqueNumerique: Calcul le coefficient pour le risque de maladie pour un attribut de type numérique
     * @param attPatient L'attribut du patient évalué
     * @param attMaladie Les attributs de chaques maladies évalués
     * @return l'ensemble des coefficient
     */
	vector<double> risqueNumerique(Attribut* attPatient, vector<Attribut*> attMaladie);
    
    /**
     * @brief risqueCategorique: Calcul le coefficient pour le risque de maladie pour un attribut de type catégorique
     * @param attPatient L'attribut du patient évalué
     * @param attMaladie Les attributs de chaques maladies évalués
     * @return l'ensemble des coefficient
     */
	vector<double> risqueCategorique(Attribut* attPatient, vector<Attribut*> attMaladie);
    
    /**
     * @brief ~Analyse: Destructeur de la classe
     */
	~Analyse();

};

#endif
