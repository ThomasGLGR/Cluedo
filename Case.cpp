#include "PointH/Case.h"

Case::Case() {
}

void Case::InitCase(int x0,int y0,int typedeCase0){
    x=x0;
    y=y0;
    typedeCase=typedeCase0;
}

int Case::getX() {
    return x;
}

int Case::getY() {
    return y;
}


int Case::getTypedeCase() {
    return typedeCase;
}
void InitialisationPlateau(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR]){
    std::ifstream fichierTexte("../PointTXT/InitialisationMap.txt");
    for (int i = 0; i < NB_CASE_HAUTEUR; ++i) {
        for (int j = 0; j < NB_CASE_LARGEUR; ++j) {
            char c;
            fichierTexte.get(c);
            if (c=='\n') {
                j--;
            }else{
                int type=c-48;
                plateau[i][j].InitCase(DEBUT_PLATEAU_X + j * LONGEUR_CASE,DEBUT_PLATEAU_Y + i * LONGEUR_CASE, type);
            }
        }
    }
    fichierTexte.close();
}
void Case::setDeplacementPossible(bool b) {
    if (typedeCase!=Vide){
        deplacementPossible=b;
    }
}

void Case::drawRectangle(sf::RenderWindow &window) {
    if (deplacementPossible) {
        sf::RectangleShape rectangle(sf::Vector2f(LONGEUR_CASE, LONGEUR_CASE));
        rectangle.setFillColor(sf::Color(80, 250, 50, 90));
        rectangle.setOutlineThickness(1.f);
        rectangle.setPosition(x, y);
        window.draw(rectangle);
    }
}

bool Case::getDeplacementPossible() {
    return deplacementPossible;
}

