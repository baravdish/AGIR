#include "object.h"

Object::Object(double x, double y, double z, double angle, double a, double b, double c, const Material &mat) :
    material(mat),
    m_system(x, y, z, angle, a, b, c)
{

}

Object::~Object()
{

}
