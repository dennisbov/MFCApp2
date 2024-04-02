#include "pch.h"
#include "InterseptionCalculator.h"
#include <algorithm>
#include <cmath>
#include "MathFunctions.h"

InterseptionCalculator::InterseptionCalculator(Drawer* drawer)
{
    this->drawer = drawer;
}

InterseptionCalculator::InterseptionCalculator()
{
    this->drawer = nullptr;
}

void InterseptionCalculator::RedrawInterseñtions(const vector<vector<PointMath>>& polygons, int polygonsNumber)
{
    visualization.polygons = vector<vector<PointMath>>();

    if (polygonsNumber <= 1) {
        return;
    }
    drawer->RemoveDrawable(&visualization);
    currentInterseption = polygons[0];
    vector<vector<PointMath>> interseptions(polygonsNumber-1, vector<PointMath>());
    int lastintersectionIndex = 0;
    MathFunctions::polarSorting(currentInterseption);
    for (int i = 1; i < polygonsNumber; i++)
    {
        interseptions[lastintersectionIndex] = calculateIntersection(currentInterseption, polygons[i]);
        currentInterseption = interseptions[lastintersectionIndex];
        lastintersectionIndex++;
    }
    this->interseptions = interseptions;
    visualization.polygons = interseptions;
    drawer->AddDrawable(&visualization);
}

vector<PointMath> InterseptionCalculator::calculateIntersection(vector<PointMath> polygon1, vector<PointMath> polygon2)
{
    vector<PointMath> intersection(100, PointMath());
    int lastIntersectionPointIndex = 0;

    MathFunctions::polarSorting(polygon1);
    MathFunctions::polarSorting(polygon2);

    for (int i = 0; i < polygon1.size(); i++)
    {
        if (MathFunctions::even_odd_rule(polygon1[i], polygon2)) {
            intersection[lastIntersectionPointIndex] = polygon1[i];
            lastIntersectionPointIndex++;
        }
    }
    for (int i = 0; i < polygon2.size(); i++)
    {
        if (MathFunctions::even_odd_rule(polygon2[i], polygon1)) {
            intersection[lastIntersectionPointIndex] = polygon2[i];
            lastIntersectionPointIndex++;
        }
    }

    for (int i = 0; i < polygon1.size(); i++)
    {
        for (int j = 0; j < polygon2.size(); j++)
        {
            PointMath intersectionEdge;
            PointMath additionalEdge;
            bool isAdditionalEdgeNeeded;
            if (MathFunctions::lines_intersection(
                polygon1[i], 
                polygon1[i + 1 == polygon1.size() ? 0 : i + 1],
                polygon2[j], 
                polygon2[j + 1 == polygon2.size() ? 0 : j + 1],
                intersectionEdge, additionalEdge, isAdditionalEdgeNeeded)) {
                intersection[lastIntersectionPointIndex] = intersectionEdge;
                lastIntersectionPointIndex++;
                /*if (isAdditionalEdgeNeeded) {
                    intersection[lastIntersectionPointIndex] = additionalEdge;
                    lastIntersectionPointIndex++;
                }*/
            }
        }
    }
    intersection.resize(lastIntersectionPointIndex);
    MathFunctions::polarSorting(intersection);
    return intersection;
}
