#include "Color.h"

Color Color::black = Color(0, 0, 0);
Color Color::gray = Color(127, 127, 127);
Color Color::white = Color(255, 255, 255);
Color Color::red = Color(255, 0, 0);
Color Color::green = Color(0, 255, 0);
Color Color::blue = Color(0, 0, 255);
Color Color::yellow = Color(255, 235, 4);

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	this->r = r, this->g = g, this->b = b, this->a = a;
}