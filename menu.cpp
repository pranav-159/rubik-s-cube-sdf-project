#include "menu.h"

Menu::Menu(float width ,float height)
{
   if(!font.loadFromFile("Dosis-Light.ttf"))
   {
     //error
   }

   if(!texture.loadFromFile("rubix-cube_image.jpg"))
   {
     //error
   }
   
   rect.setTexture( &texture );
   rect.setSize(sf::Vector2f(1920,1000));  
   rect.setPosition(sf::Vector2f(0,0));

   rect1.setPosition(sf::Vector2f(70* width / 100 , height /(10) *5));
   rect1.setSize(sf::Vector2f(100,100));
   rect1.setFillColor(sf::Color::Transparent);
   
   rect2.setPosition(sf::Vector2f(70* width / 100 , height /(10) *7));
   rect2.setSize(sf::Vector2f(100,100));
   rect2.setFillColor(sf::Color::Transparent);
  
   menu[0].setFont( font );
   menu[0].setFillColor(sf::Color::Black);
   menu[0].setCharacterSize(100);
   menu[0].setString("Play");
   menu[0].setPosition(sf::Vector2f(70* width / 100 , height /(10) *5));

   menu[1].setFont( font );
   menu[1].setFillColor(sf::Color::Black);
   menu[1].setCharacterSize(100);
   menu[1].setString("Exit");
   menu[1].setPosition(sf::Vector2f(70* width / 100 , height /(10) *7));

   menu[2].setFont( font );
   menu[2].setFillColor(sf::Color::Black );
   menu[2].setCharacterSize(200);
   menu[2].setString("RUBIX-CUBE GAME");
   menu[2].setPosition(sf::Vector2f(10* width / 100 , height /(10) *(1/2)));
  
}

sf::RectangleShape Menu::getrect1()
{
  return rect1;
}

sf::RectangleShape Menu::getrect2()
{
  return rect2;
}


Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
  window.draw(rect);
  window.draw(rect1);
  window.draw(rect2);

  for(int i=0; i< MAX_NUMBER_OF_ITEMS; i++)
  {
    window.draw(menu[i]);
  }
}