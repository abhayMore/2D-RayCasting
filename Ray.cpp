#include "Ray.h"

bool comparator(segment R1, segment R2)
{
  Vector2f a = R1.v2.sub(R1.v1);
  Vector2f b = R2.v2.sub(R2.v1);


  if ((float)a.getAngle() < (float)b.getAngle()) {
    return 0;
  }
  if ((float)a.getAngle() > (float)b.getAngle())
  {
    return 1;
  }

  return 0;
}

Ray::Ray():Line(sf::Lines, 2)
{}

void Ray::initRays(Vector2f mousePos, std::vector<segment> Walls)
{
  for (int i = 0; i < Walls.size(); i++)
  {
    Vector2f a = Vector2f(mousePos.x, mousePos.y);
    
    Vector2f b = Walls[i].v1;
    Vector2f c = b.sub(a).mult(100);

    Vector2f d = Walls[i].v2;
    Vector2f e = d.sub(a).mult(100);

    float offset = 0.00001f;
    segment s1 = segment(a, b);
    segment s2 = segment(a, a.add(c.setDir(c.getAngle() + offset)));
    segment s3 = segment(a, a.add(e.setDir(e.getAngle() - offset)));

    segment s4 = segment(a, d);
    segment s5 = segment(a, a.add(c.setDir(c.getAngle() - offset)));
    segment s6 = segment(a, a.add(e.setDir(e.getAngle() + offset)));


    Rays.push_back(s2);
    Rays.push_back(s1);
    Rays.push_back(s3);

    Rays.push_back(s6);
    Rays.push_back(s4);
    Rays.push_back(s5);

  }
}

std::pair<Vector2f, float> Ray::getIntersection(segment s1, segment s2)
{
  Vector2f p = s1.v1;
  Vector2f q = s2.v1;
  Vector2f r = s1.v2.sub(s1.v1);
  Vector2f s = s2.v2.sub(s2.v1);

  float t = (q.crossProduct(s) - p.crossProduct(s)) / r.crossProduct(s);
  float u = (p.crossProduct(r) - q.crossProduct(r)) / s.crossProduct(r);

  if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
    return std::make_pair(Vector2f(p.x + t * r.x, p.y + t * r.y), t);
  }
  return std::make_pair(Vector2f(0.0f, 0.0f), 0.0f);
}


void Ray::calculateHit(std::vector<segment> Walls)
{
  for (int j = 0; j < Rays.size(); j++)
  {
    segment ray = Rays[j];
    Vector2f closest = ray.v2;

    float distToIntersect = FLT_MAX;

    for (int i = 0; i < Walls.size(); i++)
    {
      std::pair<Vector2f, float> inter = getIntersection(Rays[j], Walls[i]);

      if (inter.first.x > 0.0f && inter.first.y > 0.0f)
      {
        float d = inter.second;

        if (distToIntersect > d)
        {
          distToIntersect = d;
          closest = inter.first;
        }
      }
    }

    Rays[j].v2 = closest;

  }
}

void Ray::drawRays(sf::RenderWindow& window)
{
  for (int i = 0; i < Rays.size(); i++)
  {
    Line[0].position = sf::Vector2f(Rays[i].v1.x, Rays[i].v1.y);
    Line[1].position = sf::Vector2f(Rays[i].v2.x, Rays[i].v2.y);
    window.draw(Line);
  }
}

void Ray::fillArea(sf::RenderWindow& window)
{
  sort(Rays.begin(), Rays.end(), comparator);
  for (int i = 0; i < Rays.size(); i++)
  {
    sf::ConvexShape Tria(3);
    if (i == Rays.size() - 1)
    {
      Tria.setPoint(0, sf::Vector2f(Rays[Rays.size() - 1].v2.x, Rays[Rays.size() - 1].v2.y));
      Tria.setPoint(1, sf::Vector2f(Rays[Rays.size() - 1].v1.x, Rays[Rays.size() - 1].v1.y));
      Tria.setPoint(2, sf::Vector2f(Rays[0].v2.x, Rays[0].v2.y));

    }
    else
    {
      Tria.setPoint(0, sf::Vector2f(Rays[i].v2.x, Rays[i].v2.y));
      Tria.setPoint(1, sf::Vector2f(Rays[i].v1.x, Rays[i].v1.y));
      Tria.setPoint(2, sf::Vector2f(Rays[i + 1].v2.x, Rays[i + 1].v2.y));
    }

    Tria.setFillColor(sf::Color(255, 255, 255, 220));
    window.draw(Tria);
  }
}

void Ray::clearRayVector()
{
  Rays.clear();
}