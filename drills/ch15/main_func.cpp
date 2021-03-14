/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

double one(double x)
{
	return 1;
}

double slope(double x)
{
	return x / 2;
}

double square(double x)
{
	return x * x;
}

double sloping_cos(double x)
{
	return cos(x) + slope(x);
}

int main()
{	
	using namespace Graph_lib;

	// Declaring constants
	const Point origin{300,300};
	constexpr int r1 = -10;
	constexpr int r2 = 11;
	constexpr int count = 400;
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;
	
	Point tl {100, 100};
	Simple_window win{tl, 600, 600, "My window"};

	Axis x {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
	Axis y {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);

	Function f(one, r1, r2, origin, count, x_scale, y_scale);
	Function sl(slope, r1, r2, origin, count, x_scale, y_scale);
	Function sq(square, r1, r2, origin, count, x_scale, y_scale);
	Function cs(cos, r1, r2, origin, count, x_scale, y_scale);
	Function sl_cos(sloping_cos, r1, r2, origin, count, x_scale, y_scale);

	Text sl_text{Point{100, 385}, "x/2"};
	cs.set_color(Color::blue);

	win.attach(f);
	win.attach(sl);
	win.attach(sl_text);
	win.attach(sq);
	win.attach(cs);
	win.attach(sl_cos);

	win.wait_for_button();
}