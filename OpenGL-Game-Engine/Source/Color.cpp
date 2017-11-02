#include "Color.h"

Color Color::black = Color(0, 0, 0);
Color Color::gray = Color(0.5, 0.5, 0.5);
Color Color::white = Color(1, 1, 1);
Color Color::red = Color(1, 0, 0);
Color Color::green = Color(0, 1, 0);
Color Color::blue = Color(0, 0, 1);
Color Color::yellow = Color(1, 0.92f, 0.016f);

Color::Color() {}

Color::Color(float r, float g, float b, float a) {
	this->r = r, this->g = g, this->b = b, this->a = a;
}

std::ostream& operator<<(std::ostream& out, const Color& color) {
	out << "Color(" << color.r << ", " << color.g << ", " << color.b << ")\n";
	return out;
}