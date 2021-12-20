#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include "includes/vector.hpp"

int main()
{
	//insert
	{
		std::vector<int> test(4, 10);
		std::vector<int> test2;
		std::vector<int>::iterator it = test.begin();

		test2.push_back(1);
		test2.push_back(2);
		test2.push_back(3);
		test2.push_back(4);
		test.insert(it+2, test2.begin(), test2.end());
		for (size_t i = 0; i < test.size(); i++)
			std::cout << test[i] << " " ;
		std::cout << std::endl;
	}
	{
		std::cout << "======= ft ========" << std::endl;
		ft::vector<int> test(4, 10);
		ft::vector<int> test2;
		ft::vector<int>::iterator it = test.begin();

		test2.push_back(1);
		test2.push_back(2);
		test2.push_back(3);
		test2.push_back(4);
		test.insert(it+2, test2.begin(), test2.end());
		for (size_t i = 0; i < test.size(); i++)
			std::cout << test[i] << " " ;
		std::cout << std::endl;
	}
    // {
    //     ft::vector<int> test;
    //     test.insert(test.begin(), 4, 1);
    //     test.insert(test.begin() + 2, 4 ,2);
    //     test.insert(test.begin() + 3, 4, 3);
    //     test.insert(test.begin() + 4, 4, 4);
    //     ft::vector<int>::iterator iter;
    //     iter = test.begin();
    //     for (int i =0; i < 4; i++)
    //         std::cout << test[i] << " ";
	// 	std::cout << std::endl;
    //     std::cout << *(iter++) << std::endl;
    //     std::cout << *iter << std::endl;
	// 	std::cout << std::endl;
    // }
    // {
	// 	std::cout << "====== std =======" << std::endl;
    //     std::vector<int> test;
    //     test.insert(test.begin(),4, 1);
    //     test.insert(test.begin() + 2, 4 ,2);
    //     test.insert(test.begin() + 3, 4, 3);
    //     test.insert(test.begin() + 4, 4, 4);
    //     std::vector<int>::iterator iter;
    //     for (int i =0; i < 4; i++)
    //         std::cout << test[i] << " "	;
	// 	std::cout << std::endl;
    //     iter = test.begin();
    //     std::cout << *(iter++) << std::endl;
    //     std::cout << *iter << std::endl;
    // }
	// { //resize
	// 	std::vector<int> test;

	// 	test.insert(test.begin(), 1);
	// 	test.insert(test.begin() + 1, 2);
	// 	test.insert(test.begin(), 3);
	// 	test.insert(test.begin(), 4);

	// 	test.resize(8, 6);
	// 	std::cout << test.size() << std::endl;
	// 	for (int i = 0; i < 8; i++)
	// 		std::cout << test[i] << " ";
	// 	std::cout << std::endl;
	// }
	// { //resize
	// 	ft::vector<int> test;

	// 	test.insert(test.begin(), 1);
	// 	test.insert(test.begin() + 1, 2);
	// 	test.insert(test.begin(), 3);
	// 	test.insert(test.begin(), 4);

	// 	test.resize(8, 6);
	// 	std::cout << test.size() << std::endl;
	// 	for (int i = 0; i < 8; i++)
	// 		std::cout << test[i] << " ";
	// }
	// { //insert
	// 	std::vector<int> test;
	// 	test.insert(test.begin(), 4,  5);
	// 	std::cout << test.size() << " " << test.capacity() << std::endl;
	// 	// test.insert(test.begin(), 4);
	// 	// test.insert(test.begin(), 3);
	// 	// test.insert(test.begin(), 2);
	// 	// test.insert(test.begin(), 1);
	// 	// test.insert(test.begin() + 2, 4, 6);
	// 	for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
	// 	{
	// 		std::cout << *it << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
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
