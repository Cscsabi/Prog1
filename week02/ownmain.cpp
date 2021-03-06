/*
    g++ ownmain.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ownmain `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double){ return 1; }

double square(double x){ return x*x; }

int main()
{
	using namespace Graph_lib;

	int xmax = 1280;
	int ymax = 720;
	Simple_window win {Point{100, 100}, xmax, ymax, "Canvas"};

	int x_orig = xmax / 2;
	int y_orig = ymax / 2;

	int rmin = -11;
	int rmax = 11;

	int xscale = 30; int yscale = 30;

	int n_points = 400;

	Point origo {x_orig, y_orig};

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); }, rmin, rmax, origo, n_points, xscale, yscale);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);

	Rectangle r {Point{200,200}, 100, 50};
	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dash, 4));

	Text t {Point{200,400}, "Hello graphics!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{100,100}, "badge.jpg"};
	win.attach(ii);

	Circle c {Point{400,400}, 50};

	win.attach(c);
	win.attach(t);
	win.attach(r);
	
	/*
	ostringstream oss;
	oss << "screen size: " << xmax() << "*" << ymax()
		<< "window size " << win.xmax() << '*' << win.ymax();

	Text sizes {Point{500,500}, oss.str()};
	*/

	int xlength = xmax-40;
	int ylength = ymax-40;

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};

	win.attach(x);
	win.attach(y);

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	win.attach(poly_rect);

	win.wait_for_button();


}