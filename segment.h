#pragma once
#include "Vector2.h"

class segment {
public:

	Vector2f v1;
	Vector2f v2;

public:
	segment();
	segment(Vector2f vec1, Vector2f vec2);
};