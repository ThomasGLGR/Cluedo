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