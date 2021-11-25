#include "PointH/RegleDuJeu.h"

void RegleDuJeu::InitialisationRegle() {
    std::ifstream fichierTexte("../PointTXT/Regle.txt");
    std::string temp=" ";
    while (getline(fichierTexte, temp)) {
        textRegle.push_back(temp);
    }
}

void RegleDuJeu::AfficherTexte(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("../font/Lato-Regular.ttf");
    sf::Text text[textRegle.size()];

    for (int i = 0; i < textRegle.size(); ++i) {
        text[i].setFont(font);
        text[i].setCharacterSize(35);
        text[i].setFillColor(ROUGE_MENU);
        text[i].setPosition(70,50*i+100+scroll);
        text[i].setString(textRegle[i]);
        window.draw(text[i]);
    }
}

void RegleDuJeu::setScroll(int a) {
    if (scroll>0) {
        if (a < 0) {
            scroll += a;
        }
    }
    else if (scroll<-1400){
        if ( a > 0) {
            scroll += a;
        }
    }else{
        scroll += a;
    }
}
