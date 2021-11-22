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
    bool deplacementPossible=false;
public:
    void InitCase(int x0,int y0,int typedeCase0);
    Case();
    int getTypedeCase();
    int getX();
    int getY();
    void drawRectangle(RenderWindow &window);
    void setDeplacementPossible(bool b);
    bool getDeplacementPossible();
};

#endif //CLUEDO_MAP_H
