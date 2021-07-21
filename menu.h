#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
  public:
       Menu(float width, float height);
       ~Menu();

       void draw (sf::RenderWindow &window);
       void MoveUp();
       void MoveDown();
       sf::RectangleShape getrect1();
       sf::RectangleShape getrect2();

  private:
      int selectedItemIndex;
      sf::Font font;
      sf::Texture texture;
      sf::RectangleShape rect;
      sf::RectangleShape rect1;
      sf::RectangleShape rect2;
      sf::Text menu[MAX_NUMBER_OF_ITEMS];
       
};