#include "IncludeAndDefine.h"
#ifndef CLUEDO_MAP_H
#define CLUEDO_MAP_H
enum{
    Vide=0,Salle,Deplacement,Spawn
};

class Case{
private:
    int x;
    int y;
    int typedeCase;
    bool joueurDessus=false;
    bool haut,bas,gauche,droite=false;
public:
    void InitCase(int x0,int y0,int typedeCase0);
    Case();
    void test();
};

#endif //CLUEDO_MAP_H
