/*
    g++ exe.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp tools.cpp -o exe `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"
#include "tools.h"

int main()
{
	using namespace Graph_lib;

	// Exercise 1
	const Point tl { 100, 100 };
	Simple_window win{ tl, 600, 400, "My window" };

	Arc a1 { Point{ 200,200 }, 150, 0, 360 };
	win.attach(a1);

	Arc a2 { Point{ 200,200 }, 150, 0, 90 };
	a2.set_color(Color::red);
	win.attach(a2);

	Arc a3 { Point{ 200,200 }, 150, 120, 180 };
	a3.set_color(Color::green);
	win.attach(a3);
	win.set_label("Exercise 1");

	win.wait_for_button();


	// Exercise 2
	Box b1{ Point{ 100, 150 }, 200, 100, 25 };
	b1.set_color(Color::red);
	win.attach(b1);

	Box b2{ Point{ 200, 250 }, 100, 50, 10 };
	b2.set_color(Color::blue);
	win.attach(b2);

	Box b3{ Point{ 50, 50 }, 120, 100, 15 };
	b3.set_color(Color::green);
	win.attach(b3);
	win.set_label("Exercise 2");

	win.wait_for_button();

	// Exercise 3
	Arrow ar1 {Point{100, 100}, Point{250, 200}};
	win.attach(ar1);

	Arrow ar2 {Point{500, 300}, Point{500, 100}};
	ar2.set_color(Color::dark_green);
	win.attach(ar2);

	Arrow ar3 {Point{525, 100}, Point{525, 300}};
	ar3.set_color(Color::blue);
	win.attach(ar3);
	win.set_label("Exercise 3");

	win.wait_for_button();

	// Exercise 6
	Text_box shape {Point{50, 50}, 100, 50, "Shape"};
    win.attach(shape);

    Text_box rect {Point{50, 200}, 100, 50, "Rectangle"};
    win.attach(rect);

    Text_box tb {Point{50, 300}, 100, 50, "Textbox"};
    win.attach(tb);

    Text_box circ {Point{200, 200}, 100, 50, "Circle"};
    win.attach(circ);

    Arrow arr1 {n(rect), s(shape)};
    win.attach(arr1);

    Arrow arr2 {n(tb), s(rect)};
    win.attach(arr2);

    Arrow arr3 {nw(circ), se(shape)};
    win.attach(arr3);
    win.set_label("Exercise 6");

    win.wait_for_button();

    // Exercise 7
    Vector_ref<Graph_lib::Rectangle> rects;

    for (int i1 = 0; i1<4; ++i1) {
        for (int i2 = 0; i2<4; ++i2) {
            for (int j = 0; j<16; ++j) {
                for (int k = 0; k<16; ++k) {
                    rects.push_back(new Graph_lib::Rectangle(Point(16*12*i1+12*k,16*12*i2+12*j),12,12));
                    rects[rects.size()-1].set_fill_color(fl_rgb_color(15*(4*i1+i2),15*j,15*k));
                    rects[rects.size()-1].set_color(Color(Color::black,Color::invisible));
                    win.attach(rects[rects.size()-1]);
                }
            }
        }
    }
    win.wait_for_button();

    for (int i = 0; i<rects.size(); ++i)
        win.detach(rects[i]);

    const int box_h = 22;
    const int box_w = 88;
    Vector_ref<Graph_lib::Rectangle> boxes;
    Vector_ref<Text> labels;

    for (int i = 0; i<6; ++i) {
        for (int j = 0; j<6; ++j) {
            for (int k = 0; k<6; ++k) {
                boxes.push_back(new Graph_lib::Rectangle(Point(k*box_w,i*6*box_h+j*box_h),box_w,box_h));
                boxes[boxes.size()-1].set_fill_color(fl_rgb_color(51*i,51*j,51*k));
                boxes[boxes.size()-1].set_color(Color(Color::black,Color::invisible));
                win.attach(boxes[boxes.size()-1]);
                ostringstream oss;
                oss << hex << uppercase << setfill('0') << left <<
                    setw(2) << 51*i << setw(2) << 51*j << setw(2) << 51*k;
                labels.push_back(new Text(Point(k*box_w+20,i*6*box_h+j*box_h+16),oss.str().c_str()));
                if (j<=2) labels[labels.size()-1].set_color(Color::white);
                win.attach(labels[labels.size()-1]);
            }
        }
    }
    win.wait_for_button();
}