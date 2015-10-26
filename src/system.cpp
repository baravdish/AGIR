#include "system.h"
#include <cmath>
#include "ray.h"
#include "math/mathstool.h"
#include "math/direction.h"
#include "math/point.h"
#include <iostream>

System::System(double x, double y, double z,
               double angle, double a, double b, double c) :
    m_translation(x, y, z),
    m_rotation(-angle, Direction(a, b, c)),
    m_rotationInverse(+angle, Direction(a, b, c))
{
    m_noRotation = (angle==0.0);
}

void System::convertToSystem(Ray &ray)const
{
    ray.origin -= m_translation;

    if(!m_noRotation)
    {
        ray.origin *= m_rotation;
        ray.direction *= m_rotation;
    }
}

void System::convertFromSystem(Point &point, Direction &vector) const
{
    if(!m_noRotation)
    {
        point *= m_rotationInverse;
        vector *= m_rotationInverse;
    }
    point += m_translation;
}
