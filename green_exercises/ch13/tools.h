#include "Graph.h"
#include "../std_lib_facilities.h"

using namespace Graph_lib;

class Arc : public Shape
{
public:
	Arc(Point p, int rr, double start, double end);
	void draw_lines() const;
	int radius() const { return r; }
private:
	int r;
	double start;
	double end;
};

class Box : public Shape
{
public:
	Box(Point p, int w, int h, int r);
	void draw_lines() const;
	
private:
	Vector_ref<Arc> corners;
	Lines sides;
};

struct Arrow : Shape
{
	Arrow(Point p1, Point p2);
	void draw_lines() const;
	void set_size(int s) { size = s; }

private:
	int size = 12;
	int iso = 20;
};

struct Text_box : Rectangle
{
	Text_box(Point pp, int ww, int hh, string ss);
	void draw_lines() const;

private:
	Text label;
};

Point n (Rectangle& r);
Point s (Rectangle& r);
Point e (Rectangle& r);
Point w (Rectangle& r);
Point nw (Rectangle& r);
Point ne (Rectangle& r);
Point sw (Rectangle& r);
Point se (Rectangle& r);