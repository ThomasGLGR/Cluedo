#include "PointH/AutresFonctions.h"

int NombreDeJoueurs(Joueur* joueur){
    int nbJ=0;
    for (int i = 0; i < NB_JOUEURS; ++i) {
        if (joueur[i].getjoueurJoue()){
            nbJ++;
        }
    }
    return nbJ;
}

void DistributionCarte(Joueur* joueur,Carte* carte,int nbJoueurs){
    int nbCarteRestante=NB_CARTE;
    int a=0;
    while (nbCarteRestante>0){
        joueur[a%nbJoueurs].PiocherCarte(carte[nbCarteRestante-1]);
        a++;
        nbCarteRestante--;
    }
}