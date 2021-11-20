#ifndef CLUEDO_CARTE_H
#define CLUEDO_CARTE_H
#include "IncludeAndDefine.h"

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
    void dessinerCarte(RenderWindow& window,int x,int y,int l,int h);
    void Couleur(ifstream& fichierTexte);
    Color getRGB();
    string getNom();
};


class cartePossible{
private:
    carte Carte;
    bool utilise=false;
public:
    void setCarte(carte C);
    void changement();
    carte getCarte();
    bool getUtilise();
};

#endif