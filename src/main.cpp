#include "scene.h"
#include <iostream>
#include <cmath>

#include "camera.hpp"
#include "image_plane.h"
#include "ray.h"
#include "point.h"
#include "direction.h"


#include "bitmap_image.hpp"

int main(void)
{
    
    int sizeImgX = 800, sizeImgY = 600;

		bitmap_image image(sizeImgX, sizeImgY);

		Camera cam;
		Direction camDirection = cam.getDirection();
		Point origin = cam.getPosition();

		/*
		int distImagePlane = 1;
		double pixelRatio = 1;
		ImagePlane imagePlane(sizeImgX, sizeImgY, distImagePlane, pixelRatio);
		*/
		ImagePlane imagePlane;

		double distScene = 2;
		double sizeScene = 1000;
		const Scene scene(distScene, sizeScene);
		


		double r = 0, g = 0, b =0;

		for(int i = 0; i < sizeImgX; ++i)
		{
			for (int j = 0; j < sizeImgY; ++j)
			{

				origin.x = i;
				origin.y = j;

				Ray rayExemple(origin, camDirection);

				scene.getColor(rayExemple, r, g, b);
	
				image.set_pixel(i, j, (int)255*r, (int)255*g, (int)255*b);
			}
		}

		image.save_image("output.bmp");
}

