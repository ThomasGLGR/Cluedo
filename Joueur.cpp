#include "PointH/Joueur.h"

void Joueur::choixPerso(cartePossible* choixJoueurCarte, int start){
    bool stop=false;
    for (int i = start; i <NB_PERSO ; ++i) {
        if (!choixJoueurCarte[i].getUtilise() && !stop){
            choixJoueurCarte[i].changement();
            avatar=choixJoueurCarte[i].getCarte();
            memoire = i;
            stop = true;
        }
    }
    for (int i = 0; i < NB_PERSO; ++i) {
         if (!choixJoueurCarte[i].getUtilise() && !stop){
             choixJoueurCarte[i].changement();
             avatar=choixJoueurCarte[i].getCarte();
            memoire = i;
            stop = true;
         }
    }
}

int Joueur::getMemoire()const {
    return memoire;
}


bool Joueur::getjoueurJoue()const{
    return joueurJoue;
}
bool Joueur::getAfficherIdentifiant()const{
    return AfficherIdentifiant;
}
void Joueur::AfficheID(){
    if (joueurJoue) {
        AfficherIdentifiant = true;
    }
}
void Joueur::setEcritureMDP(bool A){
    if (joueurJoue) {
        ecritureMDP = A;
    }
}


void Joueur::ModifierTexteID(Event event){
    if  (enCourdeModif) {
        if (event.text.unicode != 8 && event.text.unicode != 44 &&
            (etatInscription == Nouveau || etatInscription == Connexion)) {
            if (!ecritureMDP) {
                if (identifiant.size() < 14) {
                    identifiant += event.text.unicode;
                }
            } else {
                if (mdp.size() < 14) {
                    mdp += event.text.unicode;
                }
            }
        }
    }
}
void Joueur::SupprimerTexteID() {
    if  (enCourdeModif) {
        if (!ecritureMDP) {
            if (!identifiant.empty()) {
                identifiant.erase(identifiant.size() - 1);
            }
        } else {
            if (!mdp.empty()) {
                mdp.erase(mdp.size() - 1);
            }
        }
    }
}


void Joueur::setenCourdeModif(bool A){
    if (joueurJoue) {
        enCourdeModif = A;
    }
}

void Joueur::InitialisationJoueur(cartePossible* choixJoueurCarte){
    if  (!joueurJoue) {
        joueurJoue = true;
        choixPerso(choixJoueurCarte, 0);
        blocnote.InitialisationBlocNote();
    }
}

void Joueur::SupprimerJoueur(cartePossible* choixJoueurCarte){
    if  (joueurJoue) {
        joueurJoue = false;
        if (memoire != -1) {
            choixJoueurCarte[memoire].changement();
        }
    }
}

void Joueur::ChangementPerso(cartePossible* choixJoueurCarte){
    if (joueurJoue) {
        int a = getMemoire();
        choixPerso(choixJoueurCarte, a);
        choixJoueurCarte[a].changement();
    }
}

void Joueur::EcrireNom(RenderWindow &window, int t, string nomPerso, int x, int y,Color C) {
    Font font;
    font.loadFromFile("../font/Lato-Regular.ttf");
    Text text;
    text.setFont(font);
    text.setString(nomPerso);
    text.setCharacterSize(t);
    text.setFillColor(C);
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width/2,textRect.height/2);
    text.setPosition(x,y);
    window.draw(text);
}
void Joueur::EcrireID(RenderWindow &window, int t, string Nom, int x, int y, bool protection){
    Font font;
    font.loadFromFile("../font/Lato-Regular.ttf");
    Text text;
    text.setFont(font);
    if (protection){
        string temp;
        for (int i = 0; i < mdp.size(); ++i) {
            temp += "*";
        }
        text.setString(temp);
    }else {
        text.setString(Nom);
    }
    text.setCharacterSize(t);
    text.setFillColor(Color(238, 29, 33));
    text.setPosition(x,y);
    window.draw(text);
}
int Joueur::getEtatInscription() const{
    return etatInscription;
}
void Joueur::setetatInscription(int A) {
    etatInscription=A;
}
void Joueur::AjouterUnJoueur() {
    if  (joueurJoue && etatInscription==Nouveau) {
        ofstream fichierTexte("../PointTXT/Identifiant.txt", ios::app);
        fichierTexte << identifiant << "," << mdp << ",0,0," << endl;
        etatInscription = 3;
        AfficherIdentifiant = false;
        fichierTexte.close();
    }
}
void Joueur::VerifierJoueurExistant() {
    if  (joueurJoue && etatInscription==Connexion) {
        ifstream fichierTexte("../PointTXT/Identifiant.txt");
        int compteur = 0;
        string temp = "Temp";
        while (getline(fichierTexte, temp)) {
            compteur++;
        }
        fichierTexte.clear();
        fichierTexte.seekg(0, ios::beg);
        string listeID[compteur][4];
        char c = ';';
        for (int j = 0; j < compteur; ++j) {
            for (int i = 0; i < 4; ++i) {
                while (c != ',') {
                    fichierTexte.get(c);
                    if (c != ',' && c != '\n') {
                        listeID[j][i] += c;
                    }
                }
                c = ';';
            }
        }

        fichierTexte.close();
        int idValide = 0;
        for (int j = 0; j < compteur; ++j) {
            if (listeID[j][0] == identifiant && listeID[j][1] == mdp) {
                idValide = 1;
                NbVictoires = atoi(listeID[j][2].c_str());
                NbJoues = atoi(listeID[j][3].c_str());
            }
        }
        if (idValide == 1) {
            etatInscription = 3;
            AfficherIdentifiant = false;
        } else {
            messageErreur = true;
        }
    }
}
int Joueur::WinRate()const{
    if (NbJoues==0){
        return 0;
    }else{
        return NbVictoires*100/NbJoues;
    }
}

void Joueur::PiocherCarte(Carte carte) {
    Deck.push_back(carte);
}

void Joueur::AffichagePictogramme(RenderWindow& window,int i) {
    if (joueurJoue) {
         EcrireNom(window, 28,avatar.getNom(), 320 * i + 160, 795,avatar.getRGB());
        if (etatInscription == 3) {
            string temp = identifiant;
            temp += " WR: ";
            temp += to_string(WinRate());
            temp += "%";
            EcrireNom(window, 28, temp, 320 * i + 160, 260,avatar.getRGB());
        } else {
            Texture texture;
            texture.loadFromFile("../Image/Pictogramme.png");
            Sprite sprite[2];
            for (int j = 0; j < 2; ++j) {
                sprite[j].setTexture(texture);
                sprite[j].setTextureRect(IntRect(144 * j, 0, 144, 76));
                if (etatInscription != 1 + j) {
                    sprite[j].setColor(Color(255, 255, 255, 108));
                }
                sprite[j].setPosition(320 * i + 150 * j + 20, 220);
                window.draw(sprite[j]);
            }
        }
    }
}
void Joueur::AffichageCroix(RenderWindow &window, int i) {
        if (!joueurJoue) {
            //Bouton +
            RectangleShape rectanglePlus1(Vector2f(6, 40));
            rectanglePlus1.setFillColor(ROUGE_MENU);
            rectanglePlus1.setPosition(320 * i + 157, 520);
            window.draw(rectanglePlus1);
            RectangleShape rectanglePlus2(Vector2f(40, 6));
            rectanglePlus2.setFillColor(ROUGE_MENU);
            rectanglePlus2.setPosition(320 * i + 140, 537);
            window.draw(rectanglePlus2);
        } else {
            if (i > 1) {
                //Bouton -
                RectangleShape rectangleCroix1(Vector2f(4, 25));
                rectangleCroix1.setFillColor(ROUGE_MENU);
                rectangleCroix1.setPosition(320 * i + 35, 792);
                rectangleCroix1.rotate(45);
                window.draw(rectangleCroix1);
                RectangleShape rectangleCroix2(Vector2f(4, 25));
                rectangleCroix2.setFillColor(ROUGE_MENU);
                rectangleCroix2.setPosition(320 * i + 18, 795);
                rectangleCroix2.rotate(-45);
                window.draw(rectangleCroix2);
            }
            //Bouton Suivant
            RectangleShape rectangleSuivant(Vector2f(4, 25));
            rectangleSuivant.setFillColor(ROUGE_MENU);
            rectangleSuivant.setPosition(320 * i + 297, 800);
            rectangleSuivant.rotate(45);
            window.draw(rectangleSuivant);
            rectangleSuivant.rotate(90);
            rectangleSuivant.setPosition(320 * i + 300, 803);
            rectangleSuivant.setFillColor(ROUGE_MENU);
            window.draw(rectangleSuivant);
        }
    }

void Joueur::AffichageAvatarMenu2(RenderWindow &window, int i) {
    if (joueurJoue) {
        if (AfficherIdentifiant) {
            Texture texture;
            texture.loadFromFile("../Image/Identifiant.png");
            Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(320 * i + 16, 310);
            window.draw(sprite);
            EcrireID(window, 24, identifiant, 320 * i + 55, 420, false);
            EcrireID(window, 24, mdp, 320 * i + 55, 580, true);
            if (messageErreur) {
                EcrireID(window, 24, "Identifiant Inconnue", 320 * i + 53, 670, false);
            }
        } else {
            avatar.dessinerCarte(window, 320 * i + 16, 310, 288, 460);
        }
    }
}
void Joueur::AfficherCarteEnMainZoom(RenderWindow &window,int x1,int y1, int x2, int y2,int i) {
    if (Mouse::getPosition().x> x1 && Mouse::getPosition().x< x2 && Mouse::getPosition().y > y1 && Mouse::getPosition().y < y2) {
        EcrireNom(window,25,Deck[i].getNom(),x1+50,y1-94,Color::White);
        Deck[i].dessinerCarte(window,x1-30,y1-64,160,256);
    }
}
void Joueur::AfficherCarteEnMain(RenderWindow& window) {
    for (int i = 0; i < Deck.size(); ++i) {
        int x1 = 300 / Deck.size() + ((700 - (2 * 300 / Deck.size())) / Deck.size()) * i;
        Deck[i].dessinerCarte(window, x1, 750, 100, 160);
    }
    for (int i = 0; i < Deck.size(); ++i) {
        if (Deck.size() > 7 && i != Deck.size() - 1) {
            AfficherCarteEnMainZoom(window, 300 / Deck.size() + ((700 - (2 * 300 / Deck.size())) / Deck.size()) * i,
                                    750, 300 / Deck.size() + ((700 - (2 * 300 / Deck.size())) / Deck.size()) * (i + 1),
                                    750 + 160, i);

    }else{
        AfficherCarteEnMainZoom(window, 300 / Deck.size() + ((700 - (2 * 300 / Deck.size())) / Deck.size()) * i, 750,
                                300 / Deck.size() + ((700 - (2 * 300 / Deck.size())) / Deck.size()) * i + 100,
                                750 + 160, i);
    }
}
}

void Joueur::setPion(int x0,int y0) {
    pion.InitPion(avatar.getRGB(),x0,y0);
}
void Joueur::Afficherpion(RenderWindow &window) {
    pion.AfficherPion(window);
}

Pion Joueur::getPion() {
    return pion;
}

void Joueur::BarrePremierCarte() {
blocnote.BarrePremierJoueur(Deck);
}
