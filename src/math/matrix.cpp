#include "matrix.h"
#include <cmath>
#include "mathstool.h"
#include "direction.h"

Matrix::Matrix()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            at(i,j) = (i==j);
        }
    }
}

Matrix::Matrix(double angle, const Direction &axis)
{
    double cosinus = cos(angle);
    double sinus = sin(angle);

    if(std::abs(cosinus) < MathsTool::epsilon)
        cosinus = 0.0;
    if(std::abs(sinus) < MathsTool::epsilon)
        sinus = 0.0;

    at(0,0) = cosinus + pow(axis.x(), 2)*(1-cosinus);
    at(0,1) = axis.x()*axis.y()*(1-cosinus) - axis.z()*sinus;
    at(0,2) = axis.x()*axis.z()*(1-cosinus) + axis.y()*sinus;
    at(1,0) = axis.x()*axis.y()*(1-cosinus) + axis.z()*sinus;
    at(1,1) = cosinus + pow(axis.y(), 2)*(1-cosinus);
    at(1,2) = axis.y()*axis.z()*(1-cosinus) - axis.x()*sinus;
    at(2,0) = axis.x()*axis.z()*(1-cosinus) - axis.y()*sinus;
    at(2,1) = axis.y()*axis.z()*(1-cosinus) + axis.x()*sinus;
    at(2,2) = cosinus + pow(axis.z(), 2)*(1-cosinus);
}

const double& Matrix::operator ()(int i, int j)const
{
    return data[i*3+j];
}

double& Matrix::at(int i, int j)
{
    return data[i*3+j];
}
