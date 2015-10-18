#ifndef PLANE_H
#define PLANE_H

#include "object.h"

/**
 * @brief The Plane class represents a plane with its boundarys
 * A plane is not infinte and is limited to rectangular shape.
 * A corner is placed at the origin of the local coordinate
 * system and the rectangle is along the x and y axis.
 * Its normal is along the z axis.
 */
class Plane : public Object
{

public:
    /**
     * @brief Plane constructor
     * @param sizex is the size along the x axis
     * @param sizey is the size along the y axis
     * @param x is the first component of the position
     * @param y is the second component of the position
     * @param z is the third component of the position
     * @param angle is the angle of the rotation
     * @param a is the first component of the axis of the rotation
     * @param b is the second component of the axis of the rotation
     * @param c is the third component of the axis of the rotation
     * @param mat is the material
     */
    Plane(double sizex, double sizey,
          double x, double y, double z,
          double angle, double a, double b, double c,
          const Material &mat);

    /**
     * @brief intersected. See Object class.
     */
    virtual bool intersected(const Ray &ray, Point &intersection, Direction &normal, double &param) const;

protected:
    /**
     * @brief m_size contains the size along the x and y axis
     */
    double m_size[2];
};

#endif // PLANE_H
