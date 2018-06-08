#if ! defined (AttributID_H)
#define AttributID_H
#include "Attribut.h"

/**
 * @brief The AttributID class: Attribut de type ID
 */
class AttributID : public Attribut {

public:

    /**
     * @brief AttributID: Constructeur avec paramètres
     * @param valInput: La valeur de l'attribut
     * @param name: Le nom de l'attribut
     */
	AttributID(string valInput, string name);
    
    /**
     * @brief getValue
     * @return un pointeur de la valueur de l'attribut
     */
	virtual void* getValue(); //random
    
    /**
     * @brief ~AttributID: Desructeur de la classe
     */
	~AttributID();

protected:
    
    /**
     * @brief valeur: La valeur de l'attribut
     */
	int valeur;
};

#endif
