#pragma once
#include <vector>

struct SimplePoint
{
	int x, y, val;
	SimplePoint() {}
	SimplePoint(int X, int Y, int value) { x = X; y = Y; val = value; }
	std::vector<SimplePoint*> neighbours;
};
