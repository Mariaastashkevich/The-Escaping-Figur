#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
struct Point{
    Point(double x, double y);
    Point();
    double x_;
    double y_;
};

class Vector
{
public:
   explicit Vector(double x, double y);
     Vector(const Vector& other);
    Vector();
    double scale();
    Vector vector_by_scale(double scale);
    Vector operator+( Vector& other);
    Vector& operator=(const Vector &othr);
    Point vector;
};

#endif // VECTOR_H
