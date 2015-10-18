#include "direction.h"
#include "matrix.h"
#include "vector.h"
#include <cmath>
#include <cassert>
#include "point.h"

Direction::Direction(double a, double b, double c)
{
    setXYZ(a,b,c);
}

Direction::Direction(const Direction &dir) : m_x(dir.m_x), m_y(dir.m_y), m_z(dir.m_z)
{

}

Direction::Direction(const Point &pt)
{
    setXYZ(pt.x, pt.y, pt.z);
}

Direction::Direction(const Vector &v)
{
    setXYZ(v.x, v.y, v.z);
}

double Direction::x()const
{
    return m_x;
}

double Direction::y()const
{
    return m_y;
}

double Direction::z()const
{
    return m_z;
}

void Direction::setXYZ(double a, double b, double c)
{
    m_x = a;
    m_y = b;
    m_z = c;
    double norm = sqrt(pow(m_x,2)+pow(m_y,2)+pow(m_z,2));
    assert(norm!=0.0);
    if(norm!=1.0)
    {
        m_x /= norm;
        m_y /= norm;
        m_z /= norm;
    }
}

Direction& Direction::operator-()const
{
    Direction *tmp = new Direction(-x(),-y(),-z());
    return *tmp;
}

double operator*(const Direction &dir1, const Direction &dir2)
{
    return dir1.x()*dir2.x() + dir1.y()*dir2.y() + dir1.z()*dir2.z();
}

Direction& Direction::operator*=(const Matrix &mat)
{
    Direction tmp(*this);
    double xtmp = mat(0,0)*tmp.x() + mat(0,1)*tmp.y() + mat(0,2)*tmp.z();
    double ytmp = mat(1,0)*tmp.x() + mat(1,1)*tmp.y() + mat(1,2)*tmp.z();
    double ztmp = mat(2,0)*tmp.x() + mat(2,1)*tmp.y() + mat(2,2)*tmp.z();
    setXYZ(xtmp,ytmp,ztmp);
    return *this;
}
