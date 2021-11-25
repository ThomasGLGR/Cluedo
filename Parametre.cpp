#include "PointH/Parametre.h"

void Parametre::setmenuMemoire(int m) {
    if (m != 3 && m!=4) {
        menuMemoire = m;
    }
}

int Parametre::getmenuMemoire() {
    return menuMemoire;
}

void Parametre::sauvegarder(Joueur *joueur, int tour, int NbJoueur, Carte *enveloppe) {
    if (menuMemoire == 5 || menuMemoire == 6) {
        std::ofstream fichierTexte("../PointTXT/sauvegarde.txt");
        fichierTexte << NbJoueur << "," << tour << ","<< enveloppe[0].getNom() << ","<< enveloppe[1].getNom() << ","<<enveloppe[2].getNom()<<std::endl;
        for (int i = 0; i < NbJoueur; ++i) {joueur[i].sauvegarde(fichierTexte);}
        fichierTexte.close();
    }
}


int ChargerInt(std::ifstream& fichierTexte){
    int I;
    std::string tempS;
    char tempC=';';
    while (tempC!=','){
        fichierTexte.get(tempC);
        tempS+=tempC;
    }
    I=atoi(tempS.c_str());
    return I;
}
std::string ChargerString(std::ifstream& fichierTexte){
    std::string S;
    char tempC=':';
    while (tempC!=',' && tempC!='\n'){
        fichierTexte.get(tempC);
        S+=tempC;
    }
    S.erase(S.size()-1);
    return S;
}

void Parametre::ChargerPartie(Joueur* joueur, int &tour, int &NbJoueur, Carte enveloppe[3],Carte carte[NB_CARTE]) {
    std::ifstream fichierTexte("../PointTXT/sauvegarde.txt");
    NbJoueur = ChargerInt(fichierTexte);
    tour = ChargerInt(fichierTexte);
    for (int i = 0; i < 3; ++i) {
        enveloppe[i].setCarteDepuisString(ChargerString(fichierTexte),carte);
    }
for (int i = 0; i < NbJoueur; ++i) {
    std::basic_string<char> Id = ChargerString(fichierTexte);
    std::basic_string<char> StringCarte = ChargerString(fichierTexte);
    int DeckSize = ChargerInt(fichierTexte);
    std::vector<std::basic_string<char>> ListeCarte;
    ListeCarte.reserve(DeckSize);
    for (int j = 0; j < DeckSize; ++j) {
        ListeCarte.push_back(ChargerString(fichierTexte));
    }
    int Hors_Jeu = ChargerInt(fichierTexte);
    int Xpion = ChargerInt(fichierTexte);
    int Ypion = ChargerInt(fichierTexte);
    int compteBlocNote=ChargerInt(fichierTexte);
    std::vector<int> ListeBlocNote;
    ListeBlocNote.reserve(compteBlocNote);
for (int i = 0; i < compteBlocNote; ++i) {
        ListeBlocNote.push_back(ChargerInt(fichierTexte));
    }
joueur[i].chargerPartie(Id,StringCarte,ListeCarte,Hors_Jeu,Xpion,Ypion,ListeBlocNote,carte);
char Bin;
fichierTexte.get(Bin);
}
fichierTexte.close();
}


