#include "PointH/Joueur.h"

#include <utility>

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


void Joueur::ModifierTexteID(sf::Event event){
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

void Joueur::EcrireNom(sf::RenderWindow &window, int t, std::string nomPerso, int x, int y,sf::Color C) {
    sf::Font font;
    font.loadFromFile("../font/Lato-Regular.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(nomPerso);
    text.setCharacterSize(t);
    text.setFillColor(C);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width/2,textRect.height/2);
    text.setPosition(x,y);
    window.draw(text);
}
void Joueur::EcrireID(sf::RenderWindow &window, int t, std::string Nom, int x, int y, bool protection){
    sf::Font font;
    font.loadFromFile("../font/Lato-Regular.ttf");
    sf::Text text;
    text.setFont(font);
    if (protection){
        std::string temp;
        for (int i = 0; i < mdp.size(); ++i) {
            temp += "*";
        }
        text.setString(temp);
    }else {
        text.setString(Nom);
    }
    text.setCharacterSize(t);
    text.setFillColor(ROUGE_MENU);
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
    if  (joueurJoue && etatInscription==Nouveau && !identifiant.empty()) {
        std::ofstream fichierTexte("../PointTXT/Identifiant.txt", std::ios::app);
        fichierTexte << identifiant << "," << mdp << ",0,0," << std::endl;
        etatInscription = Pret;
        AfficherIdentifiant = false;
        fichierTexte.close();
    }
}
void Joueur::VerifierJoueurExistant() {
    if  (joueurJoue && etatInscription==Connexion) {
        std::ifstream fichierTexte("../PointTXT/Identifiant.txt");
        int compteur = 0;
        std::string temp = "Temp";
        while (getline(fichierTexte, temp)) {
            compteur++;
        }
        fichierTexte.clear();
        fichierTexte.seekg(0, std::ios::beg);
        std::string listeID[compteur][4];
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

void Joueur::AffichagePictogramme(sf::RenderWindow& window,int i) {
    if (joueurJoue) {
         EcrireNom(window, 28,avatar.getNom(), 320 * i + 160, 795,avatar.getRGB());
        if (etatInscription == 3) {
            std::string temp = identifiant;
            temp += " WR: ";
            temp += std::to_string(WinRate());
            temp += "%";
            EcrireNom(window, 28, temp, 320 * i + 160, 260,avatar.getRGB());
        } else {
            sf::Texture texture;
            texture.loadFromFile("../Image/Pictogramme.png");
            sf::Sprite sprite[2];
            for (int j = 0; j < 2; ++j) {
                sprite[j].setTexture(texture);
                sprite[j].setTextureRect(sf::IntRect(144 * j, 0, 144, 76));
                if (etatInscription != 1 + j) {
                    sprite[j].setColor(sf::Color(255, 255, 255, 108));
                }
                sprite[j].setPosition(320 * i + 150 * j + 20, 220);
                window.draw(sprite[j]);
            }
        }
    }
}
void Joueur::AffichageCroix(sf::RenderWindow &window, int i) {
        if (!joueurJoue) {
            //Bouton +
            sf::RectangleShape rectanglePlus1(sf::Vector2f(6, 40));
            rectanglePlus1.setFillColor(ROUGE_MENU);
            rectanglePlus1.setPosition(320 * i + 157, 520);
            window.draw(rectanglePlus1);
            sf:: RectangleShape rectanglePlus2(sf::Vector2f(40, 6));
            rectanglePlus2.setFillColor(ROUGE_MENU);
            rectanglePlus2.setPosition(320 * i + 140, 537);
            window.draw(rectanglePlus2);
        } else {
            if (i > 1) {
                //Bouton -
                sf::RectangleShape rectangleCroix1(sf::Vector2f(4, 25));
                rectangleCroix1.setFillColor(ROUGE_MENU);
                rectangleCroix1.setPosition(320 * i + 35, 792);
                rectangleCroix1.rotate(45);
                window.draw(rectangleCroix1);
                sf::RectangleShape rectangleCroix2(sf::Vector2f(4, 25));
                rectangleCroix2.setFillColor(ROUGE_MENU);
                rectangleCroix2.setPosition(320 * i + 18, 795);
                rectangleCroix2.rotate(-45);
                window.draw(rectangleCroix2);
            }
            //Bouton Suivant
            sf::RectangleShape rectangleSuivant(sf::Vector2f(4, 25));
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

void Joueur::AffichageAvatarMenu2(sf::RenderWindow &window, int i) {
    if (joueurJoue) {
        if (AfficherIdentifiant) {
            sf::Texture texture;
            texture.loadFromFile("../Image/Identifiant.png");
            sf::Sprite sprite;
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
void Joueur::AfficherCarteEnMainZoom(sf::RenderWindow &window,int x1,int y1, int x2, int y2,int i) {
    if (sf::Mouse::getPosition().x> x1 && sf::Mouse::getPosition().x< x2 && sf::Mouse::getPosition().y > y1 && sf::Mouse::getPosition().y < y2) {
        EcrireNom(window,25,Deck[i].getNom(),x1+50,y1-94,sf::Color::White);
        Deck[i].dessinerCarte(window,x1-30,y1-64,160,256);
    }
}
void Joueur::AfficherCarteEnMain(sf::RenderWindow& window) {

    for (int i = 0; i < Deck.size(); ++i) {
        int x1 = 300 / Deck.size() + ((700 - (2 * 300 / Deck.size())) / Deck.size()) * i;
        Deck[i].dessinerCarte(window, x1, 800, 100, 160);
    }
    for (int i = 0; i < Deck.size(); ++i) {
        if (Deck.size() > 7 && i != Deck.size() - 1) {
            AfficherCarteEnMainZoom(window, 300 / Deck.size() + ((700 - (2 * 300 / Deck.size())) / Deck.size()) * i,
                                    800, 300 / Deck.size() + ((700 - (2 * 300 / Deck.size())) / Deck.size()) * (i + 1),
                                    800 + 160, i);

    }else{
        AfficherCarteEnMainZoom(window, 300 / Deck.size() + ((700 - (2 * 300 / Deck.size())) / Deck.size()) * i, 800,
                                300 / Deck.size() + ((700 - (2 * 300 / Deck.size())) / Deck.size()) * i + 100,
                                800 + 160, i);
    }
}
}

void Joueur::setPion(int x0,int y0) {
    pion.InitPion(avatar.getRGB(),x0,y0);
}

Pion Joueur::getPion() {
    return pion;
}

void Joueur::BarrePremierCarte() {
blocnote.BarrePremierJoueur(Deck);
}

BlocNote Joueur::getBlocnote() {
    return blocnote;
}

void Joueur::changementBlocNoteBarre() {
    blocnote.ChangementIndiceBarre();
}
void Joueur::changementBlocNoteEntoure() {
    blocnote.ChangementIndiceEntoure();
}

void Joueur::AfficherJoueurEnCours(sf::RenderWindow &window, int x, int y) {
    avatar.dessinerCarte(window, x, y, 100, 160);
    EcrireNom(window, 23, identifiant, x + 50, y - 30, avatar.getRGB());
    if  (HorsJeu){
        sf::RectangleShape rectangle(sf::Vector2f(100, 160));
        rectangle.setFillColor(sf::Color(255,0,0,130));
        rectangle.setPosition(x, y);
        window.draw(rectangle);
    }
}

void Joueur::AfficherFlecheJoueurEnCours(sf::RenderWindow &window,int x,int y) {
    sf::Texture texture;
    texture.loadFromFile("../Image/fleche.png");
    sf::Sprite sprite;
    sf::Vector2f targetSize(65, 48);
    sprite.setTexture(texture);
    sprite.setScale(targetSize.x / sprite.getLocalBounds().width,targetSize.y / sprite.getLocalBounds().height);
    sprite.setColor(avatar.getRGB());
    sprite.setPosition(x,y);
    window.draw(sprite);
}

void Joueur::VerificationProposition(Carte *proposition,bool& stop) {
    int a=rand()%Deck.size();
    for (int i = 0; i < Deck.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            if (Deck[a].getNom()==proposition[j].getNom()){
               propostionaAfficher=proposition[j];
               AfficherProposition= true;
               stop=true;
            }
        }
        a=(a+1)%Deck.size();
    }
}

void Joueur::AfficherCarteProposition(sf::RenderWindow &window,int x, int y) {
    if (AfficherProposition){
        propostionaAfficher.dessinerCarte(window,x,y,100,160);
        EcrireNom(window,23,propostionaAfficher.getNom(),x+50,y+170,sf::Color::White);
    }
}

void Joueur::SupprimerAfficherProposition() {
    AfficherProposition=false;
}

void Joueur::AfficherCroixProposition(sf::RenderWindow &window,int x,int y) {
    if (!AfficherProposition) {
        sf::Texture texture;
        texture.loadFromFile("../Image/RedCross.png");
        sf::Sprite sprite;
        sf::Vector2f targetSize(65, 65);
        sprite.setTexture(texture);
        sprite.setScale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);
        sprite.setPosition(x, y);
        window.draw(sprite);
    }
}
bool Joueur::getAfficherProposition() const{
    return AfficherProposition;
};

void Joueur::AfficheEcranVictoire(sf::RenderWindow &window) {
    avatar.dessinerCarte(window,815,300,227,367);


    sf::Sprite spriteEcrandeVictoire;
    sf::Texture textureEcrandeVictoire;
    sf::Image I;
    sf::Image I2;
    textureEcrandeVictoire.loadFromFile("../Image/Victoire.jpg");
    I=textureEcrandeVictoire.copyToImage();
    I2=textureEcrandeVictoire.copyToImage();
    for (int i = 0; i < textureEcrandeVictoire.getSize().x / 3.2; ++i) {
        for (int j = 0; j < textureEcrandeVictoire.getSize().y; ++j) {
            if (I.getPixel(i, j).b >  100 && I.getPixel(i, j).r<181) {
                I.setPixel(i, j, sf::Color(sf::Color(I.getPixel(i,j).r+74, I.getPixel(i,j).g/4,I.getPixel(i,j).b/3)));
                if (I.getPixel(i,j).r>190 && I.getPixel(i,j).b< 60 ){
                    I.setPixel(i,j,sf::Color(I2.getPixel(i,j).r,I2.getPixel(i,j).g,I2.getPixel(i,j).b));
                }
            }
        }
    }
    for (int i = 2 * textureEcrandeVictoire.getSize().x / 3; i < textureEcrandeVictoire.getSize().x; ++i) {
        for (int j = 0; j < textureEcrandeVictoire.getSize().y; ++j){
            if (I.getPixel(i, j).b >  100 && I.getPixel(i, j).r<181) {
                I.setPixel(i, j, sf::Color(sf::Color(I.getPixel(i,j).r+74, I.getPixel(i,j).g/4,I.getPixel(i,j).b/3)));
                if (I.getPixel(i,j).r>190 && I.getPixel(i,j).b< 55 ){
                    I.setPixel(i,j,sf::Color(I2.getPixel(i,j).r,I2.getPixel(i,j).g,I2.getPixel(i,j).b));
                }
            }
        }
    }
    for (int i = 0; i < textureEcrandeVictoire.getSize().x; ++i) {
        for (int j = 0; j < textureEcrandeVictoire.getSize().y; ++j){
            if (I.getPixel(i,j).b>235 && I.getPixel(i,j).g>235 && I.getPixel(i,j).r>235){
                I.setPixel(i,j,sf::Color(I2.getPixel(i,j).r,I2.getPixel(i,j).g,I2.getPixel(i,j).b,0));
            }
        }
    }
    textureEcrandeVictoire.update(I);
    textureEcrandeVictoire.setSmooth(true);
    spriteEcrandeVictoire.setTexture(textureEcrandeVictoire);
    spriteEcrandeVictoire.setPosition(610, 125);
    window.draw(spriteEcrandeVictoire);
}


void Joueur::setHorsJeu(bool A){
    HorsJeu=A;
}

bool Joueur::getHorsJeu() const {
    return HorsJeu;
}

void Joueur::clearJoueur() {
    Deck.clear();
    etatInscription=Debut;
    blocnote.clear();
    identifiant="\0";
    mdp="\0";
    memoire=ERREUR;
    joueurJoue = false;
    enCourdeModif=false;
    messageErreur=false;
    AfficherIdentifiant = false;
    ecritureMDP = false;
    AfficherProposition=false;
    HorsJeu=false;
}

void Joueur::AjouterUnePartie(bool A) {
    std::ifstream fichierTexteR("../PointTXT/Identifiant.txt");
    int compteur = 0;
    std::string temp = "Temp";
    while (getline(fichierTexteR, temp)) {
        compteur++;
    }
    fichierTexteR.clear();
    fichierTexteR.seekg(0, std::ios::beg);
    std::string listeID[compteur][4];
    char c = ';';
    for (int j = 0; j < compteur; ++j) {
        for (int i = 0; i < 4; ++i) {
            while (c != ',') {
                fichierTexteR.get(c);
                if (c != ',' && c != '\n') {
                    listeID[j][i] += c;
                }
            }
            c = ';';
        }
    }
    fichierTexteR.close();

    for (int i = 0; i < compteur; ++i) {
        if (identifiant == listeID[i][0]) {
            std::stringstream ss;
            if (A) {
                NbVictoires++;
                ss << NbVictoires;
                ss >> listeID[i][2];
            } else {
                NbJoues++;
                ss << NbJoues;
                ss >> listeID[i][3];
            }
        }
    }
    std::ofstream fichierTexteW("../PointTXT/Identifiant.txt");
    for (int i = 0; i < compteur; ++i) {
        fichierTexteW << listeID[i][0]<< "," << listeID[i][1] << "," << listeID[i][2]<<","<<listeID[i][3]<<","<<std::endl;
    }
}

void Joueur::sauvegarde(std::ofstream& fichierTexte) {
fichierTexte<<identifiant<<"," <<avatar.getNom()<<"," <<Deck.size()<<",";
    for (int i = 0; i < Deck.size(); ++i) {
        fichierTexte << Deck[i].getNom()<<",";
    }
    fichierTexte<<HorsJeu<<",";
    pion.sauvegardePion(fichierTexte);
    blocnote.sauvegardeBlocNote(fichierTexte);
    fichierTexte<<std::endl;
}

void Joueur::chargerPartie(std::basic_string<char> Id, std::basic_string<char> StringCarte, std::vector<std::basic_string<char>> ListeCarte,
                           bool Hors_Jeu, int Xpion, int Ypion, std::vector<int> ListeBlocNote,Carte carte[NB_CARTE]) {
    identifiant=move(Id);
    avatar.setCarteDepuisString(move(StringCarte),carte);
    for (int i = 0; i < ListeCarte.size(); ++i) {
        Deck.emplace_back();
        Deck[i].setCarteDepuisString(ListeCarte[i],carte);
    }
    HorsJeu=Hors_Jeu;
    setPion(Xpion,Ypion);
    for (int i = 0; i < ListeBlocNote.size(); ++i) {
        blocnote.setBarre(true,ListeBlocNote[i]);
    }
}


