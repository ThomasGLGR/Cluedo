#include "PointH/AutresFonctions.h"

int main()
{
    RenderWindow window;
    window.create(sf::VideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN), "Cluedo",sf::Style::Fullscreen);
    window.setPosition(sf::Vector2i(0,0));
    window.setFramerateLimit(30);

    Sprite fondMenu[6];
    Texture texture[6];
    InitialisationSprite(fondMenu,texture);
    carte Carte[NB_CARTE];
    cartePossible choixJoueurCarte[NB_PERSO];
    Joueur joueur[NB_JOUEURS];

    InitialisationCarte(Carte,choixJoueurCarte);

    joueur[0].InitialisationJoueur(choixJoueurCarte);
    joueur[1].InitialisationJoueur(choixJoueurCarte);

    int menu=0;
    int nbJoueurs=0;

    while (window.isOpen()) {
        Event event;
        while (window.waitEvent(event)) {
            AffichageMenu(fondMenu, menu, window, joueur);
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case  Event::TextEntered:
                    ClavierTexte(menu, joueur, event);
                    break;
                case Event::KeyPressed:
                    Clavier(menu, joueur, event, window);
                    break;
                case Event::MouseButtonReleased:
                    switch (event.mouseButton.button) {
                        case Mouse::Right:
                            break;
                        case Mouse::Left:
                            ClicGauche(menu, joueur, choixJoueurCarte,nbJoueurs);
                            break;
                    }
                    break;
                case Event::MouseMoved:
                    SourisMouvement(menu, window);
                    break;
            }
            window.display();
            window.clear();
        }
    }
    return 0;
}