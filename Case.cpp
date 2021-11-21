#include "PointH/Case.h"

Case::Case() {
}

void Case::InitCase(int x0,int y0,int typedeCase0){
    x=x0;
    y=y0;
    typedeCase=typedeCase0;
}


void InitialisationPlateau(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR]){
    ifstream fichierTexte("../PointTXT/InitialisationMap.txt");
    for (int i = 0; i < NB_CASE_HAUTEUR; ++i) {
        for (int j = 0; j < NB_CASE_LARGEUR; ++j) {
            char c;
            fichierTexte.get(c);
            if (c=='\n') {
                j--;
            }else{
                int type;
                switch (c) {
                    case '*':
                        type=Vide;
                        break;
                    case '#':
                        type=Deplacement;
                        break;
                    case 'O':
                        type=Salle;
                        break;
                    case 'S':
                        type=Spawn;
                        break;
                }
                plateau[i][j].InitCase(DEBUT_PLATEAU_X + j * LONGEUR_CASE,DEBUT_PLATEAU_Y + i * LONGEUR_CASE, type);
            }
        }
    }
    fichierTexte.close();
}
