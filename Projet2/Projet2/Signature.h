#if ! defined (Signature_H)
#define Signature_H
#include "Attribut.h"
#include <vector>

/**
 * @brief The Signature class: Representation d'une signature
 */
class Signature
{
public:
    
    /**
     * @brief AjouterAttribut: Ajout d'un attribut
     * @param nouvAttribut: L'attribut à ajouter
     */
	void AjouterAttribut(Attribut * nouvAttribut);
    
    /**
     * @brief getIdSignature
     * @return reourne l'Id de la signature
     */
	int getIdSignature();
    
    /**
     * @brief getTabAttributs
     * @return  Retourne l'ensemble des attributs
     */
	vector <Attribut *> getTabAttributs();
    
    /**
     * @brief destroyS: Detruit l'ensemble des attributs
     */
	void destroyS();

    /**
     * @brief Signature: Construteur par défault
     */
	Signature();
    
    /**
     * @brief ~Signature: Destructeur de la classe
     */
	~Signature();
    
protected:
    
    /**
     * @brief tabAttributs: L'ensemble des attributs de la classe
     */
	vector <Attribut *> tabAttributs;
};

#endif
