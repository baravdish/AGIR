#include "camera.hpp"

Camera::Camera()
{
    Point origin(0, 0, 0);
    Direction view(0, 0, 1);

    camPosition = origin;
    camView = view;
}

Camera::Camera(Point pos, Direction view) :
camPosition(pos), camView(view) 
{

}

Camera::~Camera()
{

}

Point Camera::getPosition()
{
    return camPosition;
}

Direction Camera::getDirection()
{
    return camView;
}



