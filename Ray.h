#pragma once

#include "segment.h"


class Ray
{
  std::vector<segment> Rays;
  sf::VertexArray Line;

public:
  Ray();

  void initRays(Vector2f , std::vector<segment> );

  void drawRays(sf::RenderWindow& );

  void calculateHit(std::vector<segment>);

  std::pair<Vector2f, float> getIntersection(segment, segment);

  void fillArea(sf::RenderWindow& window);

  void clearRayVector();

};