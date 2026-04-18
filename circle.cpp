#include "circle.h"

void Circle::draw() const
{
	DrawCircle(x, y, r, color);
}
