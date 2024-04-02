#include "pch.h"
#include "MultiplePolygonDrawable.h"

MultiplePolygonDrawable::MultiplePolygonDrawable()
{
	polygons = std::vector<std::vector<PointMath>>(1000, std::vector<PointMath>());
	colors = std::vector<Color>{
		Color(255, 0, 0), 
		Color(0, 255, 0),
		Color(0, 0, 255), 
		Color(255, 0, 0),
		Color(255, 255, 0),
		Color(0, 255, 255)
	};
}

void MultiplePolygonDrawable::Draw(Graphics& graphics)
{
	Point edges[100];
	Color randomColor = pickRandomColor();
	SolidBrush brush(colors[0]);
	for (int i = 0; i < polygons.size(); i++)
	{
		for (int j = 0; j < polygons[i].size(); j++)
		{
			edges[j] = polygons[i][j];
		}
		brush.SetColor(colors[i]);
		graphics.FillPolygon(&brush, edges, polygons[i].size());
	}
}

Color MultiplePolygonDrawable::pickRandomColor()
{
	return Color(std::rand() % 255, std::rand() % 255, std::rand() % 255);
}
