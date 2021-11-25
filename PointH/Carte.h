#ifndef CLUEDO_CARTE_H
#define CLUEDO_CARTE_H
#include "IncludeAndDefine.h"

enum TypeCarte {
    Perso=0,Arme,Lieu
};

class Carte{
private:
protected:

    sf::Texture textureCarte;
    std::string nomCarte;
    int typeCarte;
    sf::Color RGBText=sf::Color::White;
public:
    Carte();
    Carte(const sf::Texture& textureCarte0,std::string nomCarte0,int typeCarte0,sf::Color RGBText0);

    void InitCarte(std::ifstream& fichierTexte,int Type,int x,int y,int l, int L);
    void dessinerCarte(sf::RenderWindow& window,int x,int y,int l,int h);
    void Couleur(std::ifstream& fichierTexte);

    sf::Color getRGB();
    std:: string getNom();
    sf::Texture getTexture();

    void RemplirEnveloppe(Carte* carte,int type);
    void setCarteDepuisString(std::string S,Carte carte[NB_CARTE]);
    virtual void setCarte(Carte C);
};


class cartePossible: public Carte{
private:
    bool utilise=false;
public:
    void changement();
    bool getUtilise();
    Carte getCarte();
    void setCarte(Carte C) override;
};

#endif