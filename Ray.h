#ifndef RAY_H
#define RAY_H
#include "Wall.h"
#include "SFML/Graphics.hpp"

class Ray{
private:
  sf::Vector2f rayPosition, rayDirection, DirPosition;
  sf::VertexArray Line;

public:
  Ray(sf::Vector2f rPos, float Angle);

  void initRayDirPosition();
  void setRayDirPos(sf::Vector2f XY);
  void setRayPosition(sf::Vector2f XY);

  sf::Vector2f Cast(Wall& wall);
  void CalculateHit(std::vector<Wall> walls);

  void Update();
  void Draw(sf::RenderWindow& window);

};

#endif //RAY_H
