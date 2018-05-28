#if ! defined (AttributCarac_H)
#define AttributCarac_H
#include "Attribut.h"

class AttributCarac : public Attribut {

public:

	AttributCarac();
	AttributCarac(string valInput, string name);
	void* getValue();
	~AttributCarac();

protected:
	string valeur;
};

#endif
