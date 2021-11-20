#include "PointH/AutresFonctions.h"

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
void EcrireTexte(RenderWindow& window,int t, string Text,int x,int y,Color color) {
    sf::Font font;
    font.loadFromFile("../font/Lato-Regular.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(Text);
    text.setCharacterSize(t);
    text.setFillColor(color);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2, textRect.height / 2);
    text.setPosition(x, y);
    window.draw(text);
}
void Dessinercroix(int i,RenderWindow& window){
        RectangleShape rectangle1(Vector2f(6, 40));
        rectangle1.setFillColor(ROUGE_MENU);
        rectangle1.setPosition(320*i+157, 520);
        window.draw(rectangle1);
        RectangleShape rectangle2(Vector2f(40, 6));
        rectangle2.setFillColor(ROUGE_MENU);
        rectangle2.setPosition(320*i+140, 537);
        window.draw(rectangle2);
}
void dessinerCroixFerme(int i,RenderWindow& window){
    RectangleShape rectangle1(Vector2f(4, 25));
    rectangle1.setFillColor(ROUGE_MENU);
    rectangle1.setPosition(320*i+35,792);
    rectangle1.rotate(45);
    window.draw(rectangle1);
    RectangleShape rectangle2(Vector2f(4, 25));
    rectangle2.setFillColor(ROUGE_MENU);
    rectangle2.setPosition(320*i+18,795);
    rectangle2.rotate(-45);
    window.draw(rectangle2);
}
void DessinerFleche(RenderWindow& window,int x,int y,int r){
    RectangleShape rectangle1(Vector2f(4, 25));
    rectangle1.setFillColor(ROUGE_MENU);
    rectangle1.setPosition(x, y);
    rectangle1.rotate(r);
    window.draw(rectangle1);
    rectangle1.rotate(2*r);
    rectangle1.setPosition(x+3, y+3);
    rectangle1.setFillColor(ROUGE_MENU);
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
void DessinerTexturePictogramme(RenderWindow& window, int x, int y, string filename, Joueur joueur){
    if   (joueur.getEtatInscription() == 3){
        string temp=joueur.getID();
        temp += " WR: ";
        temp += to_string(joueur.WinRate());
        temp += "%";
        joueur.EcrireNom(window, 28, temp, x + 144, 260);
    }else {
        Texture texture;
        texture.loadFromFile(filename);
        Sprite sprite[2];
        for (int i = 0; i < 2; ++i) {
            sprite[i].setTexture(texture);
            sprite[i].setTextureRect(IntRect(144 * i, 0, 144, 76));
            if (joueur.getEtatInscription() != 1 + i) {
                sprite[i].setColor(Color(255, 255, 255, 108));
            }
            sprite[i].setPosition(x + 144 * i, y);
            window.draw(sprite[i]);
        }
    }
}

void AffichageMenu(Sprite fondMenu[], int menu, RenderWindow& window, Joueur* joueur){
    window.draw(fondMenu[menu]);
    switch (menu) {
        case 2:

            for (int i = 0; i < 6; ++i) {
                if (!joueur[i].getjoueurJoue()){
                    Dessinercroix(i,window);
                }else{
                    if (!joueur[i].getAfficherIdentifiant()) {
                        joueur[i].getAvatar().dessinerCarte(window, 320 * i + 16, 310, 288, 460);
                    }else{
                        DessinerTexture(window,320 * i + 16, 310,"../Image/Identifiant.png");
                        joueur[i].EcrireID(window, 24, joueur[i].getID(), 320 * i + 55, 420, false);
                        joueur[i].EcrireID(window, 24, joueur[i].getMDP(), 320 * i + 55, 580, true);
                        if (joueur[i].getmessageErreur()){
                            EcrireTexte(window,25,"Identifiant inconnue",320*i+160,670,ROUGE_MENU);
                        }
                    }
                    joueur[i].EcrireNom(window, 28, joueur[i].getAvatar().getNom(), 320 * i + 160, 795);
                   if (i>1){
                       dessinerCroixFerme(i,window);
                   }
                    DessinerFleche(window,320*i+297,800,45);
                    DessinerTexturePictogramme(window,320*i+16, 220, "../Image/Pictogramme.png", joueur[i]);
                }
            }
            break;
    }
}