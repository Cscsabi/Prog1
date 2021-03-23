/*
    g++ ex06.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp tools.cpp -o ex06 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "../../std_lib_facilities.h"
#include "Graph.h"
#include "tools.h"

using namespace Graph_lib;

int main()
{
	constexpr int xmax = 600;
	constexpr int ymax = 400;

	Point tl{100,100};

	Simple_window win {tl, xmax, ymax, "Exercise 06"};

	vector<double> data {1.4, 7.2, 4.1, 9.2, 5.8, 2.4, 1.9, 3.3, 3.6, 5.0, 2.0, 2.2, 9.9};
	Bar_graph bg {data, xmax, ymax};
	bg.set_labels("Random data", "x", "y");
	win.attach(bg);

	win.wait_for_button();
}