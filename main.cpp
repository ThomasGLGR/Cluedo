#include "PointH/AutresFonctions.h"

int main()
{

    RenderWindow window;
    window.create(VideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN), "Cluedo",Style::Fullscreen);
    window.setPosition(Vector2i(0,0));
    window.setFramerateLimit(30);

    Sprite fondMenu[8];
    Texture texture[8];
    InitialisationSprite(fondMenu,texture);

    Carte carte[NB_CARTE];
    Carte enveloppe[3];
    cartePossible choixJoueurCarte[NB_PERSO];
    Proposition proposition;
    Joueur joueur[NB_JOUEURS];
    Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR];
    De de[2];
    RegleDuJeu regleDuJeu;
    int menu = 0;
    int nbJoueurs = 0;
    int SommeDesDes = 0;
    int tour = 0;
    bool MontrerProposition = false;
    bool End = true;

    InitialisationCarte(carte, choixJoueurCarte);
    proposition.InitialisationProposition(carte);
    InitialisationPlateau(plateau);
    de[0].InitialisationDe();
    de[1].InitialisationDe();
    regleDuJeu.InitialisationRegle();

        while (window.isOpen()) {
            Event event;
            while (window.waitEvent(event)) {
                if (End) {
                    MelangerCarte(carte);
                    InitialisationEnveloppe(enveloppe, carte);
                    for (int i = 0; i < 3; ++i) {
                        cout<<enveloppe[i].getNom();
                    }
                    joueur[0].InitialisationJoueur(choixJoueurCarte);
                    joueur[1].InitialisationJoueur(choixJoueurCarte);

                    nbJoueurs = 0;
                    SommeDesDes = 0;
                    tour = 0;
                    MontrerProposition = false;
                    End = false;
                    }
                    AffichageMenu(fondMenu, menu, window, joueur, de, nbJoueurs, plateau, tour, proposition,
                                  MontrerProposition, regleDuJeu);
                    switch (event.type) {
                        case Event::Closed:
                            window.close();
                            break;
                        case Event::TextEntered:
                            ClavierTexte(menu, joueur, event);
                            break;
                        case Event::KeyPressed:
                            Clavier(menu, joueur, event, window, End);
                            break;
                        case Event::MouseButtonReleased:
                            switch (event.mouseButton.button) {
                                case Mouse::Right:
                                    ClicDroit(menu, joueur, tour);
                                    break;
                                case Mouse::Left:
                                    ClicGauche(menu, joueur, choixJoueurCarte, nbJoueurs, carte, de, SommeDesDes,
                                               plateau,
                                               tour, proposition, MontrerProposition, enveloppe,End);
                                    break;
                            }
                            break;
                        case Event::MouseMoved:
                            SourisMouvement(menu, window);
                            break;
                        case Event::MouseWheelMoved:
                            SourisMolette(menu, event, regleDuJeu);
                            break;
                    }
                    window.display();
                    window.clear();
                }
            window.close();
        }
    return 0;
}