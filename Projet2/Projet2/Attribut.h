#if ! defined (Attribut_H)
#define Attribut_H
#include <string>
using namespace std;
class Attribut
{
public:
	Attribut();
	void* getValue();
	~Attribut();
protected:
	string nom;
};

#endif
