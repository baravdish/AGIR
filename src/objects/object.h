#ifndef OBJECT_H
#define OBJECT_H

#include "system.h"
#include "material.h"

class Ray;

/**
 * @brief The Object class represents an abstract object which can be rendered.
 * Each object is placed in the scene coordinate system.
 * The System of an object can both transform from and to the object local coordinate system
 */
class Object
{
public:
    /**
     * @brief Object constructor
     * @param x is the first component of the position
     * @param y is the second component of the position
     * @param z is the third component of the position
     * @param angle is the angle of the rotation
     * @param a is the first component of the axis of the rotation
     * @param b is the second component of the axis of the rotation
     * @param c is the third component of the axis of the rotation
     * @param mat is the material
     */
    Object(double x, double y, double z,
           double angle, double a, double b, double c,
           const Material &mat);

    virtual ~Object();

    /**
     * @brief intersected computes the intersection between a ray and this object.
     * Basically, this method has to be overloaded in concrete object's classes.
     * @param ray is the ray expressed in the coordinate system of the scene
     * @param intersection stores the computed intersection (it there is one)
     * @param normal stores the normal of the object at the intersection (if there is one)
     * @param param is the ray parameter of the intersection (if there is one)
     * @return true if there is an intersection
     */
    virtual bool intersected(const Ray &ray, Point &intersection, Direction &normal, double &param)const = 0;

    /**
     * @brief material contains the material's informations of the object
     */
    const Material material;

protected:
    /**
     * @brief m_system is the systeme coordinate relative to the scene coordinate system
     */
    System m_system;


};

#endif // OBJECT_H
