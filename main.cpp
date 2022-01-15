#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <utility>
#include <functional>
#include <random>
#include "includes/vector.hpp"
#include "utils/pair.hpp"
#include "utils/lexicographical_compare.hpp"
#include "utils/iterator_traits.hpp"

// void	print_container(std::vector<int> &c)
// {
// 	for (size_t i = 0; i < c.size(); i++)
// 	{
// 		std::cout << c[i] << " ";
// 	}
// 	std::cout << std::endl;
// }
// void	ft_print_container(ft::vector<int> &c)
// {
// 	for (size_t i = 0; i < c.size(); i++)
// 	{
// 		std::cout << c[i] << " ";
// 	}
// 	std::cout << std::endl;
// }

// template< class it >
// void function(it i1, it i2)
// {
//     typename ft::iterator_traits<it>::iterator_category cat;
//     std::cout << typeid(cat).name() << std::endl;
//     while (i1 != i2)
//     {
//         typename ft::iterator_traits<it>::value_type x;
//         x = *i1;
//         std::cout << x << " ";
//         i1++;
//     };
//     std::cout << std::endl;
// }

struct trivial
    {
    int val;
    };

int main()
{
	ft::vector<char> v1;
	ft::vector<char> v2;

	v1.push_back('d');
	v1.push_back('e');
	v1.push_back('f');
	v1.push_back('g');
	v2.push_back('b');
	v2.push_back('a');
	v2.push_back('d');
	v2.push_back('c');

	std::mt19937 g;
	while (!ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()))
	{
		for (ft::vector<char>::iterator it = v1.begin(); it != v1.end(); it++)
			std::cout << *it << " ";
		std::cout << ">= ";
		for (ft::vector<char>::iterator it = v2.begin(); it != v2.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	//     std::cout << "is_integral<trivial> == " << std::boolalpha
    //     << std::is_integral<trivial>::value << std::endl;
    // std::cout << "is_integral<int> == " << std::boolalpha
    //     << std::is_integral<int>::value << std::endl;
    // std::cout << "is_integral<float> == " << std::boolalpha
    //     << std::is_integral<float>::value << std::endl;
	// ft::vector<int> v;
	// v.push_back(1);
	// v.push_back(2);
	// v.push_back(3);
	// v.push_back(4);
	// v.push_back(5);

	//  for (ft::vector<int>::iterator n = v.begin(); n != v.end(); n++) {
    //     std::cout << *n << ' ';
    // }
    // std::cout << '\n';
    // ft::vector<char> vc(10, 'a');
    // function(vc.begin(), vc.end());
	// {
	// 	std::map<int, int>::iterator it;
	// }
	// { //pair
	// 	int n = 1;
    // 	int a[5] = {1, 2, 3, 4, 5};
	// 	auto p = std::make_pair(n, a[1]);
	// 	std::cout << p.first << " " << p.second << std::endl;
	// }
	// { //pair
	// 	int n = 1;
    // 	int a[5] = {1, 2, 3, 4, 5};
	// 	auto p = ft::make_pair(n, a[1]);
	// 	std::cout << p.first << " " << p.second << std::endl;
	// }
	// { // ==
	// 	std::cout << "=========== std ===========" << std::endl;
	// 	std::vector<int> vt;
	// 	vt.push_back(1);
	// 	vt.push_back(2);
	// 	vt.push_back(5);
	// 	vt.push_back(4);
	// 	vt.push_back(5);
	// 	vt.push_back(6);
	// 	vt.push_back(7);
	// 	vt.push_back(8);
	// 	vt.push_back(9);
	// 	vt.push_back(11);
	// 	std::vector<int> vt2;
	// 	vt2.push_back(1);
	// 	vt2.push_back(2);
	// 	vt2.push_back(3);
	// 	vt2.push_back(5);
	// 	vt2.push_back(5);
	// 	vt2.push_back(6);
	// 	vt2.push_back(7);
	// 	vt2.push_back(8);
	// 	vt2.push_back(9);
	// 	vt2.push_back(10);
	// 	// vt2.push_back(11);
	// 	bool result = vt <= vt2;
	// 	std::cout << result << std::endl;
	// }
	// { // ==
	// 	std::cout << "=========== ft ===========" << std::endl;
	// 	ft::vector<int> vt;
	// 	vt.push_back(1);
	// 	vt.push_back(2);
	// 	vt.push_back(3);
	// 	vt.push_back(4);
	// 	vt.push_back(5);
	// 	vt.push_back(6);
	// 	vt.push_back(7);
	// 	vt.push_back(8);
	// 	vt.push_back(9);
	// 	vt.push_back(10);
	// 	ft::vector<int> vt2;
	// 	vt2.push_back(1);
	// 	vt2.push_back(2);
	// 	vt2.push_back(3);
	// 	vt2.push_back(4);
	// 	vt2.push_back(5);
	// 	vt2.push_back(6);
	// 	vt2.push_back(7);
	// 	vt2.push_back(8);
	// 	vt2.push_back(9);
	// 	vt2.push_back(10);
	// 	// vt2.push_back(11);
	// 	bool result = vt != vt2;
	// 	std::cout << result << std::endl;
	// }
	// { //swap
	// 	std::cout << "=========== std ===========" << std::endl;
	// 	std::vector<int> vt;
	// 	vt.push_back(1);
	// 	vt.push_back(2);
	// 	vt.push_back(3);
	// 	vt.push_back(4);
	// 	vt.push_back(5);
	// 	vt.push_back(6);
	// 	vt.push_back(7);
	// 	vt.push_back(8);
	// 	vt.push_back(9);
	// 	vt.push_back(10);
	// 	std::vector<int> vt2;
	// 	vt2.push_back(11);
	// 	vt2.push_back(12);
	// 	vt2.push_back(13);
	// 	vt2.push_back(14);
	// 	std::cout << "--------- before swap --------" << std::endl;
	// 	print_container(vt);
	// 	print_container(vt2);
	// 	vt.swap(vt2);
	// 	std::cout << "--------- after swap --------" << std::endl;
	// 	print_container(vt);
	// 	print_container(vt2);
	// }
	// {
	// 	std::cout << "=========== ft ===========" << std::endl;
	// 	ft::vector<int> vt;
	// 	vt.push_back(1);
	// 	vt.push_back(2);
	// 	vt.push_back(3);
	// 	vt.push_back(4);
	// 	vt.push_back(5);
	// 	vt.push_back(6);
	// 	vt.push_back(7);
	// 	vt.push_back(8);
	// 	vt.push_back(9);
	// 	vt.push_back(10);
	// 	ft::vector<int> vt2;
	// 	vt2.push_back(11);
	// 	vt2.push_back(12);
	// 	vt2.push_back(13);
	// 	vt2.push_back(14);
	// 	std::cout << "--------- before swap --------" << std::endl;
	// 	ft_print_container(vt);
	// 	ft_print_container(vt2);
	// 	vt.swap(vt2);
	// 	std::cout << "--------- after swap --------" << std::endl;
	// 	ft_print_container(vt);
	// 	ft_print_container(vt2);

	// }
	// { //pop_back
	// 	std::cout << "=========== std ===========" << std::endl;
	// 	std::vector<int> vt;
	// 	vt.push_back(1);
	// 	vt.push_back(2);
	// 	vt.push_back(3);
	// 	vt.push_back(4);
	// 	vt.push_back(5);
	// 	vt.push_back(6);
	// 	vt.push_back(7);
	// 	vt.push_back(8);
	// 	vt.push_back(9);
	// 	vt.push_back(10);
	// 	vt.pop_back();
	// 	vt.pop_back();
	// 	print_container(vt);
	// 	std::cout << "size: " << vt.size() << std::endl;
	// 	std::cout << "capacity: " << vt.capacity() << std::endl;
	// }
	// {
	// 	std::cout << "=========== ft ===========" << std::endl;
	// 	ft::vector<int> vt;
	// 	vt.push_back(1);
	// 	vt.push_back(2);
	// 	vt.push_back(3);
	// 	vt.push_back(4);
	// 	vt.push_back(5);
	// 	vt.push_back(6);
	// 	vt.push_back(7);
	// 	vt.push_back(8);
	// 	vt.push_back(9);
	// 	vt.push_back(10);
	// 	vt.pop_back();
	// 	vt.pop_back();
	// 	ft_print_container(vt);
	// 	std::cout << "size: " << vt.size() << std::endl;
	// 	std::cout << "capacity: " << vt.capacity() << std::endl;

	// }
	// { //erase
	// 	std::cout << "=========== std ===========" << std::endl;
	// 	std::vector<int> vt;
	// 	vt.push_back(1);
	// 	vt.push_back(2);
	// 	vt.push_back(3);
	// 	vt.push_back(4);
	// 	vt.push_back(5);
	// 	vt.push_back(6);
	// 	vt.push_back(7);
	// 	vt.push_back(8);
	// 	vt.push_back(9);
	// 	vt.push_back(10);
	// 	print_container(vt);
	// 	std::cout << "size: " << vt.size() << std::endl;
	// 	std::cout << "capacity: " << vt.capacity() << std::endl;
	// 	std::cout << "--------- erase --------" << std::endl;
	// 	vt.erase(vt.begin(), vt.begin() + 1);
	// 	print_container(vt);
	// 	std::cout << "size: " << vt.size() << std::endl;
	// 	std::cout << "capacity: " << vt.capacity() << std::endl;
	// 	std::cout << "--------- erase2 --------" << std::endl;
	// 	vt.erase(vt.begin() + 2, vt.begin() + 5);
	// 	print_container(vt);
	// 	std::cout << "size: " << vt.size() << std::endl;
	// 	std::cout << "capacity: " << vt.capacity() << std::endl;
	// 	std::cout << "\n";
	// }
	// {
	// 	std::cout << "=========== ft ===========" << std::endl;
	// 	ft::vector<int> vt;
	// 	vt.push_back(1);
	// 	vt.push_back(2);
	// 	vt.push_back(3);
	// 	vt.push_back(4);
	// 	vt.push_back(5);
	// 	vt.push_back(6);
	// 	vt.push_back(7);
	// 	vt.push_back(8);
	// 	vt.push_back(9);
	// 	vt.push_back(10);
	// 	ft_print_container(vt);
	// 	std::cout << "size: " << vt.size() << std::endl;
	// 	std::cout << "capacity: " << vt.capacity() << std::endl;
	// 	std::cout << "--------- erase --------" << std::endl;
	// 	vt.erase(vt.begin(), vt.begin() + 1);
	// 	ft_print_container(vt);
	// 	std::cout << "size: " << vt.size() << std::endl;
	// 	std::cout << "capacity: " << vt.capacity() << std::endl;
	// 	std::cout << "--------- erase2 --------" << std::endl;
	// 	vt.erase(vt.begin() + 2, vt.begin() + 5);
	// 	ft_print_container(vt);
	// 	std::cout << "size: " << vt.size() << std::endl;
	// 	std::cout << "capacity: " << vt.capacity() << std::endl;

	// }
	//insert
	// {
	// 	std::vector<int> test(4, 10);
	// 	std::vector<int> test2;
	// 	std::vector<int>::iterator it = test.begin();

	// 	test2.push_back(1);
	// 	test2.push_back(2);
	// 	test2.push_back(3);
	// 	test2.push_back(4);
	// 	test.insert(it+2, test2.begin(), test2.end());
	// 	for (size_t i = 0; i < test.size(); i++)
	// 		std::cout << test[i] << " " ;
	// 	std::cout << std::endl;
	// }
	// {
	// 	std::cout << "======= ft ========" << std::endl;
	// 	ft::vector<int> test(4, 10);
	// 	ft::vector<int> test2;
	// 	ft::vector<int>::iterator it = test.begin();

	// 	test2.push_back(1);
	// 	test2.push_back(2);
	// 	test2.push_back(3);
	// 	test2.push_back(4);
	// 	test.insert(it+2, test2.begin(), test2.end());
	// 	for (size_t i = 0; i < test.size(); i++)
	// 		std::cout << test[i] << " " ;
	// 	std::cout << std::endl;
	// }
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
