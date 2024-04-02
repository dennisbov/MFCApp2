#include "pch.h"
#include "PointT.h"


PointT::PointT(PointMath point, Color color, REAL radius) {
	this->point = point;
	drawable = Dot(round(point.x), round(point.y), color, radius);
}
PointT::PointT() {
	point = PointMath();
	drawable = Dot();
}