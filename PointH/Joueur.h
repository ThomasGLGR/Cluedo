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
    std::string identifiant="\0";
    std::string mdp="\0";
    int NbVictoires=0, NbJoues=0;
    Carte avatar;
    std::vector <Carte> Deck;

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

    void AjouterUnJoueur();
    void VerifierJoueurExistant();
    void PiocherCarte(Carte carte);
    void SupprimerJoueur(cartePossible* choixJoueurCarte);
    void choixPerso(cartePossible* choixJoueurCarte,int start);
    int WinRate()const;
    void AjouterUnePartie(bool A);
    void ChangementPerso(cartePossible* choixJoueurCarte);
    void BarrePremierCarte();


    bool getjoueurJoue()const;
    int getEtatInscription()const;
    int getMemoire()const;
    bool getAfficherIdentifiant()const;
    Pion getPion();
    BlocNote getBlocnote();
    bool getHorsJeu() const;
    bool getAfficherProposition() const;

    void setHorsJeu(bool A);
    void setEcritureMDP(bool A);
    void setetatInscription(int A);
    void setenCourdeModif(bool A);
    void setPion(int x0,int y0);

    void EcrireNom(sf::RenderWindow& window,int t, std::string nomPerso,int x,int y,sf::Color C);
    void EcrireID(sf::RenderWindow &window, int t, std::string Nom,int x,int y,bool protection);
    void ModifierTexteID(sf::Event event);
    void SupprimerTexteID();
    void AfficheID();

    void AffichagePictogramme(sf::RenderWindow& window, int i);
    void AffichageCroix(sf::RenderWindow& window,int i);
    void AffichageAvatarMenu2(sf::RenderWindow& window,int i);
    void AfficherCarteEnMain(sf::RenderWindow& window);
    void AfficherCarteEnMainZoom(sf::RenderWindow &window,int x,int y, int l, int h,int i);
    void AfficherJoueurEnCours(sf::RenderWindow &window,int x,int y);
    void AfficherFlecheJoueurEnCours(sf::RenderWindow &window,int x,int y);
    void AfficherCroixProposition(sf::RenderWindow &window,int x,int y);
    void AfficherCarteProposition(sf::RenderWindow &window,int x,int y);
    void AfficheEcranVictoire(sf::RenderWindow& window);

    void changementBlocNoteBarre();
    void changementBlocNoteEntoure();

    void VerificationProposition(Carte* proposition,bool& stop);
    void SupprimerAfficherProposition();

    void clearJoueur();

    void sauvegarde(std::ofstream& fichierTexte);
    void chargerPartie(std::basic_string<char> Id,std::basic_string<char>StringCarte,std::vector<std::basic_string<char>> ListeCarte,bool Hors_Jeu,int Xpion,int Ypion,std::vector<int> ListeBlocNote,Carte carte[NB_CARTE]);
};

#endif //CLUEDO_PERSO_H
