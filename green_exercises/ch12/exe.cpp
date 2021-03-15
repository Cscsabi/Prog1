/*
    g++ exe.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o exe `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{	
	// Exercise 1
	Point tl { 100, 100 };
	Simple_window win { tl, 800, 800, "Exercise 1" };
	
	// as rectangle
	Rectangle r1 { Point{100, 100}, 100, 50 };
	r1.set_color(Color::blue);
	win.attach(r1);

	// as polygon
	Polygon poly;
	poly.add(Point{200,200});
	poly.add(Point{200,300});
	poly.add(Point{250,300});
	poly.add(Point{250,200});
	poly.set_color(Color::red);
	win.attach(poly);

	win.wait_for_button();


	// Exercise 2
	Rectangle r2 {  Point{300,300}, 100, 30 };
	win.attach(r2);

	Text t1 { Point{325,320}, "Howdy!" };
	win.attach(t1);

	win.set_label("Exercise 2");

	win.wait_for_button();


	// Exercise 3
	Text t2 { Point{500,500}, "C" };
	Text t3 { Point{600,500}, "C" };

	t2.set_color(Color::green);
	t3.set_color(Color::magenta);

	t2.set_font_size(150);
	t3.set_font_size(150);

	t2.set_font(Font::courier);
	t3.set_font(Font::courier);

	win.attach(t2);
	win.attach(t3);

	win.set_label("Exercise 3");

	win.wait_for_button();


	// Exercise 4
	win.set_label("Exercise 4");

	int wid = 50;

	Vector_ref<Rectangle> tik;
    for (int i = 0; i < 3; i++){
    	for (int j = 0; j < 3; j++){
    		tik.push_back(new Rectangle{Point{300+wid*j, 100+wid*i}, wid, wid});
            int k = tik.size() - 1;

            if (k % 2 == 0)
            	tik[k].set_fill_color(Color::white);
            else
            	tik[k].set_fill_color(Color::red);

            win.attach(tik[k]);
    	}
    }

    win.wait_for_button();


    // Exercise 5
    win.set_label("Exercise 5");

    Rectangle r3 { Point{150,150}, x_max() * 2/3, y_max() * 3/4 };
   
    r3.set_color(Color::red);
    r3.set_style(Line_style(Line_style::solid, 8));

    win.attach(r3);

    win.wait_for_button();

    // Exercise 6
    // Circle c { Point{100,100}, 700};
    // When a shape doesn't fit inside its window, then
    // is drawn, but it cannot be seen, only by resizing the window
    
    // Simple_window win2 { Point{100,100}, 5000, 5000, "X" };
    // win2.attach(c);
    // When a window doesn't fit on the screen, then it is
    // reduced to the size of the screen.
    

    // Exercise 7
    win.set_label("Exercise 7");

    Rectangle r4 { Point{300,300}, 400, 400 };
    r4.set_fill_color(Color::green);
    r4.set_color(Color::black);

    Polygon poly2;
    poly2.add(Point{300,300});
    poly2.add(Point{700,300});
    poly2.add(Point{500,100});
    poly2.set_fill_color(Color::red);
    poly2.set_color(Color::black);

    Rectangle r5 { Point{475,600}, 50, 100 };
    r5.set_fill_color(Color::black);
    
    Rectangle left { Point{375, 400}, 70, 70 };
    Rectangle right { Point{550, 400}, 70, 70 };

    Lines l1, l2, l3, l4, l5, l6; 
    l1.add(Point{375, 435}, Point{445, 435});
    l2.add(Point{410, 400}, Point{410, 470});

    l3.add(Point{550, 435}, Point{620, 435});
    l4.add(Point{585, 400}, Point{585, 470});

    l5.add(Point{650, 250}, Point{650, 150});
    l6.add(Point{675, 275}, Point{675, 150});

    win.attach(poly2);
    win.attach(r4);
    win.attach(r5);
    win.attach(left);
    win.attach(right);

    win.attach(l1);
    win.attach(l2);
    win.attach(l3);
    win.attach(l4);
    win.attach(l5);
    win.attach(l6);

    win.wait_for_button();


    // Exercise 8
    win.set_label("Exercise 8");

    Circle blue { Point{200, 200}, 50 };
    blue.set_color(Color::blue);
    blue.set_style(Line_style(Line_style::solid, 10));

    Circle yellow { Point{265, 250}, 50 };
    yellow.set_color(Color::yellow);
    yellow.set_style(Line_style(Line_style::solid, 10));

    Circle black { Point{330, 200}, 50 };
    black.set_color(Color::black);
    black.set_style(Line_style(Line_style::solid, 10));

    Circle green { Point{395, 250}, 50 };
    green.set_color(Color::green);
    green.set_style(Line_style(Line_style::solid, 10));

    Circle red { Point{460, 200}, 50 };
    red.set_color(Color::red);
    red.set_style(Line_style(Line_style::solid, 10));

    win.attach(blue);
    win.attach(yellow);
    win.attach(black);
    win.attach(green);
    win.attach(red);
	
	win.wait_for_button();


	// Exercise 9
	Image i { Point{120, 120}, "image.jpg" };

	Text t4 { Point{265, 110}, "The devil" };
	t4.set_font_size(20);
	win.set_label("The devil");

	win.attach(i);
	win.attach(t4);

	win.wait_for_button();
}