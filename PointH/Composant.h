#ifndef CLUEDO_COMPOSANT_H
#define CLUEDO_COMPOSANT_H
#include "IncludeAndDefine.h"
#include "Case.h"
#include "Carte.h"
#include "Bouton.h"

class BlocNote{
private:
    string nomDeCartes[NB_CARTE];
    bool barre[NB_CARTE];
    bool entoure[NB_CARTE];
public:
    void InitialisationBlocNote();
    void BarrePremierJoueur(vector <Carte> Deck);
    void ChangementIndiceBarre();
    void ChangementIndiceEntoure();
    void AfficherBlocNote(RenderWindow &window);
};

class De{
private:
    int valeur=rand()%NB_FACES_DE+1;
    Sprite spriteFace[6];
    Texture textureFace[6];
public:
    void InitialisationDe();
    void AfficherDe(RenderWindow &window,int x,int y,int l,int h);
    int LancerDe();
};

class Pion{
private:
    Sprite spritePion;
    Texture texturePion;
    Color colorPion;
    int x,y;
public:
void InitPion(Color C,int x0,int y0);
void AfficherPion(RenderWindow& window);
void setCoordsPion(int x0, int y0);
void DeplacementPion(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int ValeurDe);

};
#endif //CLUEDO_COMPOSANT_H
