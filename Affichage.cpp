#include "PointH/AutresFonctions.h"

void InitialisationSprite(Sprite fondMenu[],Texture* texture){
    for (int i = 0; i < 7; ++i) {
        string filename="../Image/Menu0.jpg";
        filename[13]=i+48;
        texture[i].loadFromFile(filename);
        fondMenu[i].setTexture(texture[i]);
    }
}

void AffichageMenu(Sprite fondMenu[], int menu, RenderWindow& window, Joueur* joueur,De* de,int nbJ,Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int tour,Proposition proposition,bool MontrerProposition){
    if  (menu!=ERREUR){window.draw(fondMenu[menu]);}
    switch (menu) {
        case 0: {
            Sprite spriteLogo;
            Texture textureLogo;
            textureLogo.loadFromFile("../Image/Logo.png");
            textureLogo.setSmooth(true);
            spriteLogo.setPosition(1080 - (960 - Mouse::getPosition().x) / 15, 600 - (540 - Mouse::getPosition().y) / 15);
            Vector2f targetSize(1000, 500);
            spriteLogo.setTexture(textureLogo);
           spriteLogo.setScale(targetSize.x / spriteLogo.getLocalBounds().width,
                                                 targetSize.y / spriteLogo.getLocalBounds().height);
            window.draw(spriteLogo);
        }
            break;
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
                if (MontrerProposition){
                    if (i<3){
                        joueur[i].AfficherCarteProposition(window,180,200*i+50);
                    }else{
                         joueur[i].AfficherCarteProposition(window,430,200*(i-3)+50);
                    }
                }
           }
            break;
        case 6:
            proposition.AfficherProposition(window);
            proposition.AfficherCarteAChoisir(window);
            break;
    }
}