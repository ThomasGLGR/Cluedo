#include "PointH/Carte.h"

void carte::InitCarte(ifstream& fichierTexte, int Type, int x, int y, int l, int L){
    getline(fichierTexte,nomCarte);
    typeCarte=Type;
    textureCarte.loadFromFile("../Image/ListeCarte.jpg", sf::IntRect(x, y, l, L));
    spriteCarte.setTexture(textureCarte);
}
void carte::Couleur(ifstream& fichierTexte){
    int R,G,B;
    fichierTexte >> R >> G >> B;
    RGBText=Color(R,G,B);
}

string carte::getNom(){
    return nomCarte;
}

carte cartePossible::getCarte(){
    return Carte;
}
Color carte::getRGB() {
    return RGBText;
}

void InitialisationCarte(carte Carte[NB_CARTE],cartePossible choixJoueurCarte[]){
    ifstream fichierTexte("../PointTXT/InitialisationNomCarte.txt");
    for (int i = 0; i < NB_CARTE; ++i) {
        if (i<8) {
            Carte[i].InitCarte(fichierTexte,Perso,i*LARGEUR_CARTE,0,LARGEUR_CARTE,HAUTEUR_CARTE);

        }else if(i<18){
            Carte[i].InitCarte(fichierTexte,Arme,(i-8)*LARGEUR_CARTE,HAUTEUR_CARTE,LARGEUR_CARTE,HAUTEUR_CARTE);

        }else{
            Carte[i].InitCarte(fichierTexte,Lieu,(i-18)*LARGEUR_CARTE,2*HAUTEUR_CARTE,LARGEUR_CARTE,HAUTEUR_CARTE);
        }
    }
    for (int i = 0; i < NB_PERSO; ++i) {
        Carte[i].Couleur(fichierTexte);
        choixJoueurCarte[i].setCarte(Carte[i]);
    }
    fichierTexte.close();
}

void cartePossible::changement() {
    utilise=!utilise;
}
bool cartePossible::getUtilise() {
    return utilise;
}
void cartePossible::setCarte(carte C){
    Carte=C;
}

void carte::dessinerCarte(RenderWindow &window, int x, int y, int l, int h) {
    sf::Vector2f targetSize(l, h);
    /*stackOverflaw */spriteCarte.setScale(targetSize.x / spriteCarte.getLocalBounds().width,targetSize.y / spriteCarte.getLocalBounds().height);
    spriteCarte.setPosition(x,y);
    window.draw(spriteCarte);
}

