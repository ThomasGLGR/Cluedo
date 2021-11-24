#include "PointH/Proposition.h"

void Proposition::InitialisationProposition(Carte *carte) {
    for (int i = 0; i < NB_PERSO; ++i) {
        ListepropositionPerso[i]=carte[i];
    }
    for (int i = 0; i < NB_ARMES; ++i) {
        ListepropositionArme[i]=carte[i + NB_PERSO];
    }
    for (int i = 0; i < NB_SALLE; ++i) {
        ListepropositionSalle[i]=carte[i + NB_PERSO + NB_ARMES];
    }
}

void AffiliationSalle(int i1,int j1,int i2,int j2,int a,Carte* ListeSalle,Carte* Accusation){
if (i1==i2 && j1 == j2){
    Accusation[Lieu]=ListeSalle[a];
}
}
void Proposition::InitialisationSalle(int i, int j) {
    etape=0;
AffiliationSalle(i,j,3,7,1,ListepropositionSalle,accusation);
AffiliationSalle(i,j,4,15,0,ListepropositionSalle,accusation);
AffiliationSalle(i,j,7,1,4,ListepropositionSalle,accusation);
AffiliationSalle(i,j,8,8,7,ListepropositionSalle,accusation);
AffiliationSalle(i,j,8,11,7,ListepropositionSalle,accusation);
AffiliationSalle(i,j,12,14,5,ListepropositionSalle,accusation);
AffiliationSalle(i,j,13,4,4,ListepropositionSalle,accusation);
AffiliationSalle(i,j,17,8,7,ListepropositionSalle,accusation);
AffiliationSalle(i,j,17,11,7,ListepropositionSalle,accusation);
AffiliationSalle(i,j,18,14,3,ListepropositionSalle,accusation);
AffiliationSalle(i,j,21,3,2,ListepropositionSalle,accusation);
AffiliationSalle(i,j,22,15,6,ListepropositionSalle,accusation);
AffiliationSalle(i,j,23,13,6,ListepropositionSalle,accusation);
AffiliationSalle(i,j,24,6,8,ListepropositionSalle,accusation);
}

void Proposition::AfficherProposition(RenderWindow& window) {
    for (int i = 0; i < etape; ++i) {
        accusation[i].dessinerCarte(window,DEBUT_PROPOSION_X+400*i,DEBUT_PROPOSION_Y,288,460);
        EcrireNom(window,32,accusation[i].getNom(),DEBUT_PROPOSION_X+400*i+144,DEBUT_PROPOSION_Y+480,Color::White);
    }
    accusation[Lieu].dessinerCarte(window,DEBUT_PROPOSION_X+400*2,DEBUT_PROPOSION_Y,288,460);
    EcrireNom(window,32,accusation[Lieu].getNom(),DEBUT_PROPOSION_X+400*2+144,DEBUT_PROPOSION_Y+480,Color::White);
}

void Proposition::AfficherCarteAChoisir(RenderWindow& window) {
    switch (etape) {
        case 0:
        for (int i = 0; i < NB_PERSO; ++i) {
            if (Mouse::getPosition().x > 260 + 175 * i && Mouse::getPosition().x < 410 + 175 * i &&
                Mouse::getPosition().y > 200 && Mouse::getPosition().y < 440) {
                ListepropositionPerso[i].dessinerCarte(window, 223 + 175 * i, 151, 225, 338);
                EcrireNom(window, 25, ListepropositionPerso[i].getNom(), 335 + 175 * i, 129,Color::White);
            } else {
                ListepropositionPerso[i].dessinerCarte(window, 260 + 175 * i, 200, 150, 240);
            }
        }
        break;
        case 1:
        for (int i = 0; i < NB_ARMES; ++i) {
            if (Mouse::getPosition().x > 105 + 175 * i && Mouse::getPosition().x < 255 + 175 * i &&
                Mouse::getPosition().y > 200 && Mouse::getPosition().y < 440) {
                ListepropositionArme[i].dessinerCarte(window, 67 + 175 * i, 151, 225, 338);
                EcrireNom(window, 25, ListepropositionArme[i].getNom(), 179 + 175 * i, 129,Color::White);
            } else {
                ListepropositionArme[i].dessinerCarte(window, 105 + 175 * i, 200, 150, 240);
            }
        }
            break;
        case 2:
            if (Mouse::getPosition().x > 420 && Mouse::getPosition().x < 820 &&
                Mouse::getPosition().y > 290 && Mouse::getPosition().y < 400) {
                EcrireNom(window, 120, "Changer", 630, 310, ROUGE_MENU);
            }else{
                EcrireNom(window, 100, "Changer", 640, 320, ROUGE_MENU);
            }
            if (Mouse::getPosition().x > 1060 && Mouse::getPosition().x < 1460 &&
                Mouse::getPosition().y > 290 && Mouse::getPosition().y < 400) {
                EcrireNom(window, 120, "Valider", 1240, 310, ROUGE_MENU);
            }else{
                EcrireNom(window, 100, "Valider", 1250, 320, ROUGE_MENU);
            };
            break;
    }
}



void Proposition::EcrireNom(RenderWindow &window, int t, string nom, int x, int y,Color C) {
    Font font;
    font.loadFromFile("../font/Lato-Regular.ttf");
    Text text;
    text.setFont(font);
    text.setString(nom);
    text.setCharacterSize(t);
    text.setFillColor(C);
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2, textRect.height / 2);
    text.setPosition(x, y);
    window.draw(text);
}

void Proposition::ChoisiLaPropositon(bool& MontrerProposition) {
    int choixCarte=0;
    switch (etape) {
        case 0:{
            bool stop=false;
            for (int i = 0; i < NB_PERSO; ++i) {
                if (!stop) {
                    Bouton bouton(260 + 175 * i, 200, 240, 150, Color::Transparent);
                    choixCarte = bouton.Clic(i);
                    if (choixCarte!=ERREUR) {
                        stop = true;
                    }
                }
            }
            if (choixCarte != ERREUR) {
                accusation[Perso] = ListepropositionPerso[choixCarte];
                etape++;
            }
        }
            break;
        case 1:{
            bool stop=false;
            for (int i = 0; i < NB_ARMES; ++i) {
                if (!stop) {
                    Bouton bouton(105 + 175 * i, 200, 240, 150, Color::Transparent);
                    choixCarte = bouton.Clic(i);
                    if (choixCarte!=ERREUR) {
                        stop = true;
                    }
                }
            }
            if (choixCarte != ERREUR) {
                accusation[Arme] = ListepropositionArme[choixCarte];
                etape++;
            }
        }
            break;
        case 2:{
            Bouton boutonChangement(420, 290, 110, 400, Color::Transparent);
            if (boutonChangement.Clic(0)!=ERREUR) {
                etape = boutonChangement.Clic(0);
            }
            Bouton boutonValide(1060, 290, 110, 400, Color::Transparent);
            if (boutonValide.Clic(0)!=ERREUR) {
               MontrerProposition=true;
            }
        }
            break;
    }
}

Carte *Proposition::getAccusation() {
    return accusation;
}
