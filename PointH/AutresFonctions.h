#ifndef CLUEDO_AUTRESFONCTIONS_H
#define CLUEDO_AUTRESFONCTIONS_H

#include "IncludeAndDefine.h"
#include "Bouton.h"
#include "Carte.h"
#include "Joueur.h"
#include "Case.h"
#include "Composant.h"
#include "Proposition.h"
#include "RegleDuJeu.h"
#include "Parametre.h"

void InitialisationCarte(Carte carte[NB_CARTE]);
void InitialisationCartePossible(Carte carte[NB_CARTE], cartePossible choixJoueurCarte[]);
void InitialisationSprite(sf::Sprite fondMenu[],sf::Texture* texture);
void InitialisationPlateau(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR]);
void InitialisationEnveloppe(Carte* enveloppe,Carte carte[NB_CARTE]);
void InitialisationMapSuite(Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],Joueur* joueur,int nbJ);

void AffichageMenu(sf::Sprite fondMenu[], int menu, sf::RenderWindow& window, Joueur* joueur,De* de,int nbJ,Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int tour,Proposition proposition,bool MontrerProposition,RegleDuJeu regleDuJeu);
void ClicGauche(int& menu, Joueur* joueur, cartePossible choixJoueurCarte[],int& nbJoueurs,Carte* carte,De de[2],int& SommeDesDes,Case plateau[NB_CASE_HAUTEUR][NB_CASE_LARGEUR],int& tour,Proposition& proposition,bool& MontrerProposition,Carte* enveloppe,bool& End,Parametre& parametre,sf::RenderWindow& window,Carte copyCarte[NB_CARTE]);
void ClicDroit(int menu,Joueur* joueur,int tour);
void ClavierTexte(int menu, Joueur* joueur, sf::Event event);
void Clavier(int& menu, Joueur* joueur, sf::Event event, sf::RenderWindow& window,bool &End,Parametre& parametre);

int NombreDeJoueurs(Joueur* joueur);
void MelangerCarte(Carte carte[NB_CARTE]);
void DistributionCarte(Joueur* joueur,Carte* carte,int nbJoueurs);
void SourisMolette(int menu,sf::Event& event,RegleDuJeu& regleDuJeu);
#endif
