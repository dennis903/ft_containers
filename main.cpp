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

		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);

		std::cout << test.size() << " " << test.capacity() << std::endl;
		test.clear();
		std::cout << test.size() << " " << test.capacity() << std::endl;
		for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
			std::cout << &it << std::endl;
		std::vector<int>::iterator it2 = test.begin();
			std::cout << &it2 <<std::endl;
	}
}
