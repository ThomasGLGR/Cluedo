#include "Fonction.h"
#include "Carte.h"
#include "perso.h"

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
    perso Perso[6];

    InitialisationCarte(Carte,choixJoueurCarte);
    InitialisationJoueur(Perso[0],choixJoueurCarte);
    InitialisationJoueur(Perso[1],choixJoueurCarte);
    short menu=0;

    while (window.isOpen()) {
        Event event;

        while (window.waitEvent(event)) {
            AffichageMenu(fondMenu,menu,window,Perso);
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case  Event::TextEntered:
                    ClavierTexte(menu,Perso,event);
                    break;
                case Event::KeyPressed:
                    Clavier(menu,Perso,event,window);
                    break;
                case Event::MouseButtonReleased:
                    switch (event.mouseButton.button) {
                        case Mouse::Right:
                            break;
                        case Mouse::Left:
                            ClicGauche(menu,Perso,choixJoueurCarte);
                            break;
                    }
                    break;
                case Event::MouseMoved:
                    SourisMouvement(menu, event, window);
                    break;
            }
                window.display();
                window.clear();

        }

    }
    return 0;
}