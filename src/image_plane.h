#include "math/point.h"
#include "math/direction.h"


class ImagePlane
{

    public:

    ImagePlane();
    ImagePlane(int w, int h, int distance, double pSize);
    ~ImagePlane();
    int getNpixels();
    
    private:

    int width;
    int height;
    int distanceFromCam;
    double pixelRatio;
    double aspectRatio;
    int nPixels;
    Point centerPos;
};