#include "../std_lib_facilities.h"

struct Person
{
	Person() {}
	Person(string ff, string ll, int aa);

	string first_name() const { return f; }
	string last_name() const { return l; }
	int age() const { return a; }

private:
	string f;
	string l;
	int a;
};

Person::Person(string ff, string ll, int aa)
	: f{ff}, l{ll}, a{aa}
{
	if (aa < 0 || aa > 150) error("Invalid age");
	string name = ff + ll;
	for ( char c : name ){
		switch(c){
			case ';': case ':': case '"': case '\'': case '[': case ']': case '*': 
			case '&': case '^': case '%': case '$': case '#': case '@': case '!':
			error("Invalid character(s)");
		}

	}
}

istream& operator>>(istream& is, Person& p)
{
	string f;
	string l;
	int a;
	is >> f >> l >> a;

	if(!is) error("input error...");

	p = Person(f, l, a);

	return is;
}

ostream& operator<<(ostream& os, Person& p)
{
	return os << p.first_name() << ' ' << p.last_name() << ' ' << p.age();
}

int main()
{	
	//Person p{"Goofy", 63};
	//cout << p << endl;

	vector<Person> per;

	cout << "Enter firstname, lastname and age! To end enter '|' instead of name" << endl;

	for ( Person p; cin >> p; ){
		if (p.first_name()=="|") break;
		per.push_back(p);
	}

	for ( Person p : per ){
		cout << p << endl;
	}
}