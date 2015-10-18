#include "scene.h"
#include "objects/sphere.h"
#include "objects/plane.h"
#include "math/point.h"
#include "math/direction.h"
#include "ray.h"
#include "objects/rectangle.h"
#include <cmath>
#include "math/mathstool.h"

Scene::Scene(double dist, double size) :
    m_system(0.0, 0.0, dist),
    m_box(size, size, size),
    m_objects()
{
    // some colors
    Material pink(1.0, 0.0, 1.0);
    Material yellow(1.0, 1.0, 0.0);
    Material blue(0.0, 1.0, 1.0);
    Material beige(0.96, 0.96, 0.86);
    Material red(1, 0, 0);
    Material green(0, 1, 0);

    // yellow cube
    m_objects.push_back(new Rectangle(size/2, size/10, size/2, 3.0/10*size, 0, 4.0/10*size, M_PI_4/2, 0, 1, 0, yellow));

    // blue cube
    m_objects.push_back(new Rectangle(1.0/10*size, 2*size/3, 1.0/10*size, 1.0/10*size, 0, 8.0/10*size, M_PI_4, 0, 1, 0, blue));

    // pink sphere
    m_objects.push_back(new Sphere(size/5, 7.0/10*size, size/10+size/5, 6.0/10*size, pink));

    // planes of the Cornell box
    m_objects.push_back(new Plane(size, size, 0, 0, size, -M_PI_2, 1, 0, 0, beige));
    m_objects.push_back(new Plane(size, size, 0, size, size, -M_PI, 1, 0, 0, beige));
    m_objects.push_back(new Plane(size, size, 0, size, 0, M_PI_2, 1, 0, 0, beige));
    m_objects.push_back(new Plane(size, size, size, 0, 0, -M_PI_2, 0, 1, 0, red));
    m_objects.push_back(new Plane(size, size, 0, 0, size, M_PI_2, 0, 1, 0, green));
}

Scene::~Scene()
{
    for (std::vector<Object*>::const_iterator it = m_objects.begin(); it!=m_objects.end(); ++it)
        delete *it;
}

void Scene::getColor(const Ray &ray, double &r, double &g, double &b)const
{
    // copy and convert in the system coordinate of the scene
    Ray localRay(ray);
    m_system.convertToSystem(localRay);

    // intersection checking with the box scene
    double smin, smax;
    if(!m_box.intersected(localRay, smin, smax))
    {
        r = g = b = 0;
        return;
    }

    Point intersection;
    Direction normal;
    Object *objectIntersected = 0;

    // intersection computing
    if(closerIntersection(localRay, intersection, normal, &objectIntersected))
    {
        // for now it will only take the color
        objectIntersected->material.getColor(r, g, b);
        // the dot product between the normal and the direction of the ray
        // plays the role of a weight in the final color
        double shadow = normal * (-localRay.direction);
        r *= shadow;
        g *= shadow;
        b *= shadow;

        // TODO here can be designed the Russian Roulette,
        // the Monte-Carlo method...

    }
    else
    {
        // red color if there is a box intersection but no intersection with any object
        r = 1;
        g = 0;
        b = 0;
    }
}

bool Scene::closerIntersection(const Ray &localRay, Point &intersection, Direction &normal, Object **objectIntersected) const
{
    // the closer object intersected
    *objectIntersected = 0;
    // distance parameter from the origin to the intersection
    double distance = MathsTool::infinity;

    // some temporary object
    double distanceTmp = 0.0;
    Point intersectionTmp;
    Direction normalTmp;

    // we iterate on all object of the scene
    for (std::vector<Object*>::const_iterator it = m_objects.begin(); it!=m_objects.end(); ++it)
    {
        // if there is an intersection
        if((*it)->intersected(localRay, intersectionTmp, normalTmp, distanceTmp))
        {
            // if this intersection is closer than the previous one
            if(distanceTmp < distance)
            {
                // updating current object intersected
                distance = distanceTmp;
                normal = normalTmp;
                intersection = intersectionTmp;
                *objectIntersected = *it;
            }
        }
    }
    return (*objectIntersected!=0);
}

