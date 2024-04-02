#pragma once
#include <gdiplus.h>

using namespace Gdiplus;

class Drawable
{
protected:
	Color color;
	REAL radius;
public:
	Drawable(Color color, REAL radius);
	Drawable();
	virtual void Draw(Graphics& graphics) = 0;
};

