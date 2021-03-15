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