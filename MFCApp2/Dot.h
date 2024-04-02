#pragma once
#include "Drawable.h"
class Dot :
    public Drawable
{
private:
	int x;
	int y;
public:
	Dot(LONG x, LONG y, Color color, REAL radius);
	Dot();
	void Draw(Graphics& graphics);
};

