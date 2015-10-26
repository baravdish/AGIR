#include "image_plane.h"
#include <iostream>
ImagePlane::ImagePlane()
{
    width = 800;
    height = 600;
    distanceFromCam = 1;
    pixelRatio = 1;
    centerPos = Point(11,0,0);
    std::cout << centerPos.x << " " << centerPos.y << " " << centerPos.z << std::endl;   
    nPixels = width*height*pixelRatio*pixelRatio;
    // field of view (FoV)
    aspectRatio = width/height;
}

ImagePlane::ImagePlane(int w, int h, int distance, double pRatio) :
width(w), height(h), distanceFromCam(distance), pixelRatio(pRatio)
{
    nPixels = width*height*pixelRatio*pixelRatio;
}

ImagePlane::~ImagePlane()
{

}

int ImagePlane::getNpixels()
{
    // basically the area of the image plane in pixel units
    return nPixels;
}