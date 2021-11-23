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
public:
    void InitialisationProposition(Carte* carte);
    void InitialisationSalle(int i, int j);
    void AfficherProposition(RenderWindow& window);
    void AfficherCarteAChoisir(RenderWindow& window);
    void EcrireNom(RenderWindow &window, int t, string nom, int x, int y,Color C);
    void ChoisiLaPropositon(bool& MontrerProposition);
    Carte* getAccusation();
};


#endif //CLUEDO_PROPOSITION_H