#include "PointH/IncludeAndDefine.h"
#include "PointH/Bouton.h"

int Bouton::Clic(int variable) {
    if (Mouse::getPosition().x> x && Mouse::getPosition().x< x + l && Mouse::getPosition().y > y && Mouse::getPosition().y < y + h) {
        return variable;
    }
    return ERREUR;
}

void Bouton::DessinerRectangle(RenderWindow& window) {
    if (Mouse::getPosition().x> x && Mouse::getPosition().x< x + l && Mouse::getPosition().y > y && Mouse::getPosition().y < y + h) {
        RectangleShape rectangle(Vector2f(l, h));
        rectangle.setFillColor(Color::Transparent);
        rectangle.setOutlineThickness(10.f);
        rectangle.setOutlineColor(couleur);
        rectangle.setPosition(x, y);
        window.draw(rectangle);
    }
}

Bouton::Bouton(int x0, int y0, int h0, int l0, Color couleur0){
    x=x0;
    y=y0;
    h=h0;
    l=l0;
    couleur=couleur0;
}