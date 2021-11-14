
#ifndef CLUEDO_FONCTION_H
#define CLUEDO_FONCTION_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#define LARGEUR_ECRAN 1920
#define HAUTEUR_ECRAN 1080
#define LARGEUR_CARTE 420
#define HAUTEUR_CARTE 672
#define NB_CARTE 27
#define NB_PERSO 8
using namespace std;
using namespace sf;

void InitialisationSprite(Sprite fondMenu[],Texture* texture);

void SourisMouvement(short& menu, Event event,RenderWindow& window);
#endif //CLUEDO_FONCTION_H
