#ifndef WALL_H
#define WALL_H
#include "SFML/Graphics.hpp"

class Wall
{
  sf::Vector2f stPoint, endPoint;
  sf::VertexArray wall;
public:
  Wall(const float x1, const float y1,const float x2, const float y2);

  sf::Vector2f getStartPoint();
  sf::Vector2f getEndPoint();
  void Draw(sf::RenderWindow& window);
};

#endif //WALL_H
