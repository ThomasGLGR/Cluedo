#include "PointH/AutresFonctions.h"

void InitialisationSprite(Sprite fondMenu[],Texture* texture){
    texture[0].loadFromFile("../Image/Menu0.jpg");
    fondMenu[0].setTexture(texture[0]);
    texture[1].loadFromFile("../Image/Menu1.jpg");
    fondMenu[1].setTexture(texture[1]);
    texture[2].loadFromFile("../Image/Menu2.jpg");
    fondMenu[2].setTexture(texture[2]);
    texture[5].loadFromFile("../Image/Menu5.jpg");
    fondMenu[5].setTexture(texture[5]);
}

void AffichageMenu(Sprite fondMenu[], int menu, RenderWindow& window, Joueur* joueur,De* de,int nbJ,Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int tour){
    if  (menu!=ERREUR){window.draw(fondMenu[menu]);}
    switch (menu) {
        case 2:
            for (int i = 0; i < NB_JOUEURS; ++i) {
                joueur[i].AffichageCroix(window, i);
                joueur[i].AffichageAvatarMenu2(window, i);
                joueur[i].AffichagePictogramme(window, i);
            }
            break;
        case 5:
            joueur[tour].AfficherCarteEnMain(window);
            joueur[tour].getBlocnote().AfficherBlocNote(window);
            if (tour<3) {
                joueur[tour].AfficherFlecheJoueurEnCours(window, 185, 200 * tour + 95);
            } else{
                joueur[tour].AfficherFlecheJoueurEnCours(window, 535, 200 * (tour-3) + 95);
            }
            for (int j = 0; j < 2; ++j) {
                de[j].AfficherDe(window,1400+165*j,800,160,156);
            }
            for (int i = 0; i < NB_CASE_HAUTEUR; ++i) {
                for (int j = 0; j < NB_CASE_LARGEUR; ++j) {
                        plateau[i][j].drawRectangle(window);
                    }
            }
            for (int i = 0; i < nbJ; ++i) {
                joueur[i].Afficherpion(window);
                if (i<3){
                    joueur[i].AfficherJoueurEnCours(window,50,200*i+50);
                }else{
                    joueur[i].AfficherJoueurEnCours(window,400,200*(i-3)+50);
                }
           }
            break;
    }
}