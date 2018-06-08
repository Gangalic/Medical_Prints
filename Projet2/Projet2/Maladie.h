#if ! defined (Maladie_H)
#define Maladie_H
#include "Signature.h"

/**
 * @brief The Maladie class: Representation d'une maladie
 */
class Maladie
{
public:

    /**
     * @brief Maladie: Constructeur avec paramètres
     * @param leNom: Le nom de la maladie
     * @param laSignature: La signature de la maladie
     */
	Maladie(string leNom, Signature laSignature);
    
    /**
     * @brief AffichageMaladie: Affiche les caractéristiques de la maladie
     */
	void AffichageMaladie();
    
    /**
     * @brief getNom: Retourne le nom de la maladie
     * @return le nom
     */
	string getNom();
    
    /**
     * @brief getSignature: Retourne le signature de la maladie
     * @return la signature
     */
	Signature getSignature();
    
    /**
     * @brief destroySignature: Détruit la signature de la maladie
     */
	void destroySignature();
    
    /**
     * @brief ~Maladie: Destructeur de la classe
     */
	~Maladie();

private:
    
    /**
     * @brief nomMaladie: Le nom de la maladie
     */
	string nomMaladie;
    
    /**
     * @brief uneSignature: La signature de la maladie
     */
	Signature uneSignature;
};

#endif
