#ifndef CLUEDO_AUTRESFONCTIONS_H
#define CLUEDO_AUTRESFONCTIONS_H

#include "IncludeAndDefine.h"
#include "Bouton.h"
#include "Carte.h"
#include "Joueur.h"
#include "Case.h"
#include "Composant.h"
#include "Proposition.h"

void InitialisationCarte(Carte carte[NB_CARTE], cartePossible choixJoueurCarte[]);
void AffichageMenu(Sprite fondMenu[], int menu, RenderWindow& window, Joueur* joueur,De* de,int nbJ,Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int tour,Proposition proposition,bool MontrerProposition);
void ClicGauche(int& menu, Joueur* joueur, cartePossible choixJoueurCarte[],int& nbJoueurs,Carte* carte,De de[2],int& SommeDesDes,Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int& tour,Proposition& proposition,bool& MontrerProposition);
void ClicDroit(int menu,Joueur* joueur,int tour);
void ClavierTexte(int menu, Joueur* joueur, Event event);
void Clavier(int menu, Joueur* joueur, Event event, RenderWindow& window);
void InitialisationSprite(Sprite fondMenu[],Texture* texture);
void InitialisationPlateau(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR]);
void SourisMouvement(int& menu,RenderWindow& window);
int NombreDeJoueurs(Joueur* joueur);
void MelangerCarte(Carte carte[NB_CARTE]);
void DistributionCarte(Joueur* joueur,Carte* carte,int nbJoueurs);
void InitialisationEnveloppe(Carte* enveloppe,Carte carte[NB_CARTE]);
void InitialisationMapSuite(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],Joueur* joueur,int nbJ);
void SourisMolette(int& menu,vector<string> RegleDuJeu,RenderWindow& window);
void InitialisationRegle(  vector<string> RegleDuJeu);
#endif
