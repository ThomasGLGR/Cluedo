#include "PointH/Composant.h"
#include "PointH/IncludeAndDefine.h"

void De::InitialisationDe() {
    for (int i = 0; i < NB_FACES_DE; ++i) {
        textureFace[i].loadFromFile("../Image/Dice.png",IntRect(320*i,320,320,312));
        textureFace[i].setSmooth(true);
    }
}
void De::AfficherDe(RenderWindow &window,int x,int y,int l,int h){
    Vector2f targetSize(l, h);
    spriteFace[valeur-1].setTexture(textureFace[valeur-1]);
    /*stackOverflow*/spriteFace[valeur-1].setScale(targetSize.x / spriteFace[valeur-1].getLocalBounds().width,targetSize.y / spriteFace[valeur-1].getLocalBounds().height);
    spriteFace[valeur-1].setPosition(x,y);
    window.draw(spriteFace[valeur-1]);
}

int De::LancerDe() {
    valeur=rand()%NB_FACES_DE+1;
    return valeur;
}

void Pion::InitPion(Color C,int x0,int y0){
    colorPion=C;
    texturePion.loadFromFile("../Image/pawn.png");
    setCoordsPion(x0,y0);
}

void Pion::AfficherPion(RenderWindow& window) {
    spritePion.setTexture(texturePion);
    spritePion.setColor(colorPion);
    spritePion.setPosition(x,y);
    window.draw(spritePion);
}
void Pion::setCoordsPion(int x0, int y0) {
    x=x0;
    y=y0;
}

void Pion::DeplacementPion(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int ValeurDe) {
    int Ideplacement;
    int Jdeplacement;
    for (int i = 0; i < NB_CASE_HAUTEUR; ++i) {
        for (int j = 0; j < NB_CASE_LARGEUR; ++j) {
            plateau[i][j].setDeplacementPossible(false);
            if (plateau[i][j].getX() == x && plateau[i][j].getY() == y) {
                Ideplacement = i;
                Jdeplacement = j;
            }
        }
    }
    plateau[Ideplacement][Jdeplacement].setDeplacementPossible(true);

}