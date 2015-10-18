#ifndef SYSTEM_H
#define SYSTEM_H

#include "matrix.h"
#include "vector.h"

class Point;
class Direction;
class Ray;

/**
 * @brief The System class defines a local system coordinate.
 * Its translation and its rotation permit to define a new referencial
 * in relative to a previous one. For example, the scene has a system coordinate
 * relative to the world system coordinate. An object of the scene has a coordinate
 * system ralative to the system coordinate of the scene.
 */
class System
{
public:
    /**
     * @brief System constructor
     * @param x is the translation along the x axis
     * @param y is the translation along the y axis
     * @param z is the translation along the z axis
     * @param angle is the angle of the rotation
     * @param a is the first component of the axis of the rotation
     * @param b is the second component of the axis of the rotation
     * @param c is the third component of the axis of the rotation
     */
    System(double x = 0, double y = 0, double z = 0, double angle = 0, double a = 1, double b = 0, double c = 0);

    /**
     * @brief convertToSystem transforms previous coordinates of a point and a vector to new coordinates
     * according to this system coordinate.
     * @param point is a point to transform (the origin of a ray)
     * @param direction is a direction to transform (the direction of a ray)
     */
//    void convertToSystem(Point &point, Direction &direction)const;

    /**
     * @brief convertFromSystem transforms current coordinates of a point and a vector to old coordinates
     * according to the previous system coordinate
     * @param point is a point to transform (intersection)
     * @param direction is a direction to transform (normal)
     */
    void convertFromSystem(Point &point, Direction &direction)const;

    /**
     * @brief convertToSystem ransforms previous coordinates of a ray to new coordinates
     * @param ray is the ray to transform
     */
    void convertToSystem(Ray &ray)const;

protected:

    /**
     * @brief m_trans is the vector of translation
     */
    Vector m_translation;

    /**
     * @brief m_rotation is the matrice of rotation
     */
    Matrix m_rotation;

    /**
     * @brief m_rotationInverse is the inverse of the matrice of rotation
     */
    Matrix m_rotationInverse;

    /**
     * @brief noRotation indicates if no rotation has to be done (to go faster)
     */
    bool m_noRotation;
};

#endif // SYSTEM_H
