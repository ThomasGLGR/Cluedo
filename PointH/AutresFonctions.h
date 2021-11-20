#ifndef CLUEDO_AUTRESFONCTIONS_H
#define CLUEDO_AUTRESFONCTIONS_H

#include "IncludeAndDefine.h"
#include "Bouton.h"
#include "Carte.h"
#include "Joueur.h"
#include "Map.h"

void InitialisationCarte(carte Carte[NB_CARTE],cartePossible choixJoueurCarte[]);
void AffichageMenu(Sprite fondMenu[], int menu, RenderWindow& window, Joueur* joueur);
void ClicGauche(int& menu, Joueur* joueur, cartePossible choixJoueurCarte[],int& nbJoueurs);
void ClavierTexte(int menu, Joueur* joueur, Event event);
void Clavier(int menu, Joueur* joueur, Event event, RenderWindow& window);
void InitialisationSprite(Sprite fondMenu[],Texture* texture);
void SourisMouvement(int& menu,RenderWindow& window);
int NombreDeJoueurs(Joueur* joueur);
#endif
