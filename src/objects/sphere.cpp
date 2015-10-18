#include "sphere.h"
#include "ray.h"
#include <cmath>

Sphere::Sphere(double r, double x, double y, double z, const Material &mat) :
    Object(x, y, z, 0, 1, 0, 0, mat), m_radius(r)
{

}

bool Sphere::intersected(const Ray &ray, Point &intersection, Direction &normal, double &param) const
{
    // copy and convert in the new system coordinate
    Ray localRay(ray);
    m_system.convertToSystem(localRay);

    // resolution of the second degree polynomial equation
    double a = pow(localRay.direction.x(),2)+pow(localRay.direction.y(),2)+pow(localRay.direction.z(),2);
    double b = 2*(localRay.origin.x*localRay.direction.x()+localRay.origin.y*localRay.direction.y()+localRay.origin.z*localRay.direction.z());
    double c = pow(localRay.origin.x,2)+pow(localRay.origin.y,2)+pow(localRay.origin.z,2)-pow(m_radius, 2);
    double solution = 0;

    // if delta < 0
    if(pow(b, 2)-4*a*c < 0)
    {
        return false;
    }
    else // if delta > 0
    {
        // solution of the equation
        solution = (-b-sqrt(pow(b, 2)-4*a*c))/2.0/a;

        // intersection
        intersection = localRay.origin + solution * (Vector)localRay.direction;

        // the normal is equal to the normalized intersection itself
        normal = intersection;

        // the intersection parameter is the solution
        param = solution;

        // conversion to the previous system coordinate
        m_system.convertFromSystem(intersection, normal);
        return true;
    }
}
