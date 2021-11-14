#include "Carte.h"
#ifndef CLUEDO_PERSO_H
#define CLUEDO_PERSO_H


class perso {
private:
    string identifiant="\0";
    string mdp="\0";
    int NbVictoires=0, NbJoues=0;
    carte *Deck;
    bool joueurJoue = false;
    bool AfficherIdentifiant = false;
    bool ecritureMDP = false;
    carte avatar;
    int memoire=-1;
    bool enCourdeModif=false;
    short nouveauOuAncienCompte=0; //0=Personne,1=Nouveau Compte,2= AncierCompte;
public:
    void choixPerso(cartePossible* choixJoueurCarte,int start);
    carte getAvatar();
    void InitPerso();
    void SuppPerso();
    bool getjoueurJoue();
    void setAvatar(carte C);
    void EcrireNom(RenderWindow& window,int t, string nomPerso,int x,int y);
    void LibererPerso(cartePossible* choixJoueurCarte);
    int getMemoire();
    bool getAfficherIdentifiant();
    void AfficheID();
    void setEcritureMDP(bool A);
    bool getEcritureMDP();
    string getID();
    string getMDP();
    void EcrireID(RenderWindow &window, int t, string Nom,int x,int y);
   void ModifierTexteID(Event event);
    bool getenCourdeModif();
    void setenCourdeModif(bool A);
    void SupprimerTexteID();
    short getnouveauOuAncienCompte();
    void setnouveauOuAncienCompte(short A);
    };
void InitialisationCarte(carte Carte[NB_CARTE],cartePossible choixJoueurCarte[]);
void InitialisationJoueur(perso& Perso,cartePossible* choixJoueurCarte);
void AffichageMenu(Sprite fondMenu[],short menu,RenderWindow& window,perso* Perso);
void ClicGauche(short& menu,perso* Perso,cartePossible choixJoueurCarte[]);
void SupprimerJoueur(perso& Perso,cartePossible* choixJoueurCarte);
void ChangementPerso(perso& Perso,cartePossible* choixJoueurCarte);
void ClavierTexte(short menu,perso* Perso,Event event);
void Clavier(short menu,perso* Perso,Event event,RenderWindow& window);
#endif //CLUEDO_PERSO_H
