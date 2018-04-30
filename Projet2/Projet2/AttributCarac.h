#if ! defined (AttributCarac_H)
#define AttributCarac_H
#include "Attribut.h"

class AttributCarac : public Attribut {

public:

	AttributCarac(string valInput, string name);

	~AttributCarac();

protected:
	string valeur;
};

#endif
