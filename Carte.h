#ifndef CLUEDO_CARTE_H
#define CLUEDO_CARTE_H
#include "Fonction.h"

enum TypeCarte {
    Perso=0,Arme,Lieu
};


class carte{
private:
protected:
    Sprite spriteCarte;
    Texture textureCarte;
    string nomCarte;
    int typeCarte;
    Color RGBText=Color::White;
public:
    void InitCarte(ifstream& fichierTexte,int Type,int x,int y,int l, int L);
    void MelangeCarte();
    string getNom();
    int getType();
    Sprite getSprite();
    void dessinerCarte(RenderWindow& window,int x,int y,int l,int h);
    void Couleur(ifstream& fichierTexte);
Color getRGB();
};

class cartePossible{
private:
    carte Carte;
    bool utilise=false;
public:
    carte getCarte();
    void changement();
    bool getUtilise();
    void setCarte(carte C);

};

#endif