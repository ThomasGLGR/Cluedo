#ifndef CLUEDO_PARAMETRE_H
#define CLUEDO_PARAMETRE_H
#include "IncludeAndDefine.h"
#include "Joueur.h"

class Parametre {
private:
    int menuMemoire=1;
public:
    void setmenuMemoire(int m);
    int getmenuMemoire();
    void sauvegarder(Joueur* joueur, int tour,int NbJoueur,Carte* enveloppe);
    static void ChargerPartie(Joueur* joueur, int& tour,int& NbJoueur,Carte enveloppe[3]);
};

#endif //CLUEDO_PARAMETRE_H
