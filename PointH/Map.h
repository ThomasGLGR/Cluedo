#include "IncludeAndDefine.h"
#ifndef CLUEDO_MAP_H
#define CLUEDO_MAP_H
enum{
    Vide=0,Salle,Deplacement
};

class Case{
private:
    int x;
    int y;
    int typedeCase;
    bool joueurDessus;
public:
};


class Map {
private:
    Case* cases;
public:
    void caseDispo();

};


#endif //CLUEDO_MAP_H
