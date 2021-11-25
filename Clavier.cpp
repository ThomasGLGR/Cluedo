#include "PointH/AutresFonctions.h"

void ClavierTexte(int menu, Joueur* joueur, Event event) {
    for (int i = 0; i < 6; ++i) {
        if (menu == 2) {
            joueur[i].ModifierTexteID(event);
        }
    }
}
void Clavier(int& menu, Joueur* joueur, Event event, RenderWindow& window,bool& End,Parametre& parametre) {
    if (event.key.code == Keyboard::Escape) {
        parametre.setmenuMemoire(menu);
        menu=3;
    }
    if (event.key.code == 59 && menu==2) {
        for (int i = 0; i < 6; ++i) {
                joueur[i].SupprimerTexteID();
        }
    }
}