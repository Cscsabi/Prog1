#include "Graph.h"

using namespace Graph_lib;

struct Fun : Function
{
	Fun(Fct f, double r1, double r2, Point orig,
	 int count, double xscale, double yscale, double precision);

	void set_func(Fct ff);
	void set_range(double rr1, double rr2);
	void set_origin(Point o);
	void set_precision(double precision);

private:
	void reset();
	Fct* f;
	double r1;
	double r2;
	Point orig;
	int count;
	double xscale;
	double yscale;
	double prec;
};
