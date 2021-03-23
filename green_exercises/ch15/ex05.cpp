/*
    g++ ex05.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp tools.cpp -o ex05 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

double leibniz(int n)
{
    double sum = 0;
    for (int i = 0; i<=n; ++i) {
        int fac = 1;
        if (i%2!=0) fac = -1;
        sum += 1/double(2*i+1) * fac;
    }
    return sum;
}

int main()
{
try
	{	
		constexpr int xmax = 800;
	    constexpr int ymax = 800;
	    const Point orig(xmax/2,ymax/2);
	    constexpr int xscale = 20;
	    constexpr int yscale = 20;
	    constexpr int xlength = xmax - 40;
	    constexpr int ylength = ymax - 40;
	    constexpr double r_min = 0;
	    constexpr double r_max = 20;
	    constexpr int precision = 30;
	
	    Simple_window win{Point{100,100}, xmax, ymax, "Ch15"};
	
	    Axis x {Axis::x, Point{20, ymax/2},
	            xlength, xlength/xscale, "x"};
	    Axis y {Axis::y, Point{xmax/2, ylength + 20},
	            ylength, ylength/yscale, "y"};
	    x.set_color(Color::red);
	    y.set_color(Color::red);
	
	    win.attach(x);
	    win.attach(y);
	
	    win.wait_for_button();
	
	    Open_polyline opl;
	    opl.add(Point(orig.x, orig.y-yscale));
	    win.attach(opl);
	
	    for (int n = 1; n < 50; ++n)
	    {
	    	ostringstream ss;
	    	ss << "leibniz series" << n;
	    	int x = opl.point(n-1).x + xscale;
	        int y = orig.y - leibniz(n) * yscale;
	        opl.add(Point(x,y));
	
	        win.set_label("exercise 5");
	        win.wait_for_button();
	    }

	}
catch(exception& e){
	cerr << "exception: " << e.what() << endl;
}
catch(...){
	cerr << "exception" << endl;
}

} // End of main function