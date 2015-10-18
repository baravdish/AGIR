#ifndef VECTOR_H
#define VECTOR_H

class Direction;
class Point;
class Matrix;

/**
 * @brief The Vector class represent a 3D vector
 */
class Vector
{
public:
    /**
     * @brief Vector constructor from 3 values
     */
    Vector(double a = 0.0, double b = 0.0, double c = 0.0);

    /**
     * @brief Vector copy constructor
     */
    Vector(const Vector& v);

    /**
     * @brief Vector constructor from a Direction
     */
    Vector(const Direction& dir);

    /**
     * @brief operator * between a scalar and a vector
     * @return val*v
     */
    friend Vector& operator*(const double val, const Vector &v);

    /**
     * @brief length computes the length of the vector
     * @return the length of the vector
     */
    double length()const;

    /**
     * @brief x is the x component of the vector
     */
    double x;

    /**
     * @brief y is the y component of the vector
     */
    double y;

    /**
     * @brief z is the z component of the vector
     */
    double z;
};

#endif // VECTOR_H
