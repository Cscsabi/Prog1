#include "../std_lib_facilities.h"

template<typename T> 
struct S{
	explicit S(T vv = 0) : val{vv} { }
	S& operator=(const T&);
	T& get();
	const T& get() const;
	void set(T new_val) { val = new_val; };

private:
	T val;
	T new_val;
};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
const T& S<T>::get() const
{
	return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& new_val)
{
	val = new_val;
	return *this;
}

template<typename T>
void read_val(T& v)
{
	cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
    os << "{";
    for(int i = 0; i < v.size(); ++i){
        os << v[i] << (i < v.size() -1 ? ", " : " ");
    }
    os << "}\n";

    return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if(ch != '{'){
        is.unget();
        return is;
    }

    for(T val; is >> val;){
        v.push_back(val);
        is >> ch;
        if ( ch != ',') break;
    }

    return is;
}

int main()
{
	S<int> num {15};
	S<char> letter {'b'};
	S<double> floating {21.2};
	S<string> word {"something"};
	S<vector<int>> v { vector<int>{15, 23, 12, 41} };
	
	cout << num.get() << endl;
	cout << letter.get() << endl;
	cout << floating.get() << endl;
	cout << word.get() << endl;
    for (auto& a : v.get())
        cout << a << ' ';
    cout << '\n';

    
    num.set(20);
    cout << num.get() << endl;

    num = 25;
    cout << num.get() << endl;

    cout << "Integer: ";
    int ii;
    read_val(ii);
    S<int> si2 {ii};
    cout << "Char: ";
    char cc;
    read_val(cc);
    S<char> sc2 {cc};
    cout << "Double: ";
    double dd;
    read_val(dd);
    S<double> sd2 {dd};
    cout << "String: ";
    string ss;
    read_val(ss);
    S<string> s2 {ss};
    cout << "S<int> read: " << si2.get() << '\n';
    cout << "S<char> read: " << sc2.get() << '\n';
    cout << "S<double> read: " << sd2.get() << '\n';
    cout << "S<string> read: " << s2.get() << '\n';
    

    cout << "Vector<int>: (format: { val1, val2, val3 }) ";
    vector<int> v2;
    read_val(v2);
    S<vector<int>> v3 {v2};

    cout << "S<vector<int>> read: " << v3.get();
    
    

	return 0;
}