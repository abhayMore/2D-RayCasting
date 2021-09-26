#include "Wall.h"

int ReturnIntRandom(int lower, int upper)
{
	return (rand() % (upper - lower + 1)) + lower;
}

Wall::Wall(int WIDTH,int HEIGHT) :wallsLine(sf::Lines, 2)
{
	//Boundry Coordinates;
	Walls.push_back(segment(Vector2f(1, 1), Vector2f(WIDTH, 1)));
	Walls.push_back(segment(Vector2f(WIDTH, 1), Vector2f(WIDTH, HEIGHT)));
	Walls.push_back(segment(Vector2f(WIDTH, HEIGHT), Vector2f(1, HEIGHT)));
	Walls.push_back(segment(Vector2f(1, HEIGHT), Vector2f(1, 1)));

	

	Walls.push_back(segment(Vector2f(572, 220), Vector2f(230, 149)));
	Walls.push_back(segment(Vector2f(317, 708), Vector2f(268, 750)));
	Walls.push_back(segment(Vector2f(282, 279), Vector2f(729, 448)));
	Walls.push_back(segment(Vector2f(93, 160), Vector2f(108, 746)));

}

void Wall::drawWalls(sf::RenderWindow& window)
{
	for (int i = 0; i < Walls.size(); i++)
	{
		wallsLine[0].position = sf::Vector2f(Walls[i].v1.x, Walls[i].v1.y);
		wallsLine[1].position = sf::Vector2f(Walls[i].v2.x, Walls[i].v2.y);
		window.draw(wallsLine);
	}
}

std::vector<segment> Wall::getWallsVector()
{
	return Walls;
}