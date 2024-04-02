#include "pch.h"
#include "Drawable.h"
Drawable::Drawable(Color color, REAL radius) {
	this->color = color;
	this->radius = radius;
}
Drawable::Drawable() {
	color = Color(0, 0, 0);
	radius = 0;
}
