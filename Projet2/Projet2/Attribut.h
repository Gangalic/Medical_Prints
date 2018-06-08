#if ! defined (Attribut_H)
#define Attribut_H
#include <string>
using namespace std;

/**
 * @brief The Attribut class: Classe virtuelle d'attribut
 */
class Attribut
{
public:
    
    /**
     * @brief Attribut: Constructeur par défaut
     */
	Attribut();
    
    /**
     * @brief getValue
     * @return un pointeur de la valueur de l'attribut
     */
	virtual void* getValue();
    
    /**
     * @brief ~Attribut: Destructeur de la classe
     */
	~Attribut();

protected:
    
    /**
     * @brief nom Le nom de l'attribut
     */
	string nom;
};

#endif
