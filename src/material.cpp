#include "material.h"
#include <iostream>

Material::Material(double r, double g, double b)
{
    if(r < 0 || g <0 || b < 0 || 1 < r || 1 < g || 1<b)
        std::cerr << "RGB color must be in [0,1] : " << r << "," << g << "," << b << std::endl;
    m_color[0] = r;
    m_color[1] = g;
    m_color[2] = b;
}

Material::Material(const Material &m)
{
    m_color[0] = m.m_color[0];
    m_color[1] = m.m_color[1];
    m_color[2] = m.m_color[2];
}

void Material::getColor(double &r, double &g, double &b)const
{
    r = m_color[0];
    g = m_color[1];
    b = m_color[2];
}
