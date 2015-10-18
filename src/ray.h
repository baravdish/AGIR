#ifndef RAY_H
#define RAY_H

#include "point.h"
#include "direction.h"

/**
 * @brief The Ray class represents a ray by its origin point and a direction vector
 */
class Ray
{
public:
    /**
     * @brief Ray constructor from 3 values for the origin and 3 values for the direction
     */
    Ray(double ptx = 0.0, double pty = 0.0, double ptz = 0.0,
        double dx = 0.0, double dy = 0.0, double dz = 1.0);

    /**
     * @brief Ray constructor from a Point and a Direction
     */
    Ray(Point &pt, Direction &dir);

    /**
     * @brief origin is the origin point of the ray
     */
    Point origin;

    /**
     * @brief direction is the direction vector of the ray
     */
    Direction direction;

};

#endif // RAY_H
