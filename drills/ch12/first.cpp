/*
    g++ first.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o first `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"



int main()
{	
	using namespace Graph_lib;

	try
	{
		Point tl {100,100};
		Simple_window win {tl, 600, 400, "My window"};

		Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
		Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
		ya.set_color(Color::yellow);
		ya.label.set_color(Color::green);

		Function sine {sin,0,100,Point{20,150}, 1000,50,50};
		sine.set_color(Color::blue);

		Polygon poly;
		poly.add(Point{300,200});
		poly.add(Point{350,100});
		poly.add(Point{400,200});
		poly.set_color(Color::dark_red);
		poly.set_style(Line_style::dash);

		Rectangle r {Point{200,200}, 100, 50};

		r.set_fill_color(Color::yellow);

		Closed_polyline poly_rect;
		poly_rect.add(Point{100,50});
		poly_rect.add(Point{200,50});
		poly_rect.add(Point{340,100});
		poly_rect.add(Point{100,100});

		poly_rect.add(Point{120,75});

		poly.set_style(Line_style(Line_style::dash, 10));
		poly_rect.set_style(Line_style(Line_style::dash,3));
		poly_rect.set_fill_color(Color::blue);

		Text t {Point{150,150}, "Hello, graphical world!"};
		t.set_font(Font::times_bold);
		t.set_font_size(20);

		Image ii {Point{100,50}, "badge.jpg"};

		Circle c {Point{100,200},100};
		Mark m {Point{100,200},'K'};


		win.attach(ii);
		win.attach(sine);
		win.attach(xa);
		win.attach(ya);
		win.attach(poly);
		win.attach(r);
		win.attach(poly_rect);
		win.attach(t);
		win.attach(c);
		win.attach(m);

		win.set_label("Canvas");

		win.wait_for_button();

	} catch(exception& e){
		return 1;

	}catch(...){
		return 2;
	}
}