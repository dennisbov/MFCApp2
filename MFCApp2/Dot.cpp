#include "pch.h"
#include "Dot.h"
Dot::Dot(LONG x, LONG y, Color color, REAL radius) : Drawable(color, radius){
		this->x = x;
		this->y = y;
	}
Dot::Dot() :Drawable() {
		x = 0;
		y = 0;
	}
void Dot::Draw(Graphics& graphics){
		SolidBrush brush(color);
		graphics.FillEllipse(&brush, x - radius / 2, y - radius / 2, radius, radius);
	}