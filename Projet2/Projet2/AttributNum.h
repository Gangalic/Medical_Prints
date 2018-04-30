#if ! defined (AttributNum_H)
#define AttributNum_H
#include "Attribut.h"

class AttributNum : public Attribut {

public:

	AttributNum(string valInput, string name);

	~AttributNum();

protected:
	double valeur;
};

#endif