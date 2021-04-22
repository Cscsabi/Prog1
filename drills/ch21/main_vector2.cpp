#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

template<typename T>
void print(std::vector<T> vi)
{
	for (const auto& e : vi)
		std::cout << e << '\t';
}

template<typename T>
T accumulate(std::vector<T> v)
{
	T sum_of;
	for (const auto& e : v)
		sum_of += e;

	return sum_of;
}

int main()
{	
	// 1.:
	const std::string iname {"input2.txt"};

    std::ifstream ifs {iname};
    if (!ifs) throw std::runtime_error("Could not read from file: " + iname);

    std::vector<double> vd;
    for (double ii; ifs >> ii; )
        vd.push_back(ii);

    // 2.:
    std::cout << "vd: " << std::endl;
    print(vd);

    std::cout << std::endl << std::endl << "Pairs of vd and vi: " << std::endl;

    // 3.:
    std::vector<int> vi(vd.size());

    for (int i = 0; i < vi.size(); i++)
    	vi[i] = vd[i];

    // 4.:
    for (int i = 0; i < vi.size(); i++)
    	std::cout << vd[i] << ' ' << vi[i] << std::endl;

    // 5.:
    std::cout << std::endl << "Sum of elements of vd: " << accumulate(vd);

    // 6.:
    std::cout << std::endl << "Difference between sum of the elements of vd and the sum of the elements of vi: " << accumulate(vd) - accumulate(vi);

    // 7.:
    reverse(vd.begin(), vd.end());

    std::cout << std::endl << std::endl << "After reverse(): " << std::endl;

    print(vd);

    // 8.:
    std::cout << std::endl << std::endl << "Mean value of vd: " << accumulate(vd) / vd.size();

    // 9.:
    std::vector<double> vd2;
    for (int i = 0; i < vd.size(); i++)
    {
    	if (vd[i] < (accumulate(vd) / vd.size()))
    		vd2.push_back(vd[i]);
    }

    std::cout << std::endl << "\nvd2: " << std::endl;
    print(vd2);

    // 10.:
    std::cout << std::endl << std::endl;

    sort(vd.begin(), vd.end());

    std::cout << "vd after sort: " << std::endl;
    print(vd);
    std::cout << std::endl;
}
