#if ! defined (Lecture_H)
#define Lecture_H

class Lecture
{
public:
	Lecture(string fichierMeta, string fichierMal, string fichierPat);
	~Lecture();

protected:
	string nomFichierMeta;
	string nomFichierMal;
	string nomFichierPat;
};

#endif