#include "PointH/Composant.h"


void De::InitialisationDe() {
    for (int i = 0; i < NB_FACES_DE; ++i) {
        textureFace[i].loadFromFile("../Image/Dice.png",sf::IntRect(320*i,320,320,312));
        textureFace[i].setSmooth(true);
    }
}
void De::AfficherDe(sf::RenderWindow &window,int x,int y,int l,int h){
    sf::Sprite spriteFace;
    sf::Vector2f targetSize(l, h);
    spriteFace.setTexture(textureFace[valeur-1]);
    spriteFace.setScale(targetSize.x / spriteFace.getLocalBounds().width,targetSize.y / spriteFace.getLocalBounds().height);
    spriteFace.setPosition(x,y);
    window.draw(spriteFace);
}

void De::LancerDe(int& Somme) {
    if (PeutLancerDe) {
        valeur = rand() % NB_FACES_DE + 1;
        PeutLancerDe = false;
        Somme += valeur;
    }
}

bool De::getPeutLancerDe() {
    return PeutLancerDe;
}

void Pion::InitPion(sf::Color C,int x0,int y0){
    colorPion=C;
    texturePion.loadFromFile("../Image/pawn.png");
    setCoordsPion(x0,y0);
}

void Pion::AfficherPion(sf::RenderWindow& window) {
    spritePion.setTexture(texturePion);
    spritePion.setColor(colorPion);
    spritePion.setPosition(x,y);
    window.draw(spritePion);
}
void Pion::setCoordsPion(int x0, int y0) {
    x=x0;
    y=y0;
}

void ReturnPorte(int i1,int j1,int i2,int j2,int i3,int j3,std::vector<int>* TabPorteI,std::vector<int>* TabPorteJ){
    if (i1==i2 && j1==j2){
        TabPorteI->push_back({i3});
        TabPorteJ->push_back({j3});
    }
    if (i1==i3 && j1==j3){
        TabPorteI->push_back({i2});
        TabPorteJ->push_back({j2});
    }
}

void VerifPorte(int i, int j,std::vector<int>* TabPorteI,std::vector<int>* TabPorteJ){
    ReturnPorte(i,j,22,15,23,13,TabPorteI,TabPorteJ);
    ReturnPorte(i,j,7,1,13,4,TabPorteI,TabPorteJ);
    ReturnPorte(i,j,8,8,8,11,TabPorteI,TabPorteJ);
    ReturnPorte(i,j,8,8,17,8,TabPorteI,TabPorteJ);
    ReturnPorte(i,j,8,8,17,11,TabPorteI,TabPorteJ);
    ReturnPorte(i,j,8,11,17,8,TabPorteI,TabPorteJ);
    ReturnPorte(i,j,8,11,17,11,TabPorteI,TabPorteJ);
    ReturnPorte(i,j,17,8,17,11,TabPorteI,TabPorteJ);
}

void returnRaccoucis(int i1,int j1,int i2,int j2,int i3,int j3,Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR]){
    if (i1==i2 && j1==j2){
        plateau[i3][j3].setDeplacementPossible(true);
    }
    if (i1==i3 && j1==j3){
        plateau[i2][j2].setDeplacementPossible(true);
    }
}

void VerifRacourcis(int i,int j,Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR])
{
returnRaccoucis(i,j,3,7,22,15,plateau);
returnRaccoucis(i,j,3,7,23,13,plateau);
returnRaccoucis(i,j,4,15,24,6,plateau);
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

void Pion::DeplacementPion(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int ValeurDe,bool verif) {

    int CopieDe=ValeurDe;
    std::vector<int> TabPorteI,TabPorteJ;
    for (int i = 0; i < NB_CASE_HAUTEUR; ++i) {
        for (int j = 0; j < NB_CASE_LARGEUR; ++j) {
            if (plateau[i][j].getX() == x && plateau[i][j].getY() == y) {
                VerifAutour(plateau,i,j,CopieDe-1);
                if  (plateau[i][j].getTypedeCase()==1) {
                    VerifPorte(i, j, &TabPorteI, &TabPorteJ);
                    VerifRacourcis(i, j, plateau);
                    for (int k = 0; k < TabPorteI.size(); ++k) {
                        VerifAutour(plateau, TabPorteI[k], TabPorteJ[k], CopieDe - 1);
                    }
                }
            }
        }
    }
}

void Pion::sauvegardePion(std::ofstream& fichierTexte){
    fichierTexte<<x<<","<<y<<",";
}

void BlocNote::setBarre(bool A,int i) {
    barre[i]=A;
}

void De::setLancerDe(bool A) {
PeutLancerDe=A;
}


void BlocNote::InitialisationBlocNote() {
    std::ifstream fichierTexte("../PointTXT/InitialisationNomCarte.txt");
    for (int i = 0; i < NB_CARTE; ++i) {
        barre[i]=false;
        entoure[i]=false;
        getline(fichierTexte,nomDeCartes[i]);
    }
    fichierTexte.close();
}

void BlocNote::BarrePremierJoueur(std::vector <Carte> Deck) {
    for (int j = 0; j < NB_CARTE; ++j) {
        for (int i = 0; i < Deck.size(); ++i) {
            if (Deck[i].getNom()==nomDeCartes[j]){
                barre[j]= true;
            }
        }
    }
}

void BlocNote::AfficherBlocNote(sf::RenderWindow &window) {
    sf::Texture textureLine;
    textureLine.loadFromFile("../Image/redline.png");
    sf::Sprite spriteLine;
    sf::Vector2f targetSizeL(300, 18);
    spriteLine.setTexture(textureLine);
    spriteLine.setScale(targetSizeL.x / spriteLine.getLocalBounds().width, targetSizeL.y / spriteLine.getLocalBounds().height);

    sf::Texture textureCircle;
    textureCircle.loadFromFile("../Image/Circle.png");
    sf::Sprite spriteCircle;
    sf::Vector2f targetSizeC(300, 23);
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
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 18 * i, 18, 300,sf::Color::Transparent);
                temp = bouton.Clic(i);
                if (temp!=ERREUR) {
                    barre[temp] = !barre[temp];
                    for (int j = 0; j < NB_PERSO; ++j) {
                        entoure[j]=false;
                    }
                    stop = true;
                }
            } else if (i < NB_PERSO+NB_ARMES) {
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 34 + 18 * i, 18, 300,sf::Color::Transparent);
                temp = bouton.Clic(i);
                if (temp!=ERREUR) {
                    barre[temp] = !barre[temp];
                    for (int j = NB_PERSO; j < NB_PERSO+NB_ARMES; ++j) {
                        entoure[j]=false;
                    }
                    stop = true;
                }
            } else {
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 68 + 18 * i, 18, 300,sf::Color::Transparent);
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
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 18 * i, 18, 300,sf::Color::Transparent);
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
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 34 + 18 * i, 18, 300,sf::Color::Transparent);
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
                Bouton bouton(DEBUT_BLOCNOTE_X, DEBUT_BLOCNOTE_Y + 68 + 18 * i, 18, 300,sf::Color::Transparent);
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


void BlocNote::clear() {
    for (int i = 0; i < NB_CARTE; ++i) {
        barre[i]=false;
        entoure[i]= false;
    }
}

void BlocNote::sauvegardeBlocNote(std::ofstream &fichierTexte) {
    int compte=0;
    for (int i = 0; i < NB_CARTE; ++i) {
        if  (barre[i]){
            compte++;
        }
    }
    fichierTexte<<compte<<",";
    for (int i = 0; i < NB_CARTE; ++i) {
        if  (barre[i]){
            fichierTexte<<i<<",";
        }
    }
}



