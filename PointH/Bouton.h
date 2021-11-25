#include "IncludeAndDefine.h"
#ifndef CLUEDO_BOUTON_H
#define CLUEDO_BOUTON_H


class Bouton {
private:
    int x;
    int y;
    int h;
    int l;
    sf::Color couleur;
public:
    Bouton(int x0, int y0, int h0, int l0, sf::Color couleur0);
    int Clic(int variable);
    void DessinerRectangle(sf::RenderWindow& window, float line);
};


#endif //CLUEDO_BOUTON_H
