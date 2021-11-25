#ifndef CLUEDO_REGLEDUJEU_H
#define CLUEDO_REGLEDUJEU_H
#include "IncludeAndDefine.h"

class RegleDuJeu {
private:
    std::vector<std::string> textRegle;
    int scroll=0;
public:
    void InitialisationRegle();
    void AfficherTexte(sf::RenderWindow& window);
    void setScroll(int a);
};


#endif //CLUEDO_REGLEDUJEU_H
