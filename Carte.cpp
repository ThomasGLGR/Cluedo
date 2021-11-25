#include "PointH/Carte.h"

#include <utility>

void Carte::InitCarte(std::ifstream& fichierTexte, int Type, int x, int y, int l, int L){
    getline(fichierTexte,nomCarte);
    typeCarte=Type;
    textureCarte.loadFromFile("../Image/ListeCarte.jpg", sf::IntRect(x, y, l, L));
}
void Carte::Couleur(std::ifstream& fichierTexte){
    int R,G,B;
    fichierTexte >> R >> G >> B;
    RGBText=sf::Color(R,G,B);
}

std::string Carte::getNom(){
    return nomCarte;
}

Carte::Carte() {}

Carte::Carte(const sf::Texture& textureCarte0,std::string nomCarte0,int typeCarte0,sf::Color RGBText0) {
    textureCarte=textureCarte0;
    nomCarte=move(nomCarte0);
    typeCarte=typeCarte0;
    RGBText=RGBText0;
}


sf::Texture Carte::getTexture(){
    return textureCarte;
}
Carte cartePossible::getCarte(){

    Carte C(textureCarte,nomCarte,typeCarte,RGBText);
    return C;
}
sf::Color Carte::getRGB() {
    return RGBText;
}

void cartePossible::setCarte(Carte C){
    textureCarte=C.getTexture();
    nomCarte=C.getNom();
    RGBText=C.getRGB();
    utilise=false;
}


void InitialisationCarte(Carte carte[NB_CARTE]){
    std::ifstream fichierTexte("../PointTXT/InitialisationNomCarte.txt");
    for (int i = 0; i < NB_CARTE; ++i) {
        if (i<NB_PERSO) {
            carte[i].InitCarte(fichierTexte,Perso,i*LARGEUR_CARTE,0,LARGEUR_CARTE,HAUTEUR_CARTE);
        }else if(i<18){
            carte[i].InitCarte(fichierTexte,Arme,(i-8)*LARGEUR_CARTE,HAUTEUR_CARTE,LARGEUR_CARTE,HAUTEUR_CARTE);
        }else{
            carte[i].InitCarte(fichierTexte,Lieu,(i-18)*LARGEUR_CARTE,2*HAUTEUR_CARTE,LARGEUR_CARTE,HAUTEUR_CARTE);
        }
    }

    for (int i = 0; i < NB_PERSO; ++i) {
        carte[i].Couleur(fichierTexte);
    }
    fichierTexte.close();
}

void cartePossible::changement() {
    utilise=!utilise;
}
bool cartePossible::getUtilise() {
    return utilise;
}


void Carte::dessinerCarte(sf::RenderWindow &window, int x, int y, int l, int h) {
    sf::Sprite spriteCarte;
    sf::Vector2f targetSize(l, h);
    spriteCarte.setTexture(textureCarte);
    spriteCarte.setScale(targetSize.x / spriteCarte.getLocalBounds().width,targetSize.y / spriteCarte.getLocalBounds().height);
    spriteCarte.setPosition(x,y);
    window.draw(spriteCarte);
}

void Carte::setCarte(Carte C){
    textureCarte=C.textureCarte;
    nomCarte=C.nomCarte;
    RGBText=C.RGBText;
    typeCarte=C.typeCarte;
};

void Carte::RemplirEnveloppe(Carte* carte,int type){
    bool stop=false;
    for (int i = 0; i < NB_CARTE; ++i) {
            if (carte[i].typeCarte==type && !stop){
              setCarte(carte[i]);
              carte[i].setCarte(carte[NB_CARTE-type-1]);
              stop=true;
        }
    }
}

void Carte::setCarteDepuisString(std::string S,Carte carte[NB_CARTE]) {
nomCarte=move(S);
    for (int i = 0; i < NB_CARTE; ++i) {
        if (nomCarte==carte[i].getNom()){
            setCarte(carte[i]);
        }
    }
}

void InitialisationCartePossible(Carte carte[NB_CARTE], cartePossible choixJoueurCarte[]){
    for (int i = 0; i < NB_PERSO; ++i) {
        choixJoueurCarte[i].setCarte(carte[i]);
    }
}
