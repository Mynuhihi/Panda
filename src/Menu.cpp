#include <Menu.h>

//    //SoundMenu
//    sf::SoundBuffer MenuSFX;
//    MenuSFX.loadFromFile("Menu.wav");
//    sf::Sound mnsfx;
//    mnsfx.setBuffer(MenuSFX);
Menu::Menu( float width, float height)
{
    font.loadFromFile("pricedown bl.otf");

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("1:1");
    menu[0].setCharacterSize(45);
    menu[0].setPosition(sf::Vector2f(width/2-30, height/(MAX_NUMBER_OF_ITEMS + 1)*1 + 50));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Play against bot");
    menu[1].setCharacterSize(45);
    menu[1].setPosition(sf::Vector2f(width/2-175, height/(MAX_NUMBER_OF_ITEMS +1)*2 + 45));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Instructions");
    menu[2].setCharacterSize(45);
    menu[2].setPosition(sf::Vector2f(width/2-150, height/(MAX_NUMBER_OF_ITEMS +1)*3 + 40));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setCharacterSize(45);
    menu[3].setPosition(sf::Vector2f(width/2-55, height/(MAX_NUMBER_OF_ITEMS +1)*4+ 35));

    selectedItemIndex = 0;


}

Menu::~Menu()
{

}

//Draw menu
void Menu::draw(sf::RenderWindow &window){
    for ( int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window.draw (menu[i]);
    }

 }
//MoveUp
void Menu::MoveUp(){
    if (selectedItemIndex -1 >= 0 ){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
       // mnsfx.play();

    }
}
void Menu::MoveDown(){
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS ){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
        //mnsfx.play();

    }
}
