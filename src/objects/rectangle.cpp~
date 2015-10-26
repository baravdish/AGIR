#include "rectangle.h"
#include "ray.h"
#include "mathstool.h"
#include <cmath>

Rectangle::Rectangle(double sizex, double sizey, double sizez,
                     double x, double y, double z,
                     double angle, double a, double b, double c,
                     const Material &mat) :
    Object::Object(x, y, z, angle, a, b, c, mat),
    m_box(sizex, sizey, sizez)
{
    m_size[0] = sizex;
    m_size[1] = sizey;
    m_size[2] = sizez;
}

Rectangle::~Rectangle()
{

}

bool Rectangle::intersected(const Ray &ray, Point &intersection, Direction &normal, double &param) const
{
    // copy and convert in the new system coordinate
    Ray localRay(ray);
    m_system.convertToSystem(localRay);

    // if there is no intersection with the bounding box
    double smin, smax;
    if(!m_box.intersected(localRay, smin, smax))
        return false;

    // computing intersection
    intersection = localRay.origin + smin * (Vector)localRay.direction;
    param = smin;

    if(std::abs(intersection.x)<MathsTool::epsilon) // plane x=0
    {
        normal.setXYZ(-1,0,0);
    }
    else if( std::abs(intersection.x-m_size[0])<MathsTool::epsilon ) // plane x=size[0]
    {
        normal.setXYZ(+1,0,0);
    }
    else if( std::abs(intersection.y) < MathsTool::epsilon) // plane y=0
    {
        normal.setXYZ(0,-1,0);
    }
    else if(std::abs(intersection.y-m_size[1])<MathsTool::epsilon) // plane y=size[1]
    {
        normal.setXYZ(0,+1,0);
    }
    else if(std::abs(intersection.z)<MathsTool::epsilon ) //plane z=0
    {
        normal.setXYZ(0,0,-1);
    }
    else if(std::abs(intersection.z-m_size[2])<MathsTool::epsilon) //plane z=size[2]
    {
        normal.setXYZ(0,0,+1);
    }
    else
    {
        normal.setXYZ(0,0,0);
    }

    m_system.convertFromSystem(intersection, normal);

    return true;
}
