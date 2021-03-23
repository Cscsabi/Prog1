#include "tools.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

Fun::Fun(Fct ff, double rr1, double rr2, Point o,
 	int c = 100, double x = 25, double y = 25, double p = 30)
	: Function{ff, rr1, rr2, o, c, x, y, p},
	  f{ff},
	  r1{rr1},
	  r2{rr2},
	  orig{o},
	  count{c},
	  xscale{x},
	  yscale{y},
	  prec{p}
{ }

void Fun::reset()
{
	clear_points();

	double dist = (r2-r1) - count;
	double r = r1;
	for (int i = 0; i < count; i++)
	{
		add(Point(orig.x+int(r*xscale), orig.y-int(f(r)*yscale)));
		r += dist;
	}
}

void Fun::set_func(Fct ff)
{
	f = ff;
	reset();
}

void Fun::set_range(double rr1, double rr2)
{
	r1 = rr1;
	r2 = rr2;
	reset();
}

void Fun::set_origin(Point o)
{
	orig = o;
	reset();
}

void Fun::set_precision(double precision)
{
	prec = precision;
	reset();
}

Graph_labels::Graph_labels(const string& title, const string& x_label,
        const string& y_label) :
    t{Point{0, 0}, title},
    x{Point{0, 0}, x_label},
    y{Point{0, 0}, y_label}
{
    t.set_font_size(20);
    t.set_color(Color::black);
    x.set_font_size(16);
    x.set_color(Color::black);
    y.set_font_size(16);
    y.set_color(Color::black);
}

void Graph_labels::draw_lines() const
{
    t.draw();
    x.draw();
    y.draw();
}

L_axis::L_axis(int xx, int yy) :
    xmax{xx}, ymax{yy},
    xlength{xx - xoffset - xspace},
    ylength{yy - yoffset - yspace},
    o{xoffset, yy - yoffset},
    xa{Axis::x, o, xlength},
    ya{Axis::y, o, ylength},
    labs{"Big Title!!"}
{
	labs.t.move(o.x, yspace - 10);
    labs.x.move(o.x, o.y + 20);
    labs.y.move(o.x / 4, o.y - height() / 2);
}

void L_axis::draw_lines() const
{	
    xa.draw();
    ya.draw();
    labs.draw_lines();
}

void L_axis::set_labels(const string& tt, const string& xx, const string& yy)
{
    labs.t.set_label(tt);
    labs.x.set_label(xx);
    labs.y.set_label(yy);
}

Graph_data::Graph_data(vector<double>& data)
{
    for (auto d : data) {
        if (min == 0 && max == 0) {
            min = d;
            max = d;
        }
        if (d < min)
            min = d;
        if (d > max)
            max = d;
    }

    ceil = max * 1.05;
}

Bar_graph::Bar_graph(vector<double>& data, int xx, int yy) :
    lax{xx, yy},
    gd{data}
{
    const Point o = lax.origin();
    const int w = lax.width() / data.size();
    const int bar = w * 0.8;
    const int gap = w * 0.2;

    int x = o.x;
    for (auto d : data) {
        int h = d / gd.ceiling() * lax.height();
        int y = o.y - h;
        bars.push_back(new Rectangle{Point{x + gap, y}, bar, h});
        bars[bars.size()-1].set_color(Color::invisible);
        bars[bars.size()-1].set_fill_color(Color::blue);
        x += w;
    }
}

void Bar_graph::draw_lines() const
{
    // Bars
    for (int i = 0; i < bars.size(); ++i)
        bars[i].draw_lines();

    // Axis
    lax.draw_lines();
}

void Bar_graph::set_labels(const string& t, const string& x, const string& y)
{
    lax.set_labels(t, x, y);
}
