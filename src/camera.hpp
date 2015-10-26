#ifndef CAMERA_H
#define CAMERA_H

#include "scene.h"
#include "math/point.h"
#include "math/direction.h"
#include "ray.h"

class Camera
{

public:

    Camera();
    Camera(Point pos, Direction view);
    ~Camera();

    Point getPosition();
    Direction getDirection();

private:
    Point camPosition;
    Direction camView;

};

#endif // CAMERA_H
