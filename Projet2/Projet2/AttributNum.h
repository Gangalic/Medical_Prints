#if ! defined (AttributNum_H)
#define AttributNum_H
#include "Attribut.h"

class AttributNum : public Attribut {

public:

	AttributNum();
	AttributNum(string valInput, string name);
	virtual void* getValue(); //random
	~AttributNum();

protected:
	double valeur;
};

#endif