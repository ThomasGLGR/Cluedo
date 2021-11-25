#include "PointH/IncludeAndDefine.h"
#include "PointH/Bouton.h"

int Bouton::Clic(int variable) {
    if (sf::Mouse::getPosition().x> x && sf::Mouse::getPosition().x< x + l && sf::Mouse::getPosition().y > y && sf::Mouse::getPosition().y < y + h) {
        return variable;
    }
    return ERREUR;
}

void Bouton::DessinerRectangle(sf::RenderWindow& window,float line) {
    if (sf::Mouse::getPosition().x> x && sf::Mouse::getPosition().x< x + l && sf::Mouse::getPosition().y > y && sf::Mouse::getPosition().y < y + h) {
        sf::RectangleShape rectangle(sf::Vector2f(l, h));
        rectangle.setFillColor(sf::Color::Transparent);
        rectangle.setOutlineThickness(line);
        rectangle.setOutlineColor(couleur);
        rectangle.setPosition(x, y);
        window.draw(rectangle);
    }
}

Bouton::Bouton(int x0, int y0, int h0, int l0, sf::Color couleur0){
    x=x0;
    y=y0;
    h=h0;
    l=l0;
    couleur=couleur0;
}