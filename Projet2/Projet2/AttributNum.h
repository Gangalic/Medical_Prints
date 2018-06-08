#if ! defined (AttributNum_H)
#define AttributNum_H
#include "Attribut.h"

/**
 * @brief The AttributNum class: Attribut de type numérique
 */
class AttributNum : public Attribut {

public:

    /**
     * @brief AttributNum: Constructeur par défaut de la classe
     */
	AttributNum();
    
    /**
     * @brief AttributNum: Constructeur avec paramètres
     * @param valInput: La valeur de l'attribut
     * @param name: Le nom de l'attribut.
     */
	AttributNum(string valInput, string name);
    
    /**
     * @brief getValue
     * @return un pointeur de la valueur de l'attribut
     */
	virtual void* getValue(); //random
    
    /**
     * @brief ~AttributNum: Destructeur de la classe
     */
	~AttributNum();

protected:
    
    /**
     * @brief valeur: La valeur de l'attribut
     */
	double valeur;
};

#endif
