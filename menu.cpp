#include "menu.h"
#include "opengl.h"

Menu::Menu(float width ,float height)
{
   if(!font.loadFromFile("Dosis-Light.ttf"))
   {
     //error
   }

   if(!texture.loadFromFile("Rubik's-cube.jpeg"))
   {
     //error
   }
   
   rect.setTexture( &texture );
   rect.setSize(sf::Vector2f(1900,900));  
   rect.setPosition(sf::Vector2f(0,0));

   rect1.setPosition(sf::Vector2f(70* width / 100 , height /(10) *3));
   rect1.setSize(sf::Vector2f(200,100));
   rect1.setFillColor(sf::Color::Transparent);
   
   rect2.setPosition(sf::Vector2f(70* width / 100 , height /(10) *5));
   rect2.setSize(sf::Vector2f(500,100));
   rect2.setFillColor(sf::Color::Transparent);

   rect3.setPosition(sf::Vector2f(70* width / 100 , height /(10) *7));
   rect3.setSize(sf::Vector2f(200,100));
   rect3.setFillColor(sf::Color::Transparent);
  
  
   menu[0].setFont( font );
   menu[0].setFillColor(sf::Color::Black);
   menu[0].setCharacterSize(100);
   menu[0].setString("Play");
   menu[0].setPosition(sf::Vector2f(70* width / 100 , height /(10) *3));

   menu[1].setFont( font );
   menu[1].setFillColor(sf::Color::Black);
   menu[1].setCharacterSize(100);
   menu[1].setString("Instructions");
   menu[1].setPosition(sf::Vector2f(70* width / 100 , height /(10) *5));

   menu[2].setFont( font );
   menu[2].setFillColor(sf::Color::Black);
   menu[2].setCharacterSize(100);
   menu[2].setString("Exit");
   menu[2].setPosition(sf::Vector2f(70* width / 100 , height /(10) *7));
  
  
}

sf::RectangleShape Menu::getrect1()
{
  return rect1;
}

sf::RectangleShape Menu::getrect2()
{
  return rect2;
}

sf::RectangleShape Menu::getrect3()
{
  return rect3;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
  window.draw(rect);
  window.draw(rect1);
  window.draw(rect2);
  window.draw(rect3);

  for(int i=0; i< MAX_NUMBER_OF_ITEMS; i++)
  {
    window.draw(menu[i]);
  }
}

void Menu::instructions(){
  sf::RenderWindow window2(sf::VideoMode::getDesktopMode(), "INSTRUCTIONS");
  std::vector<sf::Text> text ;
  sf::Text t;
  sf::Font fonts;
          
  fonts.loadFromFile("Dosis-Light.ttf");
          
  t.setString("ALT + L    left down");
  t.setPosition(sf::Vector2f(100 , 25));
  t.setFont( fonts );
  t.setFillColor(sf::Color::Red);
  t.setCharacterSize(50);
  text.push_back(t);

  t.setString("ALT + R    right down");
  t.setPosition(sf::Vector2f(100 , 125));
  text.push_back(t);

  t.setString("ALT + U    up right");
  t.setPosition(sf::Vector2f(100 , 225));
  text.push_back(t);

  t.setString("ALT + D    down right");
  t.setPosition(sf::Vector2f(100 , 325));
  text.push_back(t);

  t.setString("ALT + V    vertical down.");
  t.setPosition(sf::Vector2f(100 , 425));
  text.push_back(t);

  t.setString("ALT + H    horizontal right");
  t.setPosition(sf::Vector2f(100 , 525));
  text.push_back(t);

  t.setString("ALT + F    front clockwise");
  t.setPosition(sf::Vector2f(100 , 625));
  text.push_back(t);

  t.setString("ALT + B    back clockwise");
  t.setPosition(sf::Vector2f(100 , 725));
  text.push_back(t);

  while(window2.isOpen())
  {
    sf::Event event;
    while(window2.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window2.close();
      }
    }
    window2.clear();
    for(auto i = text.begin(); i!= text.end(); i++)
    {
      window2.draw(*i);
    }
    window2.display();
  }
}
