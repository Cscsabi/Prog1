#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

template<typename T, typename C>
void print(std::map<T, C> msi)
{
	for (const auto& [name, value] : msi)
        std::cout << name << ' ' << value << std::endl;
}

// 5.:
void read_pairs(std::map<std::string, int>& msi)
{
	for (int i = 0; i < 10; i++)
	{
		std::string temp_str;
		int temp_int;
		std::cin >> temp_str >> temp_int;
		msi.insert({temp_str, temp_int});
	}
}

int accumulate(std::map<std::string, int> msi)
{
	int sum_of = 0;
	for (const auto& [name, value] : msi)
		sum_of += value;

	return sum_of;
}

int main()
{	
	// 1.:
	std::map<std::string, int> msi;

	// 2.:
	msi["László"] = 123;
	msi["Károly"] = 1234;
	msi["Erzsébet"] = 53;
	msi["Fülöp"] = 9;
	msi["Pál"] = 88;
	msi["Lajos"] = 69;
	msi["Gábor"] = 7;
	msi["Hanna"] = 17;
	msi["Lilla"] = 8000;
	msi["Nikolett"] = 13;

	// 3.:
	std::cout << "Pairs of msi: " << std::endl;
	print(msi);

	// 4.:
	for (auto it = msi.begin(); it != msi.end(); )
	{
		it = msi.erase(it);
	}

	// 6.:
	std::cout << std::endl << "Input: " << std::endl;
	read_pairs(msi);

	// 7.:
	std::cout << std::endl << "Pairs of msi after input: " << std::endl;
	print(msi);

	// 8.:
	std::cout << std::endl << "Sum of values in msi: " << accumulate(msi) << std::endl;

	// 9.:
	std::map<int, std::string> mis;

	// 10.:
	for (const auto& [name, value] : msi)
		mis.insert({value, name});

	std::cout << std::endl << "mis: " << std::endl;
	print(mis);
}
