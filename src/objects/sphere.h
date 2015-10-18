#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"

/**
 * @brief The Sphere class represents a sphere of a given radius.
 * The sphere is centered in the origin of its local coordinate system.
 */
class Sphere : public Object
{
public:
    /**
     * @brief Sphere constructor
     * @param r is the radius of the sphere
     * @param x is the first component of the position
     * @param y is the second component of the position
     * @param z is the third component of the position
     * @param mat is the material of the sphere
     */
    Sphere(double r, double x, double y, double z, const Material &mat);

    /**
     * @brief intersected. See Object class.
     */
    virtual bool intersected(const Ray &ray, Point &intersection, Direction &normal, double &param) const;

protected:
    /**
     * @brief m_radius is the radius of the sphere
     */
    double m_radius;

};

#endif // SPHERE_H
