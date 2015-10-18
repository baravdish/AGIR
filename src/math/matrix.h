#ifndef MATRIX_H
#define MATRIX_H

class Direction;

/**
 * @brief The Matrix class represents a 3 by 3 row major orientation matrix.
 * A Matrix can be used for rotations
 */
class Matrix
{
public:
    /**
     * @brief Matrix default constructor
     * Constructs the identity matrix
     */
    Matrix();

    /**
     * @brief Matrix rotation constructor
     * @param angle is the angle of the rotation
     * @param axis is the axis of rotation
     */
    Matrix(double angle, const Direction &axis);

    /**
     * @brief operator () accesses to the (i,j)-element.
     * No bound-checking, in read only!
     * @return matrix[i][j]
     */
    const double& operator()(int i, int j)const;

protected:
    /**
     * @brief at access to the matrix.
     * No bound-checking, in read and write.
     * @return matrix[i][j]
     */
    double& at(int i, int j);

    /**
     * @brief data contains the matrix in row major orientation.
     */
    double data[9];
};

#endif // MATRIX_H
