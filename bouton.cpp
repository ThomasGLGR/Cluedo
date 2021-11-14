#include "Fonction.h"
#include "bouton.h"

int bouton::Clic(int variable) {
    if (Mouse::getPosition().x> x && Mouse::getPosition().x< x+L && Mouse::getPosition().y> y && Mouse::getPosition().y< y+l) {
        return variable;
    }
    return -1;
}

void bouton::DessinerRectangle(RenderWindow& window, Event event) {
    if (Mouse::getPosition().x> x && Mouse::getPosition().x< x+L && Mouse::getPosition().y> y && Mouse::getPosition().y< y+l) {
        RectangleShape rectangle(Vector2f(L, l));
        rectangle.setFillColor(Color::Transparent);
        rectangle.setOutlineThickness(10.f);
        rectangle.setOutlineColor(couleur);
        rectangle.setPosition(x, y);
        window.draw(rectangle);
    }
}

bouton::bouton(int x0,int y0,int l0,int L0,Color couleur0){
    x=x0;
    y=y0;
    l=l0;
    L=L0;
    couleur=couleur0;
}