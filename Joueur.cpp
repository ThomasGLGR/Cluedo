#include "PointH/Joueur.h"

void Joueur::choixPerso(cartePossible* choixJoueurCarte, int start){
    bool stop=false;
    for (int i = start; i <NB_PERSO ; ++i) {
        if (!choixJoueurCarte[i].getUtilise() && !stop){
            choixJoueurCarte[i].changement();
            avatar = choixJoueurCarte[i].getCarte();
            memoire = i;
            stop = true;
        }
    }
    for (int i = 0; i < NB_PERSO; ++i) {
         if (!choixJoueurCarte[i].getUtilise() && !stop){
             choixJoueurCarte[i].changement();
            avatar = choixJoueurCarte[i].getCarte();
            memoire = i;
            stop = true;
         }
    }
}

int Joueur::getMemoire()const {
    return memoire;
}
carte Joueur::getAvatar()const{
    return avatar;
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

string Joueur::getID()const{
    return identifiant;
}
string Joueur::getMDP()const{
    return mdp;
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

void Joueur::EcrireNom(RenderWindow &window, int t, string nomPerso, int x, int y) {
    sf::Font font;
    font.loadFromFile("../font/Lato-Regular.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(nomPerso);
    text.setCharacterSize(t);
    text.setFillColor(avatar.getRGB());
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width/2,textRect.height/2);
    text.setPosition(x,y);
    window.draw(text);
}
void Joueur::EcrireID(RenderWindow &window, int t, string Nom, int x, int y, bool protection){
    sf::Font font;
    font.loadFromFile("../font/Lato-Regular.ttf");
    sf::Text text;
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

bool Joueur::getmessageErreur()const{
    return messageErreur;
}