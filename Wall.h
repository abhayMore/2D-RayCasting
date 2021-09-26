#pragma once
#include "segment.h"

class Wall
{
	std::vector<segment> Walls;
	sf::VertexArray wallsLine;

public:
	Wall(int, int);

	void drawWalls(sf::RenderWindow&);

	std::vector<segment> getWallsVector();

};