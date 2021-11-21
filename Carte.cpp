#include "PointH/Carte.h"
#include <utility>

void Carte::InitCarte(ifstream& fichierTexte, int Type, int x, int y, int l, int L){
    getline(fichierTexte,nomCarte);
    typeCarte=Type;
    textureCarte.loadFromFile("../Image/ListeCarte.jpg", IntRect(x, y, l, L));
}
void Carte::Couleur(ifstream& fichierTexte){
    int R,G,B;
    fichierTexte >> R >> G >> B;
    RGBText=Color(R,G,B);
}

string Carte::getNom(){
    return nomCarte;
}

Carte::Carte() {}

Carte::Carte(Sprite spriteCarte0,const Texture& textureCarte0,string nomCarte0,int typeCarte0,Color RGBText0) {
    spriteCarte=move(spriteCarte0);
    textureCarte=textureCarte0;
    nomCarte=move(nomCarte0);
    typeCarte=typeCarte0;
    RGBText=RGBText0;
}

Sprite Carte::getSprite(){
    return spriteCarte;
}
Texture Carte::getTexture(){
    return textureCarte;
}
Carte cartePossible::getCarte(){
    Carte C(spriteCarte,textureCarte,nomCarte,typeCarte,RGBText);
    return C;
}
Color Carte::getRGB() {
    return RGBText;
}

void cartePossible::setCarte(Carte C){
    spriteCarte=C.getSprite();
    textureCarte=C.getTexture();
    nomCarte=C.getNom();
    RGBText=C.getRGB();
}


void InitialisationCarte(Carte carte[NB_CARTE], cartePossible choixJoueurCarte[]){
    ifstream fichierTexte("../PointTXT/InitialisationNomCarte.txt");
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
        choixJoueurCarte[i].setCarte(carte[i]);
    }
    fichierTexte.close();
}

void cartePossible::changement() {
    utilise=!utilise;
}
bool cartePossible::getUtilise() {
    return utilise;
}


void Carte::dessinerCarte(RenderWindow &window, int x, int y, int l, int h) {
    Vector2f targetSize(l, h);
    spriteCarte.setTexture(textureCarte);
    /*stackOverflaw*/spriteCarte.setScale(targetSize.x / spriteCarte.getLocalBounds().width,targetSize.y / spriteCarte.getLocalBounds().height);
    spriteCarte.setPosition(x,y);
    window.draw(spriteCarte);
}

void Carte::setCarte(Carte C){
    spriteCarte=C.spriteCarte;
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
