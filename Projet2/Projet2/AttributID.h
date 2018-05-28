#if ! defined (AttributID_H)
#define AttributID_H
#include "Attribut.h"

class AttributID : public Attribut {

public:

	AttributID(string valInput, string name);
	virtual void* getValue(); //random
	~AttributID();

protected:
	int valeur;
};

#endif