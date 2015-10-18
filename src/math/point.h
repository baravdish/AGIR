#ifndef POINT_H
#define POINT_H

class Vector;
class Direction;
class Matrix;

/**
 * @brief The Point class represents a 3D-space point
 */
class Point
{
public:
    /**
     * @brief Point constructor from 3 values
     */
    Point(double a = 0.0, double b = 0.0, double c = 0.0);

    /**
     * @brief Point copy constructor
     */
    Point(const Point &p);

    Point& operator-=(const Vector&v);
    Point& operator+=(const Vector&v);
    Point& operator+(const Vector&v);

    /**
     * @brief operator *= multiplies a matrix with this point
     * @return mat * this
     */
    Point& operator*=(const Matrix &mat);

    /**
     * @brief operator - between two Points
     * @return the vector from pt2 to pt1
     */
    friend Vector& operator-(const Point &pt1, const Point &pt2);

    /**
     * @brief x is the x component of the point
     */
    double x;

    /**
     * @brief y is the y component of the point
     */
    double y;

    /**
     * @brief z is the z component of the point
     */
    double z;
};

#endif // POINT_H
