#include "Wall.h"

Wall::Wall(const float x1, const float y1,const float x2, const float y2):stPoint(x1,y1), endPoint(x2,y2) , wall(sf::Lines, 2)
{
  wall[0].position = stPoint;
  wall[1].position = endPoint;
}

sf::Vector2f Wall::getStartPoint()
{
  return stPoint;
}

sf::Vector2f Wall::getEndPoint()
{
  return endPoint;
}

void Wall::Draw(sf::RenderWindow& window)
{
  window.draw(wall);
}
