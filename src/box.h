#ifndef BOX_H
#define BOX_H

class Ray;

/**
 * @brief The Box class represents a 3D box which includes all an object (or all the entire scene).
 * A box starts at the origin of the coordinate system of the associated object, and is composed
 * of three slabs, one for each direction.
 */
class Box
{
public:
    /**
     * @brief Box constructor
     * @param x is the x size
     * @param y is the y size
     * @param z is the z size
     */
    Box(double x, double y, double z);

    /**
     * @brief Box constructor
     * @param s is the x, y and z size
     */
    Box(double s);

    /**
     * @brief intersected verifys if a ray intersects or not the box,
     * if it does, the minimum and the maximum parameters are returned.
     * These parameters are valids in the current coordinate system of the object.
     * This method implements the Smit's algorithm.
     * @param localRay is the ray expressed in the local coordinate system
     * @param smin is the minimum parameter of the intersection
     * @param smax is the maximum parameter of the intersection
     * @return true if the ray intersects the box
     */
    bool intersected(const Ray &localRay, double &smin, double &smax)const;

protected:
    /**
     * @brief m_size is an array containing the box size in the three directions
     * This corresponds to the 3 slabs, each slab has its left paramater equal to zero,
     * and its right parameter positiv.
     */
    double m_size[3];

};

#endif // BOX_H
