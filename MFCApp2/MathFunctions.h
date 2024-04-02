#pragma once
#include "PointMath.h"
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class MathFunctions
{
private:
	static double angle(const PointMath& p1, const PointMath& p2);
	static PointMath getCenterOfMass(const std::vector<PointMath>& polygon);
	static bool comparePoints(const PointMath& p1, const PointMath& p2, const PointMath& center);
	static int signum(double number);
	static double min_finder(double a, double b);
	static double max_finder(double a, double b);
public:
	static void polarSorting(vector<PointMath>& polygon);
	static bool even_odd_rule(PointMath point, const vector<PointMath>& polygon);
	static double d(PointMath A, PointMath B);
	static bool lines_intersection(PointMath x_1_y_1, PointMath x_2_y_2, PointMath x_3_y_3, PointMath x_4_y_4, PointMath& intersection_xy_begin, PointMath& intersection_xy_end, bool& flag_of_segments);
	static double so_called_shoelace_formula(vector<PointMath> vector_);
};


