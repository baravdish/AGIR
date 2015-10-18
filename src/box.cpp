#include "box.h"
#include "ray.h"
#include <algorithm>
#include "mathstool.h"

Box::Box(double x, double y, double z)
{
    m_size[0] = x;
    m_size[1] = y;
    m_size[2] = z;
}

Box::Box(double s)
{
    m_size[0] = s;
    m_size[1] = s;
    m_size[2] = s;
}


bool Box::intersected(const Ray &localRay, double &smin, double &smax)const
{
    smin = 0.0;
    smax = MathsTool::infinity;
    double sxmin = 0.0, sxmax = MathsTool::infinity;
    double symin = 0.0, symax = MathsTool::infinity;
    double szmin = 0.0, szmax = MathsTool::infinity;

    // in the x,y plane
    if(localRay.direction.x() >= 0)
    {
        sxmin = -localRay.origin.x/localRay.direction.x();
        sxmax = (m_size[0]-localRay.origin.x)/localRay.direction.x();
    }
    else if(localRay.direction.x() < 0)
    {
        sxmin = (m_size[0]-localRay.origin.x)/localRay.direction.x();
        sxmax = -localRay.origin.x/localRay.direction.x();
    }
    if(localRay.direction.y() >= 0)
    {
        symin = -localRay.origin.y/localRay.direction.y();
        symax = (m_size[1]-localRay.origin.y)/localRay.direction.y();
    }
    else if(localRay.direction.y() < 0)
    {
        symin = (m_size[1]-localRay.origin.y)/localRay.direction.y();
        symax = -localRay.origin.y/localRay.direction.y();
    }

    // case of miss
    if(sxmin > symax || symin > sxmax)
        return false;

    // computation of the entry and exit
    smin = std::max(sxmin, symin);
    smax = std::min(sxmax, symax);

    // adding the z coordinate
    if(localRay.direction.z() > 0)
    {
        szmin = -localRay.origin.z/localRay.direction.z();
        szmax = (m_size[2]-localRay.origin.z)/localRay.direction.z();
    }
    else if(localRay.direction.z() < 0)
    {
        szmin = (m_size[2]-localRay.origin.z)/localRay.direction.z();
        szmax = -localRay.origin.z/localRay.direction.z();
    }

    // case of miss
    if(smin > szmax || szmin > smax)
        return false;

    // computation of the entry and exit
    smin = std::max(smin, szmin);
    smax = std::min(smax, szmax);

    return true;

}
