#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

struct Item
{
	std::string name;
	int iid;
	double value;
};

void print(std::vector<Item> vi)
{
	for (const auto& e : vi)
		std::cout << "Name: " << e.name << " Iid: "
			<< e.iid << " Value: " << e.value << std::endl;
}

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

int main()
{	
	// 1.:
	const std::string iname {"input.txt"};

    std::ifstream ifs {iname};
    if (!ifs) throw std::runtime_error("Could not read from file: " + iname);

    std::vector<Item> vi;
    for (Item ii; ifs >> ii; )
        vi.push_back(ii);

    std::cout << "vi: " << std::endl;
	print(vi);

	// 2.:
	std::sort(vi.begin(), vi.end(), 
		[](const Item& first, const Item& second) { return first.name < second.name; });

	std::cout << std::endl;

	std::cout << "vi sorted by name: " << std::endl;
	print(vi);

	// 3.:
	std::sort(vi.begin(), vi.end(), 
		[](const Item& first, const Item& second) { return first.iid < second.iid; });

	std::cout << std::endl;

	std::cout << "vi sorted by iid: " << std::endl;
	print(vi);

	// 4.:
	std::sort(vi.begin(), vi.end(),
		[](const Item& first, const Item& second) { return first.value > second.value; });

	std::cout << std::endl;

	std::cout << "vi sorted by decreasing value: " << std::endl;
	print(vi);

	// 5.:
	Item horse {"horse shoe", 99, 12.34};
	Item canon {"Canon S400", 9988, 499.95};
	vi.insert(vi.begin(), horse);
	vi.insert(vi.begin(), canon);

	std::cout << std::endl << "vi after inserting 2 items: " << std::endl;

	print(vi);

	// 6.:
	vi.erase(std::find_if(vi.begin(), vi.end(), by_name("Imola")));
	vi.erase(std::find_if(vi.begin(), vi.end(), by_name("János")));

	std::cout << std::endl << "vi after removing two items by name: " << std::endl;

	print(vi);

	// 7.:
	vi.erase(std::find_if(vi.begin(), vi.end(), by_iid(1)));
	vi.erase(std::find_if(vi.begin(), vi.end(), by_iid(9988)));

	std::cout << std::endl << "vi after removing two items by iid: " << std::endl;

	print(vi);
}
