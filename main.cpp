#include <bits/stdc++.h>
#include "Wall.h"
#include "Ray.h"

#define WIDTH 800
#define HEIGHT 600

float Radian(double degree)
{
    double PI = 3.14159265359;
    return (degree * (PI / 180));
}
int ReturnIntRandom(int lower, int upper)
{
  return (rand() % (upper - lower + 1)) + lower;
}


int main()
{
  srand(time(0));
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "2D-RayCasting", sf::Style::Default, settings);	


  std::vector<Wall> walls{};
  int wallNumber = 5;
  for(int i = 0; i < wallNumber; i++)
  {
    float x1 = ReturnIntRandom(0,WIDTH);
    float x2 = ReturnIntRandom(0,WIDTH);
    float y1 = ReturnIntRandom(0,HEIGHT);
    float y2 = ReturnIntRandom(0,HEIGHT);
    walls.push_back(Wall(x1,y1,x2,y2));
  }


  std::vector<Ray> rays;
  for(float i = 0; i < 360; i+=0.05)
  {
    rays.push_back(Ray(sf::Vector2f(WIDTH/2,HEIGHT/2), Radian(i)));
  }

  bool isRightPressed = false;

  while(window.isOpen())
  {

    sf::Event event;
    while(window.pollEvent(event))
    {
      switch (event.type)
      {
        case sf::Event::Closed:
        {
          window.close();
        }
        break;
        case sf::Event::Resized:
        {
          sf::FloatRect visibleArea(0,0 ,event.size.width, event.size.height);
          window.setView(sf::View(visibleArea));
        }
        break;

        case sf::Event::MouseButtonPressed:
        {
          switch (event.mouseButton.button) {
            case sf::Mouse::Left:
            {
            }
            break;

            case sf::Mouse::Right:
            {
              if(isRightPressed)
                isRightPressed = false;
              else
                isRightPressed = true;
            }
            break;
          }
        }
        break;

        case sf::Event::MouseButtonReleased:
        {
          switch (event.mouseButton.button) {
            case sf::Mouse::Left:
            {
            }
            break;
            case sf::Mouse::Right:
            {
            }
            break;
          }
        }
        break;
      }
    }

    window.clear();

    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
    for(auto& w : walls)
      w.Draw(window);
    for(auto& r : rays)
    {
        if(isRightPressed)
        {
          r.setRayPosition(mousePos);
          r.CalculateHit(walls);
          r.Update();
          r.Draw(window);
        }
    }
    window.display();
  }
}
