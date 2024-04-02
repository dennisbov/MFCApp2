#pragma once
#include "Dot.h"
#include "PointMath.h"

struct PointT
{
	PointMath point;
	Dot drawable;

	PointT(PointMath point, Color color, REAL radius);
	PointT();
};

