#ifndef MATERIAL_H
#define MATERIAL_H

/**
 * @brief The Material class stores all the information of the object's material
 * For now, this class just represents a color in the RGB system
 * TODO: add a BRDF method...
 */
class Material
{
public:
    /**
     * @brief Material constructor
     * @param r
     * @param g
     * @param b
     */
    Material(double r = 1.0, double g = 1.0, double b = 1.0);

    /**
     * @brief Material copy constructor
     * @param m
     */
    Material(const Material &m);

    /**
     * @brief getColor will be removed (?)
     * @param r
     * @param g
     * @param b
     */
    void getColor(double &r, double &g, double &b)const;

protected:
    /**
     * @brief m_color is a RGB model of the color (r, g, b between 0 and 1)
     */
    double m_color[3];
};

#endif // MATERIAL_H
