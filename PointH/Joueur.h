#include "IncludeAndDefine.h"
#include "Carte.h"
#include "Composant.h"
#ifndef CLUEDO_PERSO_H
#define CLUEDO_PERSO_H
enum etatActuelleInscription{
    Debut=0,Nouveau,Connexion,Pret
};

class Joueur {
private:
    string identifiant="\0";
    string mdp="\0";
    int NbVictoires=0, NbJoues=0;
    Carte avatar;
    vector <Carte> Deck;

    Pion pion;

    int etatInscription=Debut;
    int memoire=ERREUR;

    BlocNote blocnote;

    bool joueurJoue = false;
    bool enCourdeModif=false;
    bool messageErreur=false;
    bool AfficherIdentifiant = false;
    bool ecritureMDP = false;

    bool AfficherProposition=false;
    Carte propostionaAfficher;
    bool HorsJeu=false;

public:

    void InitialisationJoueur(cartePossible* choixJoueurCarte);
    void SupprimerJoueur(cartePossible* choixJoueurCarte);
    void choixPerso(cartePossible* choixJoueurCarte,int start);
    bool getjoueurJoue()const;
    int getEtatInscription()const;
    int getMemoire()const;
    bool getAfficherIdentifiant()const;
    void EcrireNom(RenderWindow& window,int t, string nomPerso,int x,int y,Color C);
    void AfficheID();
    void setEcritureMDP(bool A);
    int WinRate()const;
    Pion getPion();
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
    void AfficherCarteEnMain(RenderWindow& window);
    void AfficherCarteEnMainZoom(RenderWindow &window,int x,int y, int l, int h,int i);
    void setPion(int x0,int y0);
    void BarrePremierCarte();
    BlocNote getBlocnote();
    void changementBlocNoteBarre();
    void changementBlocNoteEntoure();
    void AfficherJoueurEnCours(RenderWindow &window,int x,int y);
    void AfficherFlecheJoueurEnCours(RenderWindow &window,int x,int y);
    void VerificationProposition(Carte* proposition,bool& stop);
    void AfficherCarteProposition(RenderWindow &window,int x,int y);
    void SupprimerAfficherProposition();
    void AfficherCroixProposition(RenderWindow &window,int x,int y);
    bool getAfficherProposition();
    void AfficheEcranVictoire(RenderWindow& window);
    void clearJoueur();
    void setHorsJeu(bool A);
    bool getHorsJeu();
    void AjouterUnePartie(bool A);
    void sauvegarde(ofstream& fichierTexte);
    void chargerPartie(basic_string<char> Id,basic_string<char>StringCarte,vector<basic_string<char>> ListeCarte,bool Hors_Jeu,int Xpion,int Ypion,vector<int> ListeBlocNote,Carte carte[NB_CARTE]);
};

#endif //CLUEDO_PERSO_H
