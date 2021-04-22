#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <algorithm>

struct Item
{
	std::string name;
	int iid;
	double value;
};

std::ostream& operator<<(std::ostream& os, const Item& it)
{
	return os << it.name << '\t' 
		<< it.iid << '\t'
		<< it.value;
}

std::istream& operator>>(std::istream& is, Item& it)
{
	std::string ss;
	int ii;
	double dd;
	is >> ss >> ii >> dd;
	Item iit {ss, ii, dd};
	it = iit;
	return is;
}

struct in_order
{
	in_order(double v) : val{v} {}
	bool operator()(const Item& i) { return i.value < val; }

private:
	double val;
};

struct by_name
{
	by_name(const std::string& n) : name{n} {}
	bool operator()(const Item& i) { return i.name == name; }

private:
	std::string name;
};

struct by_iid
{
	by_iid(const int i) : iid{i} {}
	bool operator()(const Item& i) { return i.iid == iid; }

private:
	int iid;
};

void print(std::list<Item> vi)
{
	for (const auto& e : vi)
		std::cout << "Name: " << e.name << " Iid: "
			<< e.iid << " Value: " << e.value << std::endl;
}

int main()
{	
	// 1.:
	const std::string iname {"input.txt"};

    std::ifstream ifs {iname};
    if (!ifs) throw std::runtime_error("Could not read from file: " + iname);

    std::list<Item> li;
    for (Item ii; ifs >> ii; )
        li.push_back(ii);

    std::cout << "li: " << std::endl;
	print(li);

	// 2.:
	li.sort([](const Item& first, const Item& second) { return first.name < second.name; });

	std::cout << std::endl;
	std::cout << "li sorted by name: " << std::endl;

	print(li);

	// 3.:
	li.sort([](const Item& first, const Item& second) { return first.iid < second.iid; });

	std::cout << std::endl;
	std::cout << "li sorted by iid: " << std::endl;

	print(li);

	// 4.: 
	li.sort([](const Item& first, const Item& second) { return first.value > second.value; });

	std::cout << std::endl;

	std::cout << "li sorted by decreasing value: " << std::endl;
	print(li);

	// 5.:
	Item horse {"horse shoe", 99, 12.34};
	Item canon {"Canon S400", 9988, 499.95};

	li.insert(std::find_if(li.begin(), li.end(), in_order(horse.value)), horse);
	li.insert(std::find_if(li.begin(), li.end(), in_order(canon.value)), canon);

	std::cout << std::endl << "li after inserting 2 items: " << std::endl;

	print(li);

	// 6.:
	li.erase(std::find_if(li.begin(), li.end(), by_name("Béla")));
	li.erase(std::find_if(li.begin(), li.end(), by_name("Imola")));

	std::cout << std::endl << "li after removing two items by name: " << std::endl;

	print(li);

	// 7.:
	li.erase(std::find_if(li.begin(), li.end(), by_iid(9)));
	li.erase(std::find_if(li.begin(), li.end(), by_iid(10)));

	std::cout << std::endl << "li after removing two items by iid: " << std::endl;

	print(li);
}