#include "PointH/Composant.h"


void De::InitialisationDe() {
    for (int i = 0; i < NB_FACES_DE; ++i) {
        textureFace[i].loadFromFile("../Image/Dice.png",IntRect(320*i,320,320,312));
        textureFace[i].setSmooth(true);
    }
}
void De::AfficherDe(RenderWindow &window,int x,int y,int l,int h){
    Vector2f targetSize(l, h);
    spriteFace[valeur-1].setTexture(textureFace[valeur-1]);
    /*stackOverflow*/spriteFace[valeur-1].setScale(targetSize.x / spriteFace[valeur-1].getLocalBounds().width,targetSize.y / spriteFace[valeur-1].getLocalBounds().height);
    spriteFace[valeur-1].setPosition(x,y);
    window.draw(spriteFace[valeur-1]);
}

int De::LancerDe() {
    valeur=rand()%NB_FACES_DE+1;
    return valeur;
}

void Pion::InitPion(Color C,int x0,int y0){
    colorPion=C;
    texturePion.loadFromFile("../Image/pawn.png");
    setCoordsPion(x0,y0);
}

void Pion::AfficherPion(RenderWindow& window) {
    spritePion.setTexture(texturePion);
    spritePion.setColor(colorPion);
    spritePion.setPosition(x,y);
    window.draw(spritePion);
}
void Pion::setCoordsPion(int x0, int y0) {
    x=x0;
    y=y0;
}

void VerifAutour(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int I, int J,int nbValeurDe){
    if(nbValeurDe<0){
        return;
    }
    plateau[I][J].setDeplacementPossible(true);
    if (I-1>ERREUR) {
        if (plateau[I-1][J].getTypedeCase()!=Vide) {
            plateau[I - 1][J].setDeplacementPossible(true);
            VerifAutour(plateau, I - 1, J, nbValeurDe - 1);
        }
    }
    if (I+1<NB_CASE_HAUTEUR) {
        if (plateau[I+1][J].getTypedeCase() != Vide) {
            plateau[I + 1][J].setDeplacementPossible(true);
            VerifAutour(plateau, I + 1, J, nbValeurDe - 1);
        }
    }
    if (J-1>ERREUR) {
        if (plateau[I][J-1].getTypedeCase() != Vide) {
            plateau[I][J - 1].setDeplacementPossible(true);
            VerifAutour(plateau, I, J - 1, nbValeurDe - 1);
        }
    }
    if (J+1<NB_CASE_LARGEUR) {
        if (plateau[I][J+1].getTypedeCase() != Vide) {
            plateau[I][J + 1].setDeplacementPossible(true);
            VerifAutour(plateau, I, J + 1, nbValeurDe - 1);
        }
    }
}

void Pion::DeplacementPion(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int ValeurDe) {
    int Ideplacement;
    int Jdeplacement;
    int CopieDe=ValeurDe;
    for (int i = 0; i < NB_CASE_HAUTEUR; ++i) {
        for (int j = 0; j < NB_CASE_LARGEUR; ++j) {
            plateau[i][j].setDeplacementPossible(false);
            if (plateau[i][j].getX() == x && plateau[i][j].getY() == y) {
                Ideplacement = i;
                Jdeplacement = j;
            }
        }
    }
    VerifAutour(plateau,Ideplacement,Jdeplacement,CopieDe-1);
}


void BlocNote::InitialisationBlocNote() {
    ifstream fichierTexte("../PointTXT/InitialisationNomCarte.txt");
    for (int i = 0; i < NB_CARTE; ++i) {
        getline(fichierTexte,nomDeCartes[i]);
        barre[i]=false;
        entoure[i]=false;
    }
    fichierTexte.close();
}

void BlocNote::BarrePremierJoueur(vector <Carte> Deck) {
    for (int j = 0; j < NB_CARTE; ++j) {
        for (int i = 0; i < Deck.size(); ++i) {
            if (Deck[i].getNom()==nomDeCartes[j]){
                barre[j]= true;
            }
        }
    }
}

void BlocNote::AfficherBlocNote(RenderWindow &window) {
    Texture textureLine;
    textureLine.loadFromFile("../Image/redline.png");
    Sprite spriteLine;
    Vector2f targetSizeL(300, 18);
    spriteLine.setTexture(textureLine);
    spriteLine.setScale(targetSizeL.x / spriteLine.getLocalBounds().width, targetSizeL.y / spriteLine.getLocalBounds().height);

    Texture textureCircle;
    textureCircle.loadFromFile("../Image/Circle.png");
    Sprite spriteCircle;
    Vector2f targetSizeC(300, 23);
    spriteCircle.setTexture(textureCircle);
    spriteCircle.setScale(targetSizeC.x / spriteLine.getLocalBounds().width, targetSizeC.y / spriteLine.getLocalBounds().height);

    for (int i = 0; i < NB_CARTE; ++i) {
        if (barre[i]){
            if (i<8){
                spriteLine.setPosition(DEBUT_BLOCNOTE_X,DEBUT_BLOCNOTE_Y+18*i);
            }else if (i<18){
                spriteLine.setPosition(DEBUT_BLOCNOTE_X,DEBUT_BLOCNOTE_Y+34+18*i);
            }else{
                spriteLine.setPosition(DEBUT_BLOCNOTE_X,DEBUT_BLOCNOTE_Y+68+18*i);
            }
            window.draw(spriteLine);
        }
    }

    for (int i = 0; i < NB_CARTE; ++i) {
        if (entoure[i]){
            if (i<8){
                spriteCircle.setPosition(DEBUT_BLOCNOTE_X,DEBUT_BLOCNOTE_Y+18*i);
            }else if (i<18){
                spriteCircle.setPosition(DEBUT_BLOCNOTE_X,DEBUT_BLOCNOTE_Y+34+18*i);
            }else{
                spriteCircle.setPosition(DEBUT_BLOCNOTE_X,DEBUT_BLOCNOTE_Y+68+18*i);
            }
            window.draw(spriteCircle);
        }
    }
}

void BlocNote::ChangementIndiceBarre() {
    int temp = ERREUR;
    bool stop=false;
    for (int i = 0; i < NB_CARTE; ++i) {
        if (!stop) {
            if (i < NB_PERSO) {
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 18 * i, 18, 300, Color::Transparent);
                temp = bouton.Clic(i);
                if (temp!=ERREUR) {
                    barre[temp] = !barre[temp];
                    for (int j = 0; j < NB_PERSO; ++j) {
                        entoure[j]=false;
                    }
                    stop = true;
                }
            } else if (i < NB_PERSO+NB_ARMES) {
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 34 + 18 * i, 18, 300, Color::Transparent);
                temp = bouton.Clic(i);
                if (temp!=ERREUR) {
                    barre[temp] = !barre[temp];
                    for (int j = NB_PERSO; j < NB_PERSO+NB_ARMES; ++j) {
                        entoure[j]=false;
                    }
                    stop = true;
                }
            } else {
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 68 + 18 * i, 18, 300, Color::Transparent);
                temp = bouton.Clic(i);
                if (temp!=ERREUR) {
                    barre[temp] = !barre[temp];
                    for (int j = NB_PERSO+NB_ARMES; j < NB_CARTE; ++j) {
                        entoure[j]=false;
                    }
                    stop = true;
                }
            }
        }
    }
}

void BlocNote::ChangementIndiceEntoure() {
    int temp = ERREUR;
    bool stop=false;
    for (int i = 0; i < NB_CARTE; ++i) {
        if (!stop) {
            if (i < NB_PERSO) {
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 18 * i, 18, 300, Color::Transparent);
                temp = bouton.Clic(i);
                if (temp!=ERREUR) {
                    for (int j = 0; j < NB_PERSO; ++j) {
                        entoure[j]=false;
                        barre[j]=true;
                    }
                    barre[temp]=false;
                    entoure[temp] = !entoure[temp];
                    stop = true;
                }
            } else if (i < NB_PERSO+NB_ARMES) {
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 34 + 18 * i, 18, 300, Color::Transparent);
                temp = bouton.Clic(i);
                if (temp!=ERREUR) {
                    for (int j = NB_PERSO; j < NB_PERSO+NB_ARMES; ++j) {
                        entoure[j]=false;
                        barre[j]=true;
                    }
                    barre[temp]=false;
                    entoure[temp] = !entoure[temp];
                    stop = true;
                }
            } else {
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 68 + 18 * i, 18, 300, Color::Transparent);
                temp = bouton.Clic(i);
                if (temp!=ERREUR) {
                    for (int j = NB_PERSO+NB_ARMES; j < NB_CARTE; ++j) {
                        entoure[j]=false;
                        barre[j]=true;
                    }
                    barre[temp]=false;
                    entoure[temp] = !entoure[temp];
                    stop = true;
                }
            }
        }
    }
}



