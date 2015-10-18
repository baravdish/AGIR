#include "vector.h"
#include "direction.h"
#include "point.h"
#include <cmath>

Vector::Vector(double a, double b, double c) : x(a), y(b), z(c)
{

}

Vector::Vector(const Vector &v) : x(v.x), y(v.y), z(v.z)
{

}

Vector::Vector(const Direction &dir) : x(dir.x()), y(dir.y()), z(dir.z())
{

}

Vector& operator*(const double val, const Vector &v)
{
    Vector *tmp = new Vector;
    tmp->x = val*v.x;
    tmp->y = val*v.y;
    tmp->z = val*v.z;
    return *tmp;
}

double Vector::length()const
{
    return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}
