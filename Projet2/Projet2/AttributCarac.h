#if ! defined (AttributCarac_H)
#define AttributCarac_H
#include "Attribut.h"

/**
 * @brief The AttributCarac class: Attribut de type Caractère
 */
class AttributCarac : public Attribut {

public:

    /**
     * @brief AttributCarac: Constructeur par défaut
     */
	AttributCarac();
    
    /**
     * @brief AttributCarac: Constructeur avec paramètres
     * @param valInput : La valeur de l'attribut
     * @param name: Le nom de l'attribut
     */
	AttributCarac(string valInput, string name);
    
    /**
     * @brief getValue
     * @return un pointeur de la valueur de l'attribut
     */
	virtual void* getValue(); 
    
    /**
     * @brief ~AttributCarac: Destructeur de la classe
     */
	~AttributCarac();

protected:
    
    /**
     * @brief valeur: La valeur de l'attribut
     */
	string valeur;
};

#endif

