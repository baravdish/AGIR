#ifndef DIRECTION_H
#define DIRECTION_H

class Point;
class Vector;
class Matrix;

/**
 * @brief The Direction class represents a 1-length 3D vector.
 * The 1-length condition is always verified.
 */
class Direction
{
public:
    /**
     * @brief Direction constructor from 3 values
     * The vector is normalized if the norm is not equal to 1
     */
    Direction(double a = 0.0, double b = 0.0, double c = 1.0);

    /**
     * @brief Direction copy constructor
     */
    Direction(const Direction &dir);

    /**
     * @brief Direction constructor from a Point
     * @param pt
     */
    Direction(const Point &pt);

    /**
     * @brief Direction constructor from a Vector
     * @param v
     */
    Direction(const Vector &v);

    /**
     * @brief x component accessor
     * @return m_x
     */
    double x()const;

    /**
     * @brief y component accessor
     * @return m_y
     */
    double y()const;

    /**
     * @brief z component accessor
     * @return m_z
     */
    double z()const;

    Direction& operator-()const;

    friend double operator*(const Direction &dir1, const Direction &dir2);

    /**
     * @brief operator *= multiplies a matrix with this direction
     * @return mat * this
     */
    Direction& operator*=(const Matrix &mat);

    /**
     * @brief setXYZ modifies the 3 components
     * The vector is normalized if the norm is not equal to 1
     */
    void setXYZ(double a, double b, double c);

protected:
    /**
     * @brief m_x is the x component of the direction
     */
    double m_x;

    /**
     * @brief m_y is the y component of the direction
     */
    double m_y;

    /**
     * @brief m_z is the z component of the direction
     */
    double m_z;

};

#endif // DIRECTION_H
