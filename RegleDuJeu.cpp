#include "PointH/RegleDuJeu.h"

void RegleDuJeu::InitialisationRegle() {
    ifstream fichierTexte("../PointTXT/Regle.txt");
    string temp=" ";
    while (getline(fichierTexte, temp)) {
        textRegle.push_back(temp);
    }
}

void RegleDuJeu::AfficherTexte(RenderWindow &window) {
    Font font;
    font.loadFromFile("../font/Lato-Regular.ttf");
    Text text[textRegle.size()];

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
