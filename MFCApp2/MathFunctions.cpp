#include "pch.h"
#include "MathFunctions.h"

double MathFunctions::angle(const PointMath& p1, const PointMath& p2) {
    return std::atan2(p2.y - p1.y, p2.x - p1.x);
}

PointMath MathFunctions::getCenterOfMass(const std::vector<PointMath>& polygon) {
    float cx = 0.0, cy = 0.0;
    for (const PointMath& point : polygon) {
        cx += point.x;
        cy += point.y;
    }
    cx /= polygon.size();
    cy /= polygon.size();
    return { cx, cy };
}

bool MathFunctions::comparePoints(const PointMath& p1, const PointMath& p2, const PointMath& center) {
    double angle1 = angle(center, p1);
    double angle2 = angle(center, p2);
    return angle1 < angle2;
}

void MathFunctions::polarSorting(vector<PointMath>& polygon)
{
    if (polygon.size() < 3) {
        return;
    }

    PointMath center = getCenterOfMass(polygon);
    std::sort(polygon.begin(), polygon.end(), [&](const PointMath& p1, const PointMath& p2) {
        return comparePoints(p1, p2, center);
    });
}

bool MathFunctions::even_odd_rule(PointMath point, const vector<PointMath>& polygon)
{
    bool inside = false;
    int pointsNumber = polygon.size();

    for (int i = 0, j = pointsNumber - 1; i < pointsNumber; j = i++) {
        if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
            (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }

    return inside;
}

double MathFunctions::d(PointMath A, PointMath B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

bool MathFunctions::lines_intersection(PointMath x_1_y_1, PointMath x_2_y_2, PointMath x_3_y_3, PointMath x_4_y_4, PointMath& intersection_xy_begin, PointMath& intersection_xy_end, bool& flag_of_segments) {
    double A_1, B_1, C_1;
    A_1 = x_1_y_1.y - x_2_y_2.y;//y_1 - y_2;
    B_1 = x_2_y_2.x - x_1_y_1.x;//x_2 - x_1;
    C_1 = x_1_y_1.x * x_2_y_2.y - x_2_y_2.x * x_1_y_1.y; //x_1 * y_2 - x_2 * y_1;
    double A_2, B_2, C_2;
    A_2 = x_3_y_3.y - x_4_y_4.y;
    B_2 = x_4_y_4.x - x_3_y_3.x;
    C_2 = x_3_y_3.x * x_4_y_4.y - x_4_y_4.x * x_3_y_3.y;
    double determinant;
    determinant = A_1 * B_2 - A_2 * B_1;
    //A_1x + B_1y + C_1 = 0 & A_2x + B_2y + C_2 = 0
    if (determinant == 0) {

        double Frankenstein_segment_x, sum_of_segment_x_lenghts, Frankenstein_segment_y, sum_of_segment_y_lenghts;
        Frankenstein_segment_x = max_finder(max_finder(x_1_y_1.x, x_2_y_2.x), max_finder(x_3_y_3.x, x_4_y_4.x)) -
            min_finder(min_finder(x_1_y_1.x, x_2_y_2.x), min_finder(x_3_y_3.x, x_4_y_4.x));
        Frankenstein_segment_y = max_finder(max_finder(x_1_y_1.y, x_2_y_2.y), max_finder(x_3_y_3.y, x_4_y_4.y)) -
            min_finder(min_finder(x_1_y_1.y, x_2_y_2.y), min_finder(x_3_y_3.y, x_4_y_4.y));
        sum_of_segment_x_lenghts = (max_finder(x_1_y_1.x, x_2_y_2.x) - min_finder(x_1_y_1.x, x_2_y_2.x)) +
            (max_finder(x_3_y_3.x, x_4_y_4.x) - min_finder(x_3_y_3.x, x_4_y_4.x));
        sum_of_segment_y_lenghts = (max_finder(x_1_y_1.y, x_2_y_2.y) - min_finder(x_1_y_1.y, x_2_y_2.y)) +
            (max_finder(x_3_y_3.y, x_4_y_4.y) - min_finder(x_3_y_3.y, x_4_y_4.y));
        if (Frankenstein_segment_x > sum_of_segment_x_lenghts || Frankenstein_segment_y > sum_of_segment_y_lenghts) {
            return false;
        }

        if ((Frankenstein_segment_x == sum_of_segment_x_lenghts && B_1 != 0 && B_2 != 0) || (Frankenstein_segment_y == sum_of_segment_y_lenghts) && A_1 != 0 && A_2 != 0) {
            intersection_xy_begin = PointMath(max_finder(min_finder(x_3_y_3.x, x_4_y_4.x), min_finder(x_1_y_1.x, x_2_y_2.x)), max_finder(min_finder(x_3_y_3.y, x_4_y_4.y), min_finder(x_1_y_1.y, x_2_y_2.y)));

            return true;
        }
        if (Frankenstein_segment_x < sum_of_segment_x_lenghts || Frankenstein_segment_y < sum_of_segment_y_lenghts) {

            flag_of_segments = true;
            intersection_xy_begin = PointMath(max_finder(min_finder(x_3_y_3.x, x_4_y_4.x), min_finder(x_1_y_1.x, x_2_y_2.x)), max_finder(min_finder(x_3_y_3.y, x_4_y_4.y), min_finder(x_1_y_1.y, x_2_y_2.y)));
            intersection_xy_end = PointMath(min_finder(max_finder(x_1_y_1.x, x_2_y_2.x), max_finder(x_3_y_3.x, x_4_y_4.x)), min_finder(max_finder(x_1_y_1.y, x_2_y_2.y), max_finder(x_3_y_3.y, x_4_y_4.y)));
            return true;
        }
        return false;
    }
    else {
        double x_, y_;

        x_ = (B_1 * C_2 - B_2 * C_1) / determinant;
        y_ = (A_2 * C_1 - A_1 * C_2) / determinant;
        intersection_xy_begin = PointMath(x_, y_);

        if (((d(x_1_y_1, intersection_xy_begin) <= d(x_1_y_1, x_2_y_2)) && (d(x_2_y_2, intersection_xy_begin) <= d(x_1_y_1, x_2_y_2)))
            && ((d(x_3_y_3, intersection_xy_begin) <= d(x_3_y_3, x_4_y_4)) && (d(x_4_y_4, intersection_xy_begin) <= d(x_3_y_3, x_4_y_4)))) {

            return true;
        }
        else {
            return false;
        }
    }
}

double MathFunctions::so_called_shoelace_formula(vector<PointMath> vector_) { //Gauss's area formula
    double sum_of_coordinates = 0;
    for (int i = 0; i < (vector_.size()) - 1; i++) {
        sum_of_coordinates = sum_of_coordinates + vector_[i].x * vector_[i + 1].y;
    }
    sum_of_coordinates = sum_of_coordinates + vector_[(vector_.size()) - 1].x * vector_[0].y - vector_[0].x * vector_[(vector_.size()) - 1].y;
    for (int i = 0; i < (vector_.size()) - 1; i++) {
        sum_of_coordinates = sum_of_coordinates - vector_[i + 1].x * vector_[i].y;
    }
    return 0.5 * abs(sum_of_coordinates);
}

int MathFunctions::signum(double number) {
    return (int)(number / abs(number));
};

double MathFunctions::min_finder(double a, double b) {
    if (a <= b) {
        return a;
    }
    else {
        return b;
    }
}

double MathFunctions::max_finder(double a, double b) {
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}