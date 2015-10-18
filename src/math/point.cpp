#include "point.h"
#include "vector.h"
#include "matrix.h"
#include <cmath>

Point::Point(double a, double b, double c) : x(a), y(b), z(c)
{

}

Point::Point(const Point &p) : x(p.x), y(p.y), z(p.z)
{

}

Point& Point::operator-=(const Vector &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Point& Point::operator+=(const Vector &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Point& Point::operator+(const Vector &v)
{
    Point *tmp = new Point(*this);
    (*tmp) += v;
    return *tmp;
}

Vector& operator-(const Point &pt1, const Point &pt2)
{
    Vector *tmp = new Vector;
    tmp->x = pt1.x - pt2.x;
    tmp->y = pt1.y - pt2.y;
    tmp->z = pt1.z - pt2.z;
    return *tmp;
}

Point& Point::operator*=(const Matrix &mat)
{
    Point tmp(*this);
    x = mat(0,0)*tmp.x + mat(0,1)*tmp.y + mat(0,2)*tmp.z;
    y = mat(1,0)*tmp.x + mat(1,1)*tmp.y + mat(1,2)*tmp.z;
    z = mat(2,0)*tmp.x + mat(2,1)*tmp.y + mat(2,2)*tmp.z;
    return *this;
}



