#include "CImg.h"
using namespace cimg_library;

#define imgchange(img,x,y,color,color2) \
	if((img(x, y, 0) == color[0] && img(x, y, 1) ==color[1] && img(x, y, 2) == color[2])){\
		img(x, y, 0) = color2[0];\
		img(x, y, 1) = color2[1];\
		img(x, y, 2) = color2[2];\
}


int main() {
	// open 1.bmp and diplay it

	CImg<unsigned char> img1("1.bmp");
	img1.display("hm1");

	// define colors that used later

	const unsigned char red[] = { 255,0,0 };
	const unsigned char white[] = { 255,255,255 };
	const unsigned char black[] = { 0,0,0 };
	const unsigned char green[] = { 0,255,0 };
	const unsigned char blue[] = { 0,0,255 };
	const unsigned char yellow[] ={255,255,0} ;

	// change write point into red and black point into green
	// pixel by pixel

	CImg<unsigned char> img("1.bmp");
	cimg_forXY(img, x, y)
	{
			imgchange(img, x, y, white, red);
			imgchange(img, x, y, black, green);
	}

	// draw circles

	img.draw_circle(50,50,30,blue);
	img.draw_circle(50,50,3,yellow);
	img.display("hm2");
	return 0;
}
