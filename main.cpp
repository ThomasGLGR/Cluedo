#include "PointH/AutresFonctions.h"

int main()
{
    RenderWindow window;
    window.create(VideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN), "Cluedo",Style::Fullscreen);
    window.setPosition(Vector2i(0,0));
    window.setFramerateLimit(30);


    Sprite fondMenu[7];
    Texture texture[7];
    InitialisationSprite(fondMenu,texture);

    Carte carte[NB_CARTE];
    Carte enveloppe[3];
    cartePossible choixJoueurCarte[NB_PERSO];
    Proposition proposition;
    Joueur joueur[NB_JOUEURS];
    Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR];
    De de[2];
    vector<string> RegleDuJeu;
    InitialisationCarte(carte, choixJoueurCarte);
    proposition.InitialisationProposition(carte);
    MelangerCarte(carte);
    InitialisationEnveloppe(enveloppe,carte);
    InitialisationPlateau(plateau);
    InitialisationRegle(RegleDuJeu);
    de[0].InitialisationDe();
    de[1].InitialisationDe();
    joueur[0].InitialisationJoueur(choixJoueurCarte);
    joueur[1].InitialisationJoueur(choixJoueurCarte);

    int menu=0;
    int nbJoueurs=0;
    int SommeDesDes=0;
    int tour=0;
    bool MontrerProposition=false;


    while (window.isOpen()) {
        Event event;

        while (window.waitEvent(event)) {
            AffichageMenu(fondMenu, menu, window, joueur,de,nbJoueurs,plateau,tour,proposition,MontrerProposition);

            /*
            Sprite test;
            Texture texture1;
            Image I;
            Image I2;
            texture1.loadFromFile("../Image/unknown.png");
            I=texture1.copyToImage();
            I2=texture1.copyToImage();
            for (int i = 0; i < texture1.getSize().x; ++i) {
                for (int j = 0; j < texture1.getSize().y; ++j){
                    if (I.getPixel(i,j).b>100 && I.getPixel(i,j).g<190 && I.getPixel(i,j).r<185){
                        I.setPixel(i, j, Color(Color(I.getPixel(i,j).r+80, I.getPixel(i,j).g/5,I.getPixel(i,j).b/4)));
                    }
                }
            }
            for (int i = 0; i < texture1.getSize().x; ++i) {
                for (int j = 0; j < texture1.getSize().y; ++j){
                    if (I.getPixel(i,j).b<40 && I.getPixel(i,j).g<40 && I.getPixel(i,j).r>200){
                        I.setPixel(i,j,Color(I2.getPixel(i,j).r,I2.getPixel(i,j).g,I2.getPixel(i,j).b));
                    }
                }
            }
            test.setPosition(400,100);
            texture1.update(I);
            texture1.setSmooth(true);
            test.setTexture(texture1);
            window.draw(test);
             */
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
                            ClicDroit(menu,joueur,tour);
                            break;
                        case Mouse::Left:
                            ClicGauche(menu, joueur, choixJoueurCarte, nbJoueurs, carte, de, SommeDesDes,plateau,tour,proposition,MontrerProposition);
                            break;
                    }
                    break;
                case Event::MouseMoved:
                    SourisMouvement(menu, window);
                    break;
                case Event::MouseWheelMoved:

                    break;
            }
            window.display();
            window.clear();
        }
    }
    return 0;
}