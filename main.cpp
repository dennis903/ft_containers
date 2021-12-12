#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include "includes/vector.hpp"

int main()
{
	{
		std::vector<int> test;
		test.insert(test.begin(), 1);
		std::cout << test[0] << " " << test.size() << " " << test.capacity() << std::endl;
	}
	{
		ft::vector<int> test;
		test.insert(test.begin(), 1);
		std::cout << test[0] << " " << test.size() << " " << test.capacity();
	}
}
