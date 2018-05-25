#include  <iostream>
#include "Lecture.h"
int main()
{
    vector <Signature> tabS;
    Lecture l("/home/alan/Bureau/fichierTPGL/meta.txt","/home/alan/Bureau/fichierTPGL/mal.txt","/home/alan/Bureau/fichierTPGL/p.txt");
    l.LireSignatures(tabS);
    return 0;
}
