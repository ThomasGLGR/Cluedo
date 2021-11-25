#ifndef CLUEDO_COMPOSANT_H
#define CLUEDO_COMPOSANT_H
#include "IncludeAndDefine.h"
#include "Case.h"
#include "Carte.h"
#include "Bouton.h"

class BlocNote{
private:
   std::string nomDeCartes[NB_CARTE];
    bool barre[NB_CARTE];
    bool entoure[NB_CARTE];
public:
    void InitialisationBlocNote();
    void BarrePremierJoueur(std::vector <Carte> Deck);
    void ChangementIndiceBarre();
    void ChangementIndiceEntoure();
    void AfficherBlocNote(sf::RenderWindow &window);
    void clear();
    void sauvegardeBlocNote(std::ofstream& fichierTexte);
    void setBarre(bool A,int i);
};

class De {
private:
    int valeur = rand() % NB_FACES_DE + 1;
    sf::Texture textureFace[6];
    bool PeutLancerDe = true;
public:
    void InitialisationDe();
    void AfficherDe(sf::RenderWindow &window, int x, int y, int l, int h);
    void LancerDe(int &Somme);
    void setLancerDe(bool A);
    bool getPeutLancerDe();
};

class Pion{
private:
    sf::Sprite spritePion;
    sf::Texture texturePion;
    sf::Color colorPion;
    int x,y;

public:
void InitPion(sf::Color C,int x0,int y0);
void AfficherPion(sf::RenderWindow& window);
void setCoordsPion(int x0, int y0);
void DeplacementPion(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int ValeurDe,bool verif);
void sauvegardePion(std::ofstream& fichierTexte);
};
#endif //CLUEDO_COMPOSANT_H
