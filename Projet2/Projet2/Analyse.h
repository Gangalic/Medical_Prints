#if ! defined (Analyse_H)
#define Analyse_H

class Analyse
{
public:
    //Analyse();

<<<<<<< HEAD
//	void Analyse();
=======
	multimap<string,double> FaireAnalyse(Patient unPatient, vector<Maladie>maladies);
>>>>>>> 483c775da1338cf6af1b3e12182e48e2adf226e2

	double risqueNumerique(Attribut* attPatient,Attribut* attMaladie);

	double risqueCategorique(Attribut* attPatient, Attribut* attMaladie);

	
	~Analyse();


};

#endif
