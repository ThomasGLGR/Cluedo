#ifndef CLUEDO_PROPOSITION_H
#define CLUEDO_PROPOSITION_H
#include "IncludeAndDefine.h"
#include "Carte.h"
#include "Bouton.h"

class Proposition {
private:
    Carte ListepropositionPerso[NB_PERSO];
    Carte ListepropositionArme[NB_ARMES];
    Carte ListepropositionSalle[NB_SALLE];
    Carte accusation[3];
    int etape=0;
    int menuEncours;
    bool victoire=false;

public:
    void InitialisationProposition(Carte* carte);
    void InitialisationSalle(int i, int j);
    void InitialisationMenu(int m);
    void AfficherProposition(sf::RenderWindow& window);
    void AfficherCarteAChoisir(sf::RenderWindow& window);
    void EcrireNom(sf::RenderWindow &window, int t, std::string nom, int x, int y,sf::Color C);
    void ChoisiLaPropositon(bool& MontrerProposition,Carte* enveloppe);
    Carte* getAccusation();
    int getMenuEncours();
    void VerificationAccusation(Carte* enveloppe);
    bool getVictoire();
    void clearProposition();
};


#endif //CLUEDO_PROPOSITION_H
