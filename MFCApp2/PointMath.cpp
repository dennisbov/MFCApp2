#include "pch.h"
#include "PointMath.h"

PointMath::PointMath(float x, float y)
{
	this->x = x;
	this->y = y;
}

PointMath::PointMath()
{
	this->x = 0;
	this->y = 0;
}

PointMath::operator Gdiplus::Point() const
{
	return Gdiplus::Point(x, y);
}



