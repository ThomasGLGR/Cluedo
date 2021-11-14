#include "Fonction.h"
#include "bouton.h"
#include "perso.h"

void ClicGauche(short& menu,perso* Perso,cartePossible choixJoueurCarte[]){
switch (menu){
    case 0:
        menu=1;
        break;
    case 1: {
        bool stop = false;
        for (int i = 0; i < 3; ++i) {
            if (!stop) {
                Color color(238, 29, 33);
                bouton boutonMenuClic{LARGEUR_ECRAN / 3, 240 + 210 * i, 100, LARGEUR_ECRAN / 3, color};
                if (boutonMenuClic.Clic(2 + i) != -1) {
                   menu =boutonMenuClic.Clic(2 + i);
                    stop = true;
                }
            }
        }
    }
        break;
    case 2: {

        bouton boutonMenuSuivant{1770, 920, 130, 130, Color(238, 29, 33)};
       if (boutonMenuSuivant.Clic(5)!=-1) {
           menu = boutonMenuSuivant.Clic(5);
       }
        //Bouton +
        int temp = 0;
        bool stop = false;
        for (int i = 2; i < 6; ++i) {
            if (!Perso[i].getjoueurJoue()&& !stop) {
                bouton boutonPlus{320 * i + 140, 520, 40, 40, Color(238, 29, 33)};
                temp=boutonPlus.Clic(i);
                if (temp==i){
                    stop=true;
                }
            }
        }
        if (temp > 1 && temp < 6) {
            for (int i = 2; i < temp + 1; ++i) {
                if (!Perso[i].getjoueurJoue()) {
                    InitialisationJoueur(Perso[i], choixJoueurCarte);
                }
            }
        }
        // Bouton Ferme
        int temp2 = 0;
        bool stop2 = false;
        for (int i = 2; i < 6; ++i) {
            if (Perso[i].getjoueurJoue() && !stop2) {
                bouton boutonFerme{320 * i + 15, 780, 40, 30, Color(238, 29, 33)};
                temp2=boutonFerme.Clic(i);
                if (temp2==i){
                    stop2=true;
                }
            }
        }
        if (temp2 > 1 && temp2 < 6) {
            for (int i = temp2; i < 6; ++i) {
                if (Perso[i].getjoueurJoue()) {
                    SupprimerJoueur(Perso[i], choixJoueurCarte);
                }
            }
        }
        // Bouton changement de Personnage
        int temp3 = -1;
        bool stop3 = false;
        for (int i = 0; i < 6; ++i) {
            if (Perso[i].getjoueurJoue() && !stop3) {
                bouton boutonChoix{320 * i + 270, 780, 50, 30, Color(238, 29, 33)};
               temp3= boutonChoix.Clic(i);
                if (temp3==i){
                    stop3=true;
                }
            }
        }
        if (temp3 > -1 && temp3 < 6) {
            if (Perso[temp3].getjoueurJoue()) {
               ChangementPerso(Perso[temp3], choixJoueurCarte);
            }
        }
        // Bouton Identifiant
        int temp4i=-1, temp4j=-1;
        bool stop4 = false;
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < 6; ++i) {
                if (Perso[i].getjoueurJoue() && !stop4) {
                    bouton boutonChoix{320 * i + 176*j +20, 225, 75, 90, Color(238, 29, 33)};
                    temp4i= boutonChoix.Clic(i);
                    temp4j= boutonChoix.Clic(j);
                    if (temp4i==i){
                        stop4=true;
                    }
                }
            }
        }
        if  (temp4i>-1 && temp4i<6){
            if (Perso[temp4i].getjoueurJoue()) {
                Perso[temp4i].AfficheID();
                if  (temp4j==0){
                    Perso[temp4i].setnouveauOuAncienCompte(1);
                }else{
                    Perso[temp4i].setnouveauOuAncienCompte(2);
                }
                for (int i = 0; i < 6; ++i) {
                    Perso[i].setenCourdeModif(false);
                }
                Perso[temp4i].setenCourdeModif(true);
            }
        }
        // Bouton Start
        int temp5 =-1;
        bool stop5 = false;
        for (int i = 0; i < 6; ++i) {
            if (Perso[i].getAfficherIdentifiant() && !stop5) {
                bouton boutonChoix{320 * i + 90, 700, 50, 150, Color(238, 29, 33)};
                temp5= boutonChoix.Clic(i);
                if (temp5==i){
                    stop5=true;
                }
            }
        }
        if  (temp5>-1 && temp5<6){
            if (Perso[temp5].getjoueurJoue()) {
                if  (temp4j==0){

                }else{

                }
            }
        }
        int temp6i =-1, temp6j=-1;
        bool stop6 = false;
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < 6; ++i) {
                if (Perso[i].getAfficherIdentifiant() && !stop6) {
                    bouton boutonChoix{320 * i + 30, 415+160*j, 45, 260, Color(238, 29, 33)};
                    temp6i = boutonChoix.Clic(i);
                    temp6j = boutonChoix.Clic(j);
                    if (temp6i == i && temp6j == j) {
                        stop6 = true;
                    }
                }
            }
        }
        if  (temp6i>-1 && temp6i<6){
            if (Perso[temp6i].getjoueurJoue()) {
                if  (temp6j==0){
                    Perso[temp6i].setEcritureMDP(false);
                    for (int i = 0; i < 6; ++i) {
                        Perso[i].setenCourdeModif(false);
                    }
                    Perso[temp6i].setenCourdeModif(true);
                }else{
                    Perso[temp6i].setEcritureMDP(true);
                    for (int i = 0; i < 6; ++i) {
                        Perso[i].setenCourdeModif(false);
                    }
                    Perso[temp6i].setenCourdeModif(true);
                }
            }
        }
    }
        break;

}
}

void SourisMouvement(short& menu, Event event,RenderWindow& window){
    switch (menu){
        case 1:
            for (int i = 0; i < 3; ++i) {
                bouton boutonMenu{LARGEUR_ECRAN/ 3,240 + 210 * i,100,LARGEUR_ECRAN/ 3,Color(238, 29, 33)};
                boutonMenu.DessinerRectangle(window,event);
            }
            break;
        case 2:
           break;
    }
}