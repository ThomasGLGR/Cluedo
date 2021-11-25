#include "PointH/AutresFonctions.h"



void PassageMenu5(int& menu, Joueur* joueur,int& nbJoueurs,Carte* carte,Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR]){
    bool valide=true;
    Bouton boutonMenuSuivant{1770, 920, 130, 130, Color::Transparent};
    for (int i = 0; i < 6; ++i) {
        if (joueur[i].getjoueurJoue()) {
            if (joueur[i].getEtatInscription() != Pret) {
                valide = false;
            }
        }
    }
    if (boutonMenuSuivant.Clic(5)!=ERREUR && valide) {
        nbJoueurs=NombreDeJoueurs(joueur);
        InitialisationMapSuite(plateau,joueur,nbJoueurs);
        DistributionCarte(joueur,carte,nbJoueurs);
        for (int i = 0; i < nbJoueurs; ++i) {
            joueur[i].BarrePremierCarte();
            joueur[i].AjouterUnePartie(false);
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

void ClicGauche(int& menu, Joueur* joueur, cartePossible choixJoueurCarte[],int& nbJoueurs,Carte* carte,De de[2],int& SommeDesDes, Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int& tour,Proposition& proposition,bool& MontrerProposition,Carte* enveloppe,bool& End,Parametre& parametre,RenderWindow& window,Carte copyCarte[NB_CARTE]){
switch (menu){
    case 0:
        menu=1;
        break;
    case 1: {
        bool stop = false;
        for (int i = 0; i < 3; ++i) {
            if (!stop) {
                Bouton boutonMenuClic{LARGEUR_ECRAN / 3, 240 + 210 * i, 100, LARGEUR_ECRAN / 3, ROUGE_MENU};
                switch (boutonMenuClic.Clic(i)) {
                    case 0:
                        menu=2;
                        stop= true;
                        break;
                    case 1:
                        Parametre::ChargerPartie(joueur,tour,nbJoueurs,enveloppe,copyCarte);
                        cout<<tour<<endl<<nbJoueurs<<endl<<enveloppe[0].getNom()<<endl;
                        menu=5;
                        stop= true;
                        break;
                    case 2:
                        menu=4;
                        stop= true;
                        break;
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
    case 4:{
        Bouton boutonSuivant(1750,900,150,150,Color::Transparent);
        if(boutonSuivant.Clic(0)!=ERREUR){
            menu=parametre.getmenuMemoire();
        }
    }
        break;
    case 5: {
        joueur[tour].changementBlocNoteBarre();
        SommeDesDes = 0;
        int stopDe = ERREUR;
        if  (!MontrerProposition){
        Bouton boutonLancerDe{1500, 800, 150, 315, Color::Transparent};
        stopDe = boutonLancerDe.Clic(1);
        if (stopDe != ERREUR) {
           for (int i = 0; i < 2; ++i) {de[i].LancerDe(SommeDesDes);}
            joueur[tour].getPion().DeplacementPion(plateau, SommeDesDes,de[0].getPeutLancerDe());
            for (int i = 0; i < 2; ++i) {de[i].setLancerDe(false);}
            stopDe = ERREUR;
        }
        }else{
            Bouton boutonSuivant(1750,900,150,150,Color::Transparent);
            if(boutonSuivant.Clic(0)!=ERREUR){
                for (int i = 0; i < nbJoueurs; ++i) {
                    joueur[i].SupprimerAfficherProposition();
                }
                MontrerProposition=false;
                tour=(tour+1)%nbJoueurs;
                for (int k = 0; k < 2; ++k) {
                    de[k].setLancerDe(true);
                }
            }
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
                        if (plateau[i][j].getTypedeCase() == Salle) {
                            proposition.InitialisationSalle(i, j);
                            proposition.InitialisationMenu(menu);
                            menu = 6;
                            actualise = true;
                        } else {
                            tour = (tour + 1) % nbJoueurs;
                            for (int k = 0; k < 2; ++k) {
                                de[k].setLancerDe(true);
                            }
                            actualise = true;
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
        if (de[0].getPeutLancerDe()) {
            Bouton boutonAccusation{792, 928, 70, 400, ROUGE_MENU};
            if (boutonAccusation.Clic(0) != ERREUR) {
                proposition.InitialisationMenu(6);
                menu = 6;
            }
        }

        int stopJeu=nbJoueurs;
        while (joueur[tour].getHorsJeu() && stopJeu>ERREUR){
            tour=(tour+1)%nbJoueurs;
            stopJeu--;
        }
        if (stopJeu==ERREUR){
            menu=1;
            End=true;
        }
    }
    break;
    case 6:
        proposition.ChoisiLaPropositon(MontrerProposition,enveloppe);

        if (proposition.getMenuEncours()==7){
            if (proposition.getVictoire()){
                menu=7;
            }else{
                joueur[tour].setHorsJeu(true);
                tour=(tour+1)%nbJoueurs;
                menu=5;
            }
        }
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
    case 7: {
        Bouton boutonSuivant(1700, 900, 250, 250, Color::Transparent);
        if (boutonSuivant.Clic(0) != ERREUR) {
            joueur[tour].AjouterUnePartie(true);
            End = true;
            menu = 1;
        }
    }
        break;
    case 3: {
        bool stop = false;
        for (int i = 0; i < 3; ++i) {
            if (!stop) {
                Bouton boutonOption{550, 260 + 210 * i, 100, 820, ROUGE_MENU};
                    if (boutonOption.Clic(i)==0){
                        menu=parametre.getmenuMemoire();
                        stop = true;
                    }
                    if (boutonOption.Clic(i)==1){
                        menu=4;
                        stop = true;
                    }
                    if (boutonOption.Clic(i)==2){
                        parametre.sauvegarder(joueur,tour,nbJoueurs,enveloppe);
                        window.close();
                    }

            }
        }
    }
        break;
}
}


void ClicDroit(int menu,Joueur* joueur,int tour) {
    if (menu == 5) {
        joueur[tour].changementBlocNoteEntoure();
    }
}

void SourisMolette(int menu,Event& event,RegleDuJeu& regleDuJeu) {
    if (menu == 4) {
        regleDuJeu.setScroll(20*event.mouseWheel.delta);
    }
}
