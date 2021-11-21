#ifndef CLUEDO_AUTRESFONCTIONS_H
#define CLUEDO_AUTRESFONCTIONS_H

#include "IncludeAndDefine.h"
#include "Bouton.h"
#include "Carte.h"
#include "Joueur.h"
#include "Case.h"

void InitialisationCarte(Carte carte[NB_CARTE], cartePossible choixJoueurCarte[]);
void AffichageMenu(Sprite fondMenu[], int menu, RenderWindow& window, Joueur* joueur);
void ClicGauche(int& menu, Joueur* joueur, cartePossible choixJoueurCarte[],int& nbJoueurs,Carte* carte);
void ClavierTexte(int menu, Joueur* joueur, Event event);
void Clavier(int menu, Joueur* joueur, Event event, RenderWindow& window);
void InitialisationSprite(Sprite fondMenu[],Texture* texture);
void InitialisationPlateau(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR]);
void SourisMouvement(int& menu,RenderWindow& window);
int NombreDeJoueurs(Joueur* joueur);
void MelangerCarte(Carte carte[NB_CARTE]);
void DistributionCarte(Joueur* joueur,Carte* carte,int nbJoueurs);
#endif
