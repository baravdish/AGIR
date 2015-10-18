#include "ray.h"

Ray::Ray(double ptx, double pty, double ptz, double dx, double dy, double dz) :
    origin(ptx, pty, ptz), direction(dx, dy, dz)
{

}

Ray::Ray(Point &pt, Direction &dir) : origin(pt), direction(dir)
{

}

