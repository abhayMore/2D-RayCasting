#include <iostream>
#include <SFML/Graphics.hpp>
#include "segment.h"
#include "Wall.h"
#include "Ray.h"

#define WIDTH 900
#define HEIGHT 800

int main()
{
  srand(time(0));
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "2D-RayCasting", sf::Style::Titlebar | sf::Style::Close, settings);

  Wall wallsInit(WIDTH,HEIGHT);
  Ray lightRays;

  bool isKeyRpressed = false;
  bool isRightPressed = false;
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
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
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        window.setView(sf::View(visibleArea));
      }
      break;

      case sf::Event::KeyPressed:
      {
        switch (event.key.code)
        {
        case sf::Keyboard::R:
        {
          if (isKeyRpressed)
            isKeyRpressed = false;
          else
            isKeyRpressed = true;
        }
        default:
          break;
        }
      }
      case sf::Event::MouseButtonPressed:
      {
        switch (event.mouseButton.button) {
        case sf::Mouse::Left:
        {
        }
        break;

        case sf::Mouse::Right:
        {
          if (isRightPressed)
            isRightPressed = false;
          else
            isRightPressed = true;
        }
        break;
        }
      }
      break;
      }
    }


    window.clear();
    wallsInit.drawWalls(window);
    
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

    lightRays.initRays(Vector2f(mousePos.x, mousePos.y), wallsInit.getWallsVector());
    lightRays.calculateHit(wallsInit.getWallsVector());
    if (isKeyRpressed)
      lightRays.drawRays(window);

    if (isRightPressed)
    {
      lightRays.fillArea(window);
    }

    lightRays.clearRayVector();
    window.display();
  }
  return 0;
}
