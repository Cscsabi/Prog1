/*
    g++ ex02.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp tools.cpp -o ex02 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "../../std_lib_facilities.h"
#include "Graph.h"
#include "tools.h"

using namespace Graph_lib;

int main()
{
	constexpr int xmax = 800;
    constexpr int ymax = 800;
    const Point orig{xmax/2,ymax/2};
    constexpr int xscale = 20;
    constexpr int yscale = 20;
    constexpr int xlength = xmax - 40;
    constexpr int ylength = ymax - 40;

    Simple_window win{Point{100,100}, xmax, ymax, "Ch15"};

    Axis x {Axis::x, Point{20, ymax/2},
            xlength, xlength/xscale, "x"};
    Axis y {Axis::y, Point{xmax/2, ylength + 20},
            ylength, ylength/yscale, "y"};
    x.set_color(Color::red);
    y.set_color(Color::red);

    win.attach(x);
    win.attach(y);

    Fun f{[](double x){ return x*x; }, -5, 10,
     orig, 100, xscale, yscale, 30};
    win.set_label("1/x");
    win.attach(f);

    win.wait_for_button();

    win.detach(f);
    f.set_func([](double x){ return x; });
    win.set_label("x");
    f.set_range(-10, 11);
    win.attach(f);

    win.wait_for_button();

    win.detach(f);
    f.set_func([](double x){ return x/2; });
    f.set_precision(50);
    f.set_range(-8, 8);
    win.set_label("x/2");
    win.attach(f);

    win.wait_for_button();

    win.detach(f);
    f.set_func([](double x){ return 1/x; });
    f.set_range(-15, 7);
    win.attach(f);
    win.wait_for_button();
}