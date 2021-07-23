#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu 
{
  public:
       Menu(float width, float height);
       ~Menu();
       void instructions();
       void draw (sf::RenderWindow &window);
       void MoveUp();
       void MoveDown();
       sf::RectangleShape getrect1();
       sf::RectangleShape getrect2();
       sf::RectangleShape getrect3();


  private:
      int selectedItemIndex;
      sf::Font font;
      sf::Texture texture;
      sf::RectangleShape rect;
      sf::RectangleShape rect1;
      sf::RectangleShape rect2;
      sf::RectangleShape rect3;
      sf::Text menu[MAX_NUMBER_OF_ITEMS];
       
};