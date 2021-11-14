#include "Fonction.h"
#ifndef CLUEDO_BOUTON_H
#define CLUEDO_BOUTON_H


class bouton {
private:
    int x;
    int y;
    int l;
    int L;
    Color couleur;
public:
    bouton(int x0,int y0,int l0,int L0,Color couleur0);
    int Clic(int variable);
    void DessinerRectangle(RenderWindow& window, Event event);

};


#endif //CLUEDO_BOUTON_H
