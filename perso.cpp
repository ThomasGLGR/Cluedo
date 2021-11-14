#include "perso.h"

void perso::choixPerso(cartePossible* choixJoueurCarte,int start){
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

void perso::LibererPerso(cartePossible* choixJoueurCarte){
    if (memoire!=-1) {
        choixJoueurCarte[memoire].changement();
    }
}
int perso::getMemoire() {
    return memoire;
}
carte perso::getAvatar() {
    return avatar;
}
void perso::setAvatar(carte C) {
    avatar=C;
}
void perso::InitPerso() {
    joueurJoue=true;
}
void perso::SuppPerso() {
    joueurJoue=false;
}
bool perso::getjoueurJoue() {
    return joueurJoue;
}
bool perso::getAfficherIdentifiant(){
    return AfficherIdentifiant;
}
void perso::AfficheID(){
    AfficherIdentifiant =true;
}
void perso::setEcritureMDP(bool A){
    ecritureMDP=A;
}
bool perso::getEcritureMDP() {
    return ecritureMDP;
}
string perso::getID(){
    return identifiant;
}
string perso::getMDP(){
    return mdp;
}
void perso::ModifierTexteID(Event event){
    if(event.text.unicode!=8) {
        if (!ecritureMDP) {
            if (identifiant.size() <17 ) {
                identifiant += event.text.unicode;
            }
        } else {
            if (mdp.size() < 17) {
                mdp += event.text.unicode;
            }
        }
    }
}
void perso::SupprimerTexteID() {
    if (!ecritureMDP){
        if (!identifiant.empty()) {
            identifiant.erase(identifiant.size()-1);
        }
    }else{
        if (!mdp.empty()) {
            mdp.erase(mdp.size()-1);
        }
    }
}

bool perso::getenCourdeModif(){
    return enCourdeModif;
}
void perso::setenCourdeModif(bool A){
    enCourdeModif=A;
}

void InitialisationJoueur(perso& Perso,cartePossible* choixJoueurCarte){
    Perso.InitPerso();
    Perso.choixPerso(choixJoueurCarte,0);
}

void SupprimerJoueur(perso& Perso,cartePossible* choixJoueurCarte){
    Perso.SuppPerso();
    Perso.LibererPerso(choixJoueurCarte);
}

void ChangementPerso(perso& Perso,cartePossible* choixJoueurCarte){
    int a=Perso.getMemoire();
    Perso.choixPerso(choixJoueurCarte,a);
    choixJoueurCarte[a].changement();
}

void perso::EcrireNom(RenderWindow &window, int t, string nomPerso,int x,int y) {
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
void perso::EcrireID(RenderWindow &window, int t, string Nom,int x,int y){
    sf::Font font;
    font.loadFromFile("../font/Lato-Regular.ttf");
    sf::Text text;
    text.setFont(font);
    if (Nom==mdp){
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
short perso::getnouveauOuAncienCompte() {
    return nouveauOuAncienCompte;
}
void perso::setnouveauOuAncienCompte(short A) {
    nouveauOuAncienCompte=A;
}
void AjouterPerso(perso& Perso){
    Perso.AfficheID();
}