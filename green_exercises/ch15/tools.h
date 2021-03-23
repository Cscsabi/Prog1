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

struct Graph_labels : Shape {
    Graph_labels(const string& title = "Default",
            const string& x_label = "Default",
            const string& y_label = "Default");

    void draw_lines() const;

    Text t;
    Text x;
    Text y;
};

class L_axis : public Shape {
    int xmax;
    int ymax;
    int xlength;
    int ylength;

    Point o;
    Axis xa;
    Axis ya;
    Graph_labels labs;

    static constexpr int xoffset = 100;
    static constexpr int yoffset = 60;
    static constexpr int xspace = 40;
    static constexpr int yspace = 40;

public:
    L_axis(int x_width, int y_height);
    void set_labels(const string& t, const string& x, const string& y);
    void draw_lines() const;
    Point origin() const { return o; }
    int width() const { return xlength; }
    int height() const { return ylength; }
};

struct Graph_data {
    Graph_data(vector<double>& d);

    double ceiling() const { return ceil; }

private:
    double min;
    double max;
    double ceil;
};

struct Bar_graph : Shape {
    Bar_graph(vector<double>& data, int xm, int ym);

    void draw_lines() const;
    void set_labels(const string& t, const string& x, const string& y);

private:
    Vector_ref<Rectangle> bars;
    L_axis lax;
    Graph_data gd;
};