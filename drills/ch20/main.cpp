#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <stdexcept>

/*
template<typename T>
void increment(T& cont, int init)
{
	for(auto& p : cont)
		p = p + init;
}
*/

template<typename Iterator>
void increment(Iterator first, Iterator last, int init)
{
	while (first!=last){
		*first += init;
		++first;
	}
}

// 6.:
template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (Iter1 p = f1; p != e1; ++p)
        *f2++ = *p;
    return f2;
}

int main()
{	
	// 1.:
	std::array<int, 10> int_array {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// 2.:
	std::vector<int> int_vec {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// 3.:
	std::list<int> int_list {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// 4.:
	std::array<int, 10> int_array_2 = int_array;
	std::vector<int> int_vec_2 = int_vec;
	std::list<int> int_list_2 = int_list;

	// 5.:
	increment(int_array_2.begin(), int_array_2.end(), 2);
	increment(int_vec_2.begin(), int_vec_2.end(), 3);
	increment(int_list_2.begin(), int_list_2.end(), 5);

	// 7.:
	my_copy(int_array_2.begin(), int_array_2.end(), int_vec_2.begin());
	my_copy(int_list_2.begin(), int_list_2.end(), int_array_2.begin());

	// 8.:
	std::cout << "find(): \n";
	constexpr int value = 3;
	constexpr int value2 = 27;

	auto p = std::find(int_vec.begin(), int_vec.end(), value);

	if (p != int_vec.end())
        std::cout << "Found at: " << std::distance(int_vec.begin(), p) << '\n';
    else
        std::cout << "Not found\n";

    auto p2 = std::find(int_list.begin(), int_list.end(), value2);

    if (p2 != int_list.end())
        std::cout << "Found at: " << std::distance(int_list.begin(), p2) << '\n';
    else
        std::cout << "Not found\n";
}
	

	