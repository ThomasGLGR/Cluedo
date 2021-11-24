#include "PointH/AutresFonctions.h"

void PassageMenu5(int& menu, Joueur* joueur,int& nbJoueurs,Carte* carte,Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR]){
    bool valide=true;
    Bouton boutonMenuSuivant{1770, 920, 130, 130, Color::Transparent};
    for (int i = 0; i < 6; ++i) {
        if (joueur[i].getjoueurJoue()) {
            if (joueur[i].getEtatInscription() != Pret) {
                valide =true;
            }
        }
    }
    if (boutonMenuSuivant.Clic(5)!=-1 && valide) {
        nbJoueurs=NombreDeJoueurs(joueur);
        InitialisationMapSuite(plateau,joueur,nbJoueurs);
        DistributionCarte(joueur,carte,nbJoueurs);
        for (int i = 0; i < nbJoueurs; ++i) {
            joueur[i].BarrePremierCarte();
        }
        menu = boutonMenuSuivant.Clic(5);
    }

}

int EnsembleBouton(int x, int y, int h, int l, bool b, int s, Joueur* joueur, bool JouerouID){
    bool stop = false;
    bool A;
    int temp=ERREUR;
    for (int i = s; i < 6; ++i) {
        if (JouerouID){
            A=joueur[i].getjoueurJoue();
        }else {
            A=joueur[i].getAfficherIdentifiant();
        }
        if (A==b && !stop){
            Bouton bouton{320 * i + x, y, h, l, Color::Transparent};
            temp=bouton.Clic(i);
            if (temp==i){
                stop=true;
            }
        }
    }
    return temp;
}

void ChangementDeJoueurQuiJoue(Joueur* joueur,int a){
for (int i = 0; i < NB_JOUEURS; ++i) {
joueur[i].setenCourdeModif(false);
joueur[i].setenCourdeModif(false);
}
joueur[a].setenCourdeModif(true);
}

void BoutonInscription(Joueur* joueur,int& I,int& J){
    bool stop = false;
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 6; ++i) {
            if (joueur[i].getjoueurJoue() && !stop) {
                Bouton bouton{320 * i + 176 * j + 20, 225, 75, 90, Color::Transparent};
                I= bouton.Clic(i);
                J= bouton.Clic(j);
                if (I==i){
                    stop=true;
                }
            }
        }
    }
}
void BoutonIdentifiant(Joueur* joueur, int& I, int& J){
    bool stop6 = false;
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 6; ++i) {
            if (joueur[i].getAfficherIdentifiant() && !stop6) {
                Bouton boutonChoix{320 * i + 30, 415 + 160 * j, 45, 260,  Color::Transparent};
                I = boutonChoix.Clic(i);
                J = boutonChoix.Clic(j);
                if (I == i && J == j) {
                    stop6 = true;
                }
            }
        }
    }
}

void ClicGauche(int& menu, Joueur* joueur, cartePossible choixJoueurCarte[],int& nbJoueurs,Carte* carte,De de[2],int& SommeDesDes, Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int& tour,Proposition& proposition,bool& MontrerProposition){
switch (menu){
    case 0:
        menu=1;
        break;
    case 1: {

        bool stop = false;
        for (int i = 0; i < 3; ++i) {
            if (!stop) {
                Bouton boutonMenuClic{LARGEUR_ECRAN / 3, 240 + 210 * i, 100, LARGEUR_ECRAN / 3, ROUGE_MENU};
                if (boutonMenuClic.Clic(2 + i) != ERREUR) {
                    menu =boutonMenuClic.Clic(2 + i);
                    stop = true;
                }
            }
        }

        break;
    }
    case 2: {

        PassageMenu5(menu,joueur,nbJoueurs,carte,plateau);

        int boutonPlus = EnsembleBouton(140, 520, 40, 40, false, 2, joueur, true);
        if (boutonPlus!=ERREUR) {
            for (int i = 2; i < boutonPlus + 1; ++i) {
                    joueur[i].InitialisationJoueur(choixJoueurCarte);
            }
        }

        int boutonMoins = EnsembleBouton(15, 780, 40, 30, true, 2, joueur, true);
        if (boutonMoins !=ERREUR) {
            for (int i = boutonMoins; i < 6; ++i) {
                    joueur[i].SupprimerJoueur(choixJoueurCarte);
            }
        }

        int BoutonChangement = EnsembleBouton(270, 780, 50, 30, true, 0, joueur, true);
        if (BoutonChangement != ERREUR) {
               joueur[BoutonChangement].ChangementPerso(choixJoueurCarte);
        }

        int boutonInscriptionI=ERREUR;
        int boutonInscriptionJ=ERREUR;
        BoutonInscription(joueur, boutonInscriptionI, boutonInscriptionJ);
        if  (boutonInscriptionI != ERREUR){
                joueur[boutonInscriptionI].AfficheID();
                joueur[boutonInscriptionI].setetatInscription(boutonInscriptionJ + 1);
                ChangementDeJoueurQuiJoue(joueur, boutonInscriptionI);
        }


        int boutonStart = EnsembleBouton(90, 700, 50, 150, true, 0, joueur, false);
        if  (boutonStart != ERREUR){
            joueur[boutonStart].AjouterUnJoueur();
            joueur[boutonStart].VerifierJoueurExistant();
        }


        int boutonIdentifiantI = ERREUR;
        int boutonIdentifiantJ = ERREUR;
        BoutonIdentifiant(joueur, boutonIdentifiantI, boutonIdentifiantJ);
        if  (boutonIdentifiantI != ERREUR){
                joueur[boutonIdentifiantI].setEcritureMDP(boutonIdentifiantJ);
                ChangementDeJoueurQuiJoue(joueur, boutonIdentifiantI);
        }
    }
        break;
    case 5: {
        joueur[tour].changementBlocNoteBarre();
        SommeDesDes = 0;
        int stopDe = ERREUR;
        Bouton boutonLancerDe{1500, 800, 150, 315, Color::Transparent};
        stopDe = boutonLancerDe.Clic(1);
        if (stopDe != ERREUR) {
            for (int i = 0; i < 2; ++i) {
                de[i].LancerDe(SommeDesDes);
                de[i].setLancerDe(false);
            }
            stopDe = ERREUR;
            joueur[tour].getPion().DeplacementPion(plateau, SommeDesDes);
        }

        bool actualise = false;
        for (int i = 0; i < NB_CASE_HAUTEUR; ++i) {
            for (int j = 0; j < NB_CASE_LARGEUR; ++j) {
                if ((Mouse::getPosition().x > DEBUT_PLATEAU_X + j * LONGEUR_CASE) &&
                    (Mouse::getPosition().x < DEBUT_PLATEAU_X + j * LONGEUR_CASE + LONGEUR_CASE) &&
                    (Mouse::getPosition().y > DEBUT_PLATEAU_Y + i * LONGEUR_CASE) &&
                    (Mouse::getPosition().y < DEBUT_PLATEAU_Y + i * LONGEUR_CASE + LONGEUR_CASE)) {
                    if (plateau[i][j].getDeplacementPossible()) {
                        joueur[tour].setPion(DEBUT_PLATEAU_X + j * LONGEUR_CASE, DEBUT_PLATEAU_Y + i * LONGEUR_CASE);
                        actualise = true;
                        if (plateau[i][j].getTypedeCase() == Salle) {
                            proposition.InitialisationSalle(i, j);
                            menu = 6;
                        } else {
                            tour = (tour + 1) % nbJoueurs;
                            for (int k = 0; k < 2; ++k) {
                                de[k].setLancerDe(true);
                            }
                        }
                    }
                }
            }
        }
        if (actualise) {
            for (int i = 0; i < NB_CASE_HAUTEUR; ++i) {
                for (int j = 0; j < NB_CASE_LARGEUR; ++j) {
                    plateau[i][j].setDeplacementPossible(false);
                }
            }
        }
        if (MontrerProposition){
            Bouton boutonSuivant(1750,900,150,150,Color::Transparent);
        if(boutonSuivant.Clic(0)!=ERREUR){
            for (int i = 0; i < nbJoueurs; ++i) {
                joueur[i].SupprimerAfficherProposition();
            }
            for (int k = 0; k < 2; ++k) {
                de[k].setLancerDe(true);
            }
            MontrerProposition=false;
            tour=(tour+1)%nbJoueurs;
        }
        }
    }

    break;
    case 6:
        proposition.ChoisiLaPropositon(MontrerProposition);
        if (MontrerProposition){
            bool stop=false;
            for (int i = 1; i < nbJoueurs; ++i) {
                if (!stop) {
                    joueur[(tour + i) % nbJoueurs].VerificationProposition(proposition.getAccusation(),stop);
                }
            }
            menu=5;
        }
        break;
}
}

void SourisMouvement(int& menu,RenderWindow& window){
    switch (menu){
        case 1:
            for (int i = 0; i < 3; ++i) {
            Bouton boutonMenu{LARGEUR_ECRAN / 3, 240 + 210 * i, 100, LARGEUR_ECRAN / 3, ROUGE_MENU};
            boutonMenu.DessinerRectangle(window);
            }
            break;
        case 6:
            break;
    }
}

void ClicDroit(int menu,Joueur* joueur,int tour) {
    if (menu == 5) {
        joueur[tour].changementBlocNoteEntoure();
    }
}
/*
void SourisMolette(int& menu,vector<string> RegleDuJeu,RenderWindow& window) {
    if (menu == 4) {
        Font font;
        font.loadFromFile("../font/Lato-Regular.ttf");
        Text text;
        text.setFont(font);

        text.setCharacterSize(t);
        text.setFillColor(Color(238, 29, 33));
        text.setPosition(x,y);
        window.draw(text);
    }
}*/
