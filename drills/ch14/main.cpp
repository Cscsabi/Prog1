#include "../std_lib_facilities.h"

class B1{
public:
	void f() { cout << "B1::f()\n"; }
	virtual void vf() { cout << "B1::vf()\n"; }
	virtual void pvf() =0; // ...
};

class D1 : public B1{
public:
	void vf() override { cout << "D1::vf()\n"; }
	void f() { cout << "D1:f()\n"; }
};

class D2 : public D1{
public:
	void pvf() override { cout << "D2::pvf()\n"; }
};

class B2{
public:
	virtual void pvf() =0;
};

class D21 : public B2{ //string
public:
	string s = "random";
	void pvf() override { cout << s << '\n'; }
};

class D22 : public B2{ //int
public:
	int s = 17;
	virtual void pvf() override { cout << s << '\n'; };
};

void f(B2& b){
	b.pvf();
}

int main()
{
	/*
	B1 b;
	b.vf();
	b.f();

	D1 d;
	d.vf();
	d.f();

	B1& r {d};
	r.vf();
	r.f();

	D2 dd;
	dd.f();
	dd.vf();
	dd.pvf();
	*/

	D21 dd1;
	D22 dd2;

	f(dd1);
	f(dd2);
}