#ifndef CLUEDO_CARTE_H
#define CLUEDO_CARTE_H
#include "IncludeAndDefine.h"

enum TypeCarte {
    Perso=0,Arme,Lieu
};

class Carte{
private:
protected:

    Texture textureCarte;
    string nomCarte;
    int typeCarte;
    Color RGBText=Color::White;

public:
    void InitCarte(ifstream& fichierTexte,int Type,int x,int y,int l, int L);
    void dessinerCarte(RenderWindow& window,int x,int y,int l,int h);
    void Couleur(ifstream& fichierTexte);

    Carte();
    Carte(const Texture& textureCarte0,string nomCarte0,int typeCarte0,Color RGBText0);
    Color getRGB();
    string getNom();
    Texture getTexture();
    void RemplirEnveloppe(Carte* carte,int type);
    virtual void setCarte(Carte C);
    void setCarteDepuisString(string S,Carte carte[NB_CARTE]);
};


class cartePossible: public Carte{
private:
    bool utilise=false;
public:
    void changement();
    bool getUtilise();
    Carte getCarte();
    void setCarte(Carte C);
};

#endif