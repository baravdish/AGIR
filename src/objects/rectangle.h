#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "object.h"
#include "box.h"

/**
 * @brief The Rectangle class represents a 3D-rectangular shape.
 * A corner is situated at the origin of the local coordinate system.
 * The rectangle extends itself toward the x, y, and z directions of the local coordinate system.
 */
class Rectangle : public Object
{
public:
    /**
     * @brief Rectangle constructor
     * @param sizex is the size along the x axis
     * @param sizey is the size along the y axis
     * @param sizez is the size along the z axis
     * @param x is the first component of the position
     * @param y is the second component of the position
     * @param z is the third component of the position
     * @param angle is the angle of the rotation
     * @param a is the first component of the axis of the rotation
     * @param b is the second component of the axis of the rotation
     * @param c is the third component of the axis of the rotation
     * @param mat is the material
     */
    Rectangle(double sizex, double sizey, double sizez,
          double x, double y, double z,
          double angle, double a, double b, double c,
          const Material &mat);

    ~Rectangle();

    /**
     * @brief intersected. See Object class.
     */
    virtual bool intersected(const Ray &ray, Point &intersection, Direction &normal, double &param) const;

protected:
    /**
     * @brief m_box is exactly the rectangle itself
     * So, its algorithms are re-used here
     */
    Box m_box;

    /**
     * @brief m_size contains the sizes toward all 3 directions
     */
    double m_size[3];

};

#endif // RECTANGLE_H
