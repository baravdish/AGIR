#include "scene.h"
#include <iostream>
#include <cmath>

#include "ray.h"
#include "point.h"
#include "direction.h"

int main(void)
{
    double distScene = 10;
    double sizeScene = 10;
    const Scene scene(distScene, sizeScene);

    Point originExample(5, 5, 0);
    Direction directionExemple(0, 0, 1);
    Ray rayExemple(originExample, directionExemple);

    double r = 0, g = 0, b =0;
    scene.getColor(rayExemple, r, g, b);
    std::cout << r << " " << g << " " << b << std::endl;
}

