#pragma once

#include "raylib.h"

struct Circle
{
	float x, y;
	int r;
	Color color;

	void draw() const;
};
