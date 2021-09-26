#include "segment.h"

segment::segment() : v1(0,0), v2(0,0)
{
	
}

segment::segment(Vector2f vec1, Vector2f vec2) 
{
	v1.x = vec1.x;
	v1.y = vec1.y;

	v2.x = vec2.x;
	v2.y = vec2.y;
}