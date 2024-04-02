#pragma once
#include <gdiplus.h>
struct PointMath
{
	float x;
	float y;
	
	PointMath(float x, float y);
	PointMath();

	operator Gdiplus::Point() const;
};

