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
		test.insert(test.begin(), 4,  5);
		std::cout << test.size() << " " << test.capacity() << std::endl;
		// test.insert(test.begin(), 4);
		// test.insert(test.begin(), 3);
		// test.insert(test.begin(), 2);
		// test.insert(test.begin(), 1);
		// test.insert(test.begin() + 2, 4, 6);
		for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	// {
	// 	ft::vector<int> test;
	// 	test.insert(test.begin(), 1);
	// 	std::cout << test[0] << " " << test.size() << " " << test.capacity() << std::endl;
	// 	test.insert(test.begin(), 3);
	// 	std::cout << test[0] << " " << test.size() << " " << test.capacity() << std::endl;
	// 	test.insert(test.begin() + 1, 5);
	// 	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// }
}
