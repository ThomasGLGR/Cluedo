#include "PointH/AutresFonctions.h"

int main()
{

    RenderWindow window;
    window.create(VideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN), "Cluedo",Style::Fullscreen);
    window.setPosition(Vector2i(0,0));
    window.setFramerateLimit(30);

    Event event;

    Sprite fondMenu[8];
    Texture texture[8];
    InitialisationSprite(fondMenu,texture);

    Carte carte[NB_CARTE];
    Carte carteCopy[NB_CARTE];
    Carte enveloppe[3];
    cartePossible choixJoueurCarte[NB_PERSO];
    Proposition proposition;
    Joueur joueur[NB_JOUEURS];
    Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR];
    De de[2];
    RegleDuJeu regleDuJeu;
    Parametre parametre;
    int menu = 0;
    int nbJoueurs = 0;
    int SommeDesDes = 0;
    int tour = 0;
    bool MontrerProposition = false;
    bool End = true;

    de[0].InitialisationDe();
    de[1].InitialisationDe();
    InitialisationPlateau(plateau);
    InitialisationCarte(carte);
    for (int i = 0; i < NB_CARTE; ++i) {
        carteCopy[i]=carte[i];
    }

    while (window.isOpen()) {
        AffichageMenu(fondMenu, menu, window, joueur, de, nbJoueurs, plateau, tour, proposition,  MontrerProposition, regleDuJeu);

        while (window.pollEvent(event)) {
            if (End) {
                for (int i = 0; i < NB_CARTE; ++i) {
                    carte[i]=carteCopy[i];
                }
                InitialisationCartePossible(carte,choixJoueurCarte);
                for (auto & i : joueur) {
                    i.clearJoueur();
                }

                joueur[0].InitialisationJoueur(choixJoueurCarte);
                joueur[1].InitialisationJoueur(choixJoueurCarte);

                proposition.InitialisationProposition(carte);
                regleDuJeu.InitialisationRegle();

                MelangerCarte(carte);
                InitialisationEnveloppe(enveloppe, carte);


                proposition.clearProposition();
                cout<<"-------------Solution----------------"<<endl;
                for (auto & i : enveloppe) {
                    cout<<i.getNom()<<endl;
                }
                cout<<"-------------------------------------"<<endl;
                nbJoueurs = 0;
                SommeDesDes = 0;
                tour = 0;
                MontrerProposition = false;
                End = false;
            }
            switch (event.type) {
                        case Event::Closed:
                            window.close();
                            break;
                        case Event::TextEntered:
                            ClavierTexte(menu, joueur, event);
                            break;
                        case Event::KeyPressed:
                            Clavier(menu, joueur, event, window, End,parametre);
                            break;
                        case Event::MouseButtonReleased:
                            switch (event.mouseButton.button) {
                                case Mouse::Right:
                                    ClicDroit(menu, joueur, tour);
                                    break;
                                case Mouse::Left:
                                    ClicGauche(menu, joueur, choixJoueurCarte, nbJoueurs, carte, de, SommeDesDes,
                                               plateau,
                                               tour, proposition, MontrerProposition, enveloppe,End,parametre,window,carteCopy);
                                    break;
                            }
                            break;
                        case Event::MouseWheelMoved:
                            SourisMolette(menu, event, regleDuJeu);
                            break;
                    }
        }
        window.display();
        }
    return 0;
}