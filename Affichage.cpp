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

void AffichageMenu(Sprite fondMenu[], int menu, RenderWindow& window, Joueur* joueur){
    window.draw(fondMenu[menu]);
    switch (menu) {
        case 2:
            for (int i = 0; i < NB_JOUEURS; ++i) {
                joueur[i].AffichageCroix(window,i);
                joueur[i].AffichageAvatarMenu2(window,i);
                joueur[i].AffichagePictogramme(window,i);
            }
            break;
    }
}