#include "pch.h"
#include "PolygonDrawable.h"

PolygonDrawable::PolygonDrawable(std::vector<PointMath> edges, Color borderColor, Color mainColor, REAL borderWidth)
	: Drawable::Drawable(mainColor, borderWidth)
{
	this->edges = edges;
	this->borderColor = borderColor;
}

PolygonDrawable::PolygonDrawable() : Drawable::Drawable()
{
	this->edges = std::vector<PointMath>(100, PointMath());
	this->borderColor = Color(0, 0, 0);
}

void PolygonDrawable::Draw(Graphics& graphics)
{
	Pen pen(borderColor);
	SolidBrush brush(color);
	graphics.DrawPolygon(&pen, pointsArray, edgesCount);
	graphics.FillPolygon(&brush, pointsArray, edgesCount);
}

void PolygonDrawable::SetDrawSettings(std::vector<PointMath> edges, Color borderColor, Color mainColor, REAL borderWidth)
{
	this->borderColor = borderColor;
	this->color = mainColor;
	this->radius = borderWidth;
	MathFunctions::polarSorting(edges);
	for (int i = 0; i < edges.size(); i++)
	{
		pointsArray[i] = edges[i];
	}
}

