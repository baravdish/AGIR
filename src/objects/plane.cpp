#include "plane.h"
#include "ray.h"
#include <cmath>
#include "mathstool.h"

Plane::Plane(double sizex, double sizey,
             double x, double y, double z,
             double angle, double a, double b, double c,
             const Material &mat) :
    Object(x, y, z, angle, a, b, c, mat)
{
    m_size[0] = sizex;
    m_size[1] = sizey;
}


bool Plane::intersected(const Ray &ray, Point &intersection, Direction &normal, double &param) const
{
    // copy and transform in the current system coordinate
    Ray localRay(ray);
    m_system.convertToSystem(localRay);

    // if the ray is parallel to the plane
    if(std::abs(localRay.direction.z())<MathsTool::epsilon)
        return false;

    // compute the intersection with the infinite plane
    double t = - localRay.origin.z / localRay.direction.z();

    intersection = localRay.origin + t * (Vector)localRay.direction;

    // if the intersection is outside the boundaries of the plane
    if(!(-MathsTool::epsilon<=intersection.x && intersection.x<=m_size[0]+MathsTool::epsilon &&
         -MathsTool::epsilon<=intersection.y && intersection.y<=m_size[1]+MathsTool::epsilon))
        return false;

    normal.setXYZ(0,0,1);
    param = t;

    // transform from this current coordinate system to the previous one
    m_system.convertFromSystem(intersection, normal);

    return true;
}
