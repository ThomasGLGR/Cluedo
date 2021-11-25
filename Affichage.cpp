#include "PointH/AutresFonctions.h"

void InitialisationSprite(sf::Sprite fondMenu[],sf::Texture* texture){
    for (int i = 0; i < 8; ++i) {
        std::string filename="../Image/Menu2.jpg";
        filename[13]=i+48;
        if (i==4 || i==7){filename[13]='X';}
        texture[i].loadFromFile(filename);
        fondMenu[i].setTexture(texture[i]);
    }
}
void AfficherFleche(sf::RenderWindow &window,int x,int y){
    sf::Sprite Sfleche;
    sf::Texture Tfleche;
    Tfleche.loadFromFile("../Image/next.png");
    Tfleche.setSmooth(true);
    sf::Vector2f targetSize(150, 150);
   Sfleche.setTexture(Tfleche);
   Sfleche.setColor(ROUGE_MENU);
    Sfleche.setScale(targetSize.x / Sfleche.getLocalBounds().width,targetSize.y / Sfleche.getLocalBounds().height);
    Sfleche.setPosition(x,y);
    window.draw(Sfleche);
}


void AffichageMenu(sf::Sprite fondMenu[], int menu, sf::RenderWindow& window, Joueur* joueur,De* de,int nbJ,Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int tour,Proposition proposition,bool MontrerProposition,RegleDuJeu regleDuJeu){
    if  (menu!=ERREUR){window.draw(fondMenu[menu]);}
    switch (menu) {
        case 0: {
            sf::Sprite spriteLogo;
            sf::Texture textureLogo;
            textureLogo.loadFromFile("../Image/Logo.png");
            textureLogo.setSmooth(true);
            spriteLogo.setPosition(1080 - (960 - sf::Mouse::getPosition().x) / 15,
                                   600 - (540 - sf::Mouse::getPosition().y) / 15);
            sf::Vector2f targetSize(1000, 500);
            spriteLogo.setTexture(textureLogo);
            spriteLogo.setScale(targetSize.x / spriteLogo.getLocalBounds().width,
                                targetSize.y / spriteLogo.getLocalBounds().height);
            window.draw(spriteLogo);
        }
            break;
        case 1:
            for (int i = 0; i < 3; ++i) {
                Bouton boutonMenu{LARGEUR_ECRAN / 3, 240 + 210 * i, 100, LARGEUR_ECRAN / 3, ROUGE_MENU};
                boutonMenu.DessinerRectangle(window, 10.f);
            }
            break;
        case 2:
            for (int i = 0; i < NB_JOUEURS; ++i) {
                joueur[i].AffichageCroix(window, i);
                joueur[i].AffichageAvatarMenu2(window, i);
                joueur[i].AffichagePictogramme(window, i);
            }
            break;
        case 3:
            for (int i = 0; i < 3; ++i) {
                Bouton boutonOption{550, 260 + 210 * i, 100, 820, ROUGE_MENU};
                boutonOption.DessinerRectangle(window, 10.f);
            }
            break;
        case 4:
            regleDuJeu.AfficherTexte(window);
            AfficherFleche(window, 1750, 900);
            break;
        case 5:{
            joueur[tour].AfficherCarteEnMain(window);
            joueur[tour].getBlocnote().AfficherBlocNote(window);
            if (tour < 3) {
                joueur[tour].AfficherFlecheJoueurEnCours(window, 185, 200 * tour + 95);
            } else {
                joueur[tour].AfficherFlecheJoueurEnCours(window, 535, 200 * (tour - 3) + 95);
            }
            for (int j = 0; j < 2; ++j) {
                de[j].AfficherDe(window, 1400 + 165 * j, 800, 160, 156);
            }
            for (int i = 0; i < NB_CASE_HAUTEUR; ++i) {
                for (int j = 0; j < NB_CASE_LARGEUR; ++j) {
                    plateau[i][j].drawRectangle(window);
                }
            }
            for (int i = 0; i < nbJ; ++i) {
                joueur[i].getPion().AfficherPion(window);
                if (i < 3) {
                    joueur[i].AfficherJoueurEnCours(window, 50, 200 * i + 50);
                } else {
                    joueur[i].AfficherJoueurEnCours(window, 400, 200 * (i - 3) + 50);
                }
                if (MontrerProposition) {
                    bool stop = false;
                    for (int j = 1; j < nbJ; ++j) {
                        if (joueur[(tour + j) % nbJ].getAfficherProposition()) {
                            stop = true;
                        }
                        if (!stop) {
                            if ((tour + j) % nbJ < 3) {
                                joueur[(tour + j) % nbJ].AfficherCroixProposition(window, 180,
                                                                                  200 * ((tour + j) % nbJ) + 70);
                            } else {
                                joueur[(tour + j) % nbJ].AfficherCroixProposition(window, 530,
                                                                                  200 * ((tour + j) % nbJ - 3) + 70);
                            }
                        }
                    }
                    if (i < 3) {
                        joueur[i].AfficherCarteProposition(window, 180, 200 * i + 50);
                    } else {
                        joueur[i].AfficherCarteProposition(window, 530, 200 * (i - 3) + 50);
                    }
                    AfficherFleche(window, 1750, 900);
                }
            }
            Bouton boutonAccusation{792, 928, 70, 400, ROUGE_MENU};
            boutonAccusation.DessinerRectangle(window, 5.f);
    }
            break;
        case 6:
            proposition.AfficherProposition(window);
            proposition.AfficherCarteAChoisir(window);
            break;
        case 7:
            joueur[tour].AfficheEcranVictoire(window);
            AfficherFleche(window,1750,900);
            break;
    }
}

