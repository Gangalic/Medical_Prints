#if ! defined (AttributNum_H)
#define AttributNum_H
#include "Attribut.h"

class AttributNum : public Attribut {

public:

	AttributNum();
	AttributNum(string valInput, string name);
	auto getValue();
	~AttributNum();

protected:
	double valeur;
};

#endif