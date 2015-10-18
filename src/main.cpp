#include "scene.h"
#include <iostream>
#include <fstream>
#include <cmath>

//#define parallel


#include "ray.h"
#include "point.h"
#include "direction.h"

int main(void)
{
    std::cout << "hello world" << std::endl;   
    double zoom = 30;
    double dist = 10;
    double size = 10;

    int sizex = 1000;
    int sizey = 1000;

#ifndef parallel

    const Scene scene(dist, size);

    double dx = size/(sizex-1);
    double dy = size/(sizey-1);

    std::ofstream myfile;
    myfile.open("test.pbm");

    myfile << "P3\n";
    myfile << sizex << " " << sizey << "\n";
    myfile << "255\n";

    double x=0, y=0;

    double r0, g0, b0;
    int r, g, b;


    Point camera(size/2, size/2, -zoom);

    for (int j = sizey-1; j >= 0; --j)
    {
        y = j*dy;
        for (int i = sizex-1; i >= 0; --i)
        {
            x = i*dx;
            Point origin(x, y, 0.0);
            Direction direction(origin-camera);

            Ray ray(origin, direction);
            scene.getColor(ray, r0, g0, b0);
            r = 255*r0;
            g = 255*g0;
            b = 255*b0;
            myfile << r << " " << g << " " << b << " ";
        }
        myfile << "\n";
    }

    myfile.close();
    // system("./open.sh");
    return 0;

#else

    const Scene scene(dist, size);

    double dx = size/(sizex-1);
    double dy = size/(sizey-1);

    std::ofstream myfile;
    myfile.open("test.pbm");

    myfile << "P3\n";
    myfile << sizex << " " << sizey << "\n";
    myfile << "255\n";

    double x=0, y=0, z=0;
    Direction d(0,0,1);

    double r0, g0, b0;
    int r, g, b;


    for (int j = sizey-1; j >= 0; --j)
    {
        y = j*dy;
        for (int i = sizex-1; i >= 0; --i)
        {

            x = i*dx;
            Point o(x,y,z);
            Ray ray(o,d);

            if(i==1&&j==4)
            {

                double b = 2+2;
            }

            scene.getColor(ray, r0, g0, b0);

            r = 255*r0;
            g = 255*g0;
            b = 255*b0;
            myfile << r << " " << g << " " << b << " ";
        }
        myfile << "\n";
    }

    myfile.close();
    // system("./open.sh");
    return 0;
#endif
}

