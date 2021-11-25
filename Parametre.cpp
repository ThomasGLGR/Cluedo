#include "PointH/Parametre.h"

void Parametre::setmenuMemoire(int m) {
    if (m != 8 && m!=4) {
        menuMemoire = m;
    }
}

int Parametre::getmenuMemoire() {
    return menuMemoire;
}