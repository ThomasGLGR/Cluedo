#include "Fonction.h"
#include "perso.h"


void ClavierTexte(short menu,perso* Perso,Event event){
    switch (menu) {
        case 2:
            for (int i = 0; i < 6; ++i) {
                if  (Perso[i].getenCourdeModif()){
                    Perso[i].ModifierTexteID(event);
                }
            }

            break;
    }
}

void Clavier(short menu,perso* Perso,Event event,RenderWindow& window){
    if (event.key.code == Keyboard::Escape) {
        window.close();
    }
    switch (menu) {
        case 2:
            if (event.key.code == 59){
                for (int i = 0; i < 6; ++i) {
                    if (Perso[i].getenCourdeModif()) {
                        Perso[i].SupprimerTexteID();
                    }
                }
            }
            break;
    }
}