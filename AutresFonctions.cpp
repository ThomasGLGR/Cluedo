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
    int nbCarteRestante=NB_CARTE_JOUABLE;
    int a=0;
    while (nbCarteRestante>0){
        joueur[a%nbJoueurs].PiocherCarte(carte[nbCarteRestante-1]);
        a++;
        nbCarteRestante--;
    }
}

void MelangerCarte(Carte carte[NB_CARTE]){
    srand(time(NULL));
    for (int i = 0; i < 500; ++i) {
        int a=rand()%NB_CARTE;
        int b=rand()%NB_CARTE;
        Carte C=carte[a];
        carte[a]=carte[b];
        carte[b]=C;
    }
}

void InitialisationEnveloppe(Carte* enveloppe,Carte carte[NB_CARTE]){
    enveloppe[Perso].RemplirEnveloppe(carte,Perso);
    enveloppe[Arme].RemplirEnveloppe(carte,Arme);
    enveloppe[Lieu].RemplirEnveloppe(carte,Lieu);
}

void InitialisationMapSuite(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR] ,Joueur* joueur,int nbJ) {
    Case Spawn[6];
    int a=0;
    for (int i = 0; i < NB_CASE_HAUTEUR; ++i) {
        for (int j = 0; j < NB_CASE_LARGEUR; ++j) {
            if(plateau[i][j].getTypedeCase()==3){
                Spawn[a]=plateau[i][j];
                a++;
            }
        }
    }
    bool Verif[6];
    for (int i = 0; i < 6; ++i) {
        Verif[i]= true;
    }
    for (int i = 0; i < nbJ; ++i) {
        a=rand()%6;
        if (Verif[a]){
            joueur[i].setPion(Spawn[a].getX(), Spawn[a].getY());
            Verif[a]= false;
        }else{
            i--;
        }
    }
}