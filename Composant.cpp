#include "PointH/Composant.h"
#include "PointH/IncludeAndDefine.h"

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

void VerifAutour(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int I, int J){
   if (I-1>0){ plateau[I-1][J].setDeplacementPossible(true);}
   if (I+1<NB_CASE_HAUTEUR){ plateau[I+1][J].setDeplacementPossible(true);}
   if (J-1>0){ plateau[I][J-1].setDeplacementPossible(true);}
   if (J+1<NB_CASE_LARGEUR){ plateau[I][J+1].setDeplacementPossible(true);}
}

void Pion::DeplacementPion(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int ValeurDe) {
    int Ideplacement;
    int Jdeplacement;
    for (int i = 0; i < NB_CASE_HAUTEUR; ++i) {
        for (int j = 0; j < NB_CASE_LARGEUR; ++j) {
            plateau[i][j].setDeplacementPossible(false);
            if (plateau[i][j].getX() == x && plateau[i][j].getY() == y) {
                Ideplacement = i;
                Jdeplacement = j;
            }
        }
    }
    plateau[Ideplacement][Jdeplacement].setDeplacementPossible(true);
  for (int k = -ValeurDe; k < ValeurDe; ++k) {
      for (int i = -k; i < k + 1; ++i) {
          for (int j = -k; j < k + 1; ++j) {
              if (abs(i) + abs(j) == k) {
                  if (k != ValeurDe) {
                      if (plateau[Ideplacement + i][Jdeplacement + j].getDeplacementPossible()) {
                          VerifAutour(plateau, Ideplacement + i, Jdeplacement + j);
                      }
                  } else {
                      plateau[Ideplacement + i][Jdeplacement + j].setDeplacementPossible(true);
                  }
              }
          }
      }
  }
}


void BlocNote::InitialisationBlocNote() {
    ifstream fichierTexte("../PointTXT/InitialisationNomCarte.txt");
    for (int i = 0; i < NB_CARTE; ++i) {
        getline(fichierTexte,nomDeCartes[i]);
        barre[i]=false;
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
    Texture textureredLine;
    textureredLine.loadFromFile("../Image/redline.png");
    Sprite spriteredLine;
    Vector2f targetSize(300, 18);
    spriteredLine.setTexture(textureredLine);
    spriteredLine.setScale(targetSize.x / spriteredLine.getLocalBounds().width,targetSize.y / spriteredLine.getLocalBounds().height);
    for (int i = 0; i < NB_CARTE; ++i) {
        if (barre[i]){
            if (i<8){
                spriteredLine.setPosition(DEBUT_BLOCNOTE_X,DEBUT_BLOCNOTE_Y+18*i);
            }else if (i<18){
                spriteredLine.setPosition(DEBUT_BLOCNOTE_X,DEBUT_BLOCNOTE_Y+34+18*i);
            }else{
                spriteredLine.setPosition(DEBUT_BLOCNOTE_X,DEBUT_BLOCNOTE_Y+68+18*i);

            }
            window.draw(spriteredLine);
        }
    }
}

void BlocNote::ChangementIndice() {
    int temp = ERREUR;
    bool stop=false;
    for (int i = 0; i < NB_CARTE; ++i) {
        if (!stop) {
            if (i < 8) {
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 18 * i, 18, 300, Color::Transparent);
                temp = bouton.Clic(i);
                if (temp!=ERREUR) {
                    barre[temp] = !barre[temp];
                    stop = true;
                }
            } else if (i < 18) {
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 34 + 18 * i, 18, 300, Color::Transparent);
                temp = bouton.Clic(i);
                if (temp!=ERREUR) {
                    barre[temp] = !barre[temp];
                    stop = true;
                }
            } else {
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 68 + 18 * i, 18, 300, Color::Transparent);
                temp = bouton.Clic(i);
                if (temp!=ERREUR) {
                    barre[temp] = !barre[temp];
                    stop = true;
                }
            }
        }
    }
}
