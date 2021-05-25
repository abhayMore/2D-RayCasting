#include "Ray.h"
#include <cmath>
#include <cfloat>


template<class T>
float dist( sf::Vector2<T> a, sf::Vector2<T> b)
{
  T DiffX = a.x - b.x;
  T DiffY = a.y - b.y;
  return sqrt(DiffX * DiffX + DiffY * DiffY);
}

Ray::Ray(sf::Vector2f rPos, float Angle): rayPosition(rPos), Line(sf::Lines,2)
{
  rayDirection = sf::Vector2f(cos(Angle), sin(Angle)) *3000.f ;
  Line[0].color = sf::Color(255,255,255,20);
  Line[1].color = sf::Color(255,255,255,20);
}
void Ray::initRayDirPosition()
{
  DirPosition = rayPosition + rayDirection;
}
void Ray::setRayDirPos(sf::Vector2f XY)
{
  DirPosition = XY;
}
void Ray::setRayPosition(sf::Vector2f XY)
{
  rayPosition = XY;
  initRayDirPosition();
}
sf::Vector2f Ray::Cast(Wall& wall)
{
  float x1 = wall.getStartPoint().x;
  float y1 = wall.getStartPoint().y;

  float x2 = wall.getEndPoint().x;
  float y2 = wall.getEndPoint().y;

  float x3 = rayPosition.x;
  float y3 = rayPosition.y;

  float x4 = DirPosition.x;
  float y4 = DirPosition.y;

  float D = (x1 - x2) * (y3 - y4) - (y1 - y2)*(x3 - x4);
  if(D == 0)
  {
    return sf::Vector2f(0.f,0.f);
  }

  float T = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / D;
  float U = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / D;

  if(T > 0 &&  T < 1 && U > 0  )
  {
    return sf::Vector2f((x1 + T * (x2 - x1)), (y1 + T * (y2 - y1)));
  }
   else
     return sf::Vector2f(0.f,0.f);
}
void Ray::CalculateHit(std::vector<Wall> walls)
{
  sf::Vector2f closest = sf::Vector2f(0.0f,0.0f);
  float Max = FLT_MAX;
  for(auto& w : walls)
  {
    sf::Vector2f IntPoint = Cast(w);
    if(IntPoint.x > 0.0f && IntPoint.y > 0.0f)
    {
      float Distance = dist(rayPosition, IntPoint);
      if(Distance < Max)
      {
        Max = Distance;
        closest = IntPoint;
      }
    }
  }
  if(closest.x > 0.0f && closest.y > 0.0f)
    setRayDirPos(closest);
}
void Ray::Update()
{
  Line[0].position = rayPosition;
  Line[1].position = DirPosition;
}
void Ray::Draw(sf::RenderWindow& window)
{
  window.draw(Line);
}
