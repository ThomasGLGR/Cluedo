#include "Fonction.h"
#include "perso.h"
void InitialisationSprite(Sprite fondMenu[],Texture* texture){
    texture[0].loadFromFile("../Image/Menu0.jpg");
    fondMenu[0].setTexture(texture[0]);
    texture[1].loadFromFile("../Image/Menu1.jpg");
    fondMenu[1].setTexture(texture[1]);
    texture[2].loadFromFile("../Image/Menu2.jpg");
    fondMenu[2].setTexture(texture[2]);
    texture[5].loadFromFile("../Image/Menu5.jpg");
    fondMenu[5].setTexture(texture[5]);
}

void Dessinercroix(int i,RenderWindow& window){
    Color color(238, 29, 33);
        RectangleShape rectangle1(Vector2f(6, 40));
        rectangle1.setFillColor(color);
        rectangle1.setPosition(320*i+157, 520);
        window.draw(rectangle1);
        RectangleShape rectangle2(Vector2f(40, 6));
        rectangle2.setFillColor(color);
        rectangle2.setPosition(320*i+140, 537);
        window.draw(rectangle2);
}
void dessinerCroixFerme(int i,RenderWindow& window){
    Color color(238, 29, 33);
    RectangleShape rectangle1(Vector2f(4, 25));
    rectangle1.setFillColor(color);
    rectangle1.setPosition(320*i+35,792);
    rectangle1.rotate(45);
    window.draw(rectangle1);
    RectangleShape rectangle2(Vector2f(4, 25));
    rectangle2.setFillColor(color);
    rectangle2.setPosition(320*i+18,795);
    rectangle2.rotate(-45);
    window.draw(rectangle2);
}
void DessinerFleche(RenderWindow& window,int x,int y,int r){
    Color color(238, 29, 33);
    RectangleShape rectangle1(Vector2f(4, 25));
    rectangle1.setFillColor(color);
    rectangle1.setPosition(x, y);
    rectangle1.rotate(r);
    window.draw(rectangle1);
    rectangle1.rotate(2*r);
    rectangle1.setPosition(x+3, y+3);
    rectangle1.setFillColor(color);
    window.draw(rectangle1);
}
void DessinerTexture(RenderWindow& window,int x,int y,string filename){
    Texture texture;
    texture.loadFromFile(filename);
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
    window.draw(sprite);
}
void DessinerTexturePictogramme(RenderWindow& window,int x,int y,string filename){
    Texture texture;
    texture.loadFromFile(filename);
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setColor(sf::Color(255, 255, 255, 128));
    sprite.setPosition(x,y);
    window.draw(sprite);
}

void AffichageMenu(Sprite fondMenu[],short menu,RenderWindow& window,perso* Perso){
    window.draw(fondMenu[menu]);
    switch (menu) {
        case 2:

            for (int i = 0; i < 6; ++i) {
                if (!Perso[i].getjoueurJoue()){
                    Dessinercroix(i,window);
                }else{
                    if (!Perso[i].getAfficherIdentifiant()) {
                        Perso[i].getAvatar().dessinerCarte(window, 320 * i + 16, 310, 288, 460);
                    }else{
                        DessinerTexture(window,320 * i + 16, 310,"../Image/Identifiant.png");
                        Perso[i].EcrireID(window,28,Perso[i].getID(),320*i+55,420);
                        Perso[i].EcrireID(window,28,Perso[i].getMDP(),320*i+55,580);

                    }
                    Perso[i].EcrireNom(window,28,Perso[i].getAvatar().getNom(),320*i+160,795);
                   if (i>1){
                       dessinerCroixFerme(i,window);
                   }
                    DessinerFleche(window,320*i+297,800,45);
                    DessinerTexturePictogramme(window,320*i+16,220,"../Image/Pictogramme.png");
                }
            }

            break;

    }
}