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
        ofstream fichierTexte("../PointTXT/sauvegarde.txt");
        fichierTexte << NbJoueur << "," << tour << ",";
        for (int i = 0; i < 3; ++i) {
            fichierTexte << enveloppe[i].getNom() << ",";
        }

        fichierTexte << endl;

        for (int i = 0; i < NbJoueur; ++i) {
            joueur[i].sauvegarde(fichierTexte);
        }

        fichierTexte.close();
    }
}


int ChargerInt(ifstream& fichierTexte){
    int I;
    string tempS;
    char tempC=';';
    while (tempC!=','){
        fichierTexte.get(tempC);
        tempS+=tempC;
    }
    I=atoi(tempS.c_str());
    return I;
}
string ChargerString(ifstream& fichierTexte){
    string S;
    char tempC=':';
    while (tempC!=',' && tempC!='\n'){
        fichierTexte.get(tempC);
        S+=tempC;
    }
    S.erase(S.size()-1);
    return S;
}

void Parametre::ChargerPartie(Joueur* joueur, int &tour, int &NbJoueur, Carte enveloppe[3]) {
    ifstream fichierTexte("../PointTXT/sauvegarde.txt");
    tour = ChargerInt(fichierTexte);
    NbJoueur = ChargerInt(fichierTexte);
    for (int i = 0; i < 3; ++i) {
        enveloppe[i].setCarteDepuisString(ChargerString(fichierTexte));
    }
for (int i = 0; i < NbJoueur; ++i) {
    basic_string<char> Id = ChargerString(fichierTexte);
    basic_string<char> StringCarte = ChargerString(fichierTexte);
    int DeckSize = ChargerInt(fichierTexte);
    vector<basic_string<char>> ListeCarte;
    ListeCarte.reserve(DeckSize);
    for (int j = 0; j < DeckSize; ++j) {
        ListeCarte.push_back(ChargerString(fichierTexte));
    }
    int Hors_Jeu = ChargerInt(fichierTexte);
    int Xpion = ChargerInt(fichierTexte);
    int Ypion = ChargerInt(fichierTexte);
    vector<basic_string<char>> ListeBlocNote;
    char tempC;
    fichierTexte.get(tempC);
    while (tempC != '\n') {
        ListeBlocNote.push_back(tempC + ChargerString(fichierTexte));
        fichierTexte.get(tempC);
    }
    joueur[i].chargerPartie(Id,StringCarte,ListeCarte,Hors_Jeu,Xpion,Ypion,ListeBlocNote);
}

    fichierTexte.close();
}


