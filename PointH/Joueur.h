#include "IncludeAndDefine.h"
#include "Carte.h"
#ifndef CLUEDO_PERSO_H
#define CLUEDO_PERSO_H
enum etatActuelleInscription{
    Debut=0,Nouveau,Connexion,Pret
};

class BlocNote{
private:
    string* nomDeCartes;
public:
    void AjouterIndice();
    void SupprimerIndice();
    void AfficherBlocNote();
};

class Joueur {
private:
    string identifiant="\0";
    string mdp="\0";
    int NbVictoires=0, NbJoues=0;
    Carte avatar;
    vector <Carte> Deck;

    int etatInscription=Debut;
    int memoire=-1;

    BlocNote blocnote;
    int De;

    bool joueurJoue = false;
    bool enCourdeModif=false;
    bool messageErreur=false;
    bool AfficherIdentifiant = false;
    bool ecritureMDP = false;

public:

    void InitialisationJoueur(cartePossible* choixJoueurCarte);
    void SupprimerJoueur(cartePossible* choixJoueurCarte);
    void choixPerso(cartePossible* choixJoueurCarte,int start);


    bool getjoueurJoue()const;
    int getEtatInscription()const;
    int getMemoire()const;
    bool getAfficherIdentifiant()const;


    void EcrireNom(RenderWindow& window,int t, string nomPerso,int x,int y);
    void AfficheID();
    void setEcritureMDP(bool A);
    int WinRate()const;

    void ChangementPerso(cartePossible* choixJoueurCarte);
    void EcrireID(RenderWindow &window, int t, string Nom,int x,int y,bool protection);
    void ModifierTexteID(Event event);
    void setenCourdeModif(bool A);
    void SupprimerTexteID();
    void setetatInscription(int A);
    void AjouterUnJoueur();
    void VerifierJoueurExistant();
    void PiocherCarte(Carte carte);

    //Affichage Menu 2
    void AffichagePictogramme(RenderWindow& window, int i);
    void AffichageCroix(RenderWindow& window,int i);
    void AffichageAvatarMenu2(RenderWindow& window,int i);

    };

#endif //CLUEDO_PERSO_H
