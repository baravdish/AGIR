#ifndef SCENE_H
#define SCENE_H

#include "system.h"
#include "box.h"
#include <vector>

class Ray;
class Object;

/**
 * @brief The Scene class contains all the objects of the Cornell box we want to render
 */
class Scene
{
public:
    /**
     * @brief Scene constructor
     * The objects scene are constructed by the scene itself.
     * @param dist is the distance from the world coordinate origin the scene will be
     * @param size is the size of the scene
     */
    Scene(double dist, double size);

    ~Scene();

    /**
     * @brief getColor has to be changed in "getRadiance" or someting TODO!
     * This is just a temporary method
     * The russian roulette, BRDF and other stuff may be applied here (?)
     * @param origin is the origin of a ray
     * @param direction is the direction of a ray
     * @param r is the returned red component (between 0 and 1)
     * @param g is the returned green component (between 0 and 1)
     * @param b is the returned blue component (between 0 and 1)
     */
    void getColor(const Ray &ray, double &r, double &g, double &b)const;

protected:

    /**
     * @brief closerIntersection computes the closer intersection between the objects of th scene and a ray.
     * @param localRay is the ray, in the local coordinate system, we want to compute the intersection.
     * @param intersection stores the intersection computed (if there is one)
     * @param direction stores the normal at the intersection (if there is one)
     * @param objectIntersected is the adress of the object intersected pointer
     * @return true if an intersection exists
     */
    bool closerIntersection(const Ray &localRay, Point &intersection, Direction &normal, Object **objectIntersected)const;

    /**
     * @brief m_system is the system coordinate of the scene relative to the world coordinate system
     */
    System m_system;

    /**
     * @brief m_box is the box in which the scene is included
     */
    Box m_box;

    /**
     * @brief m_objects is a vector of all the objects of the scene.
     * m_objects includes the walls of the box, but does not store the sources light
     */
    std::vector<Object*> m_objects;

};

#endif // SCENE_H
