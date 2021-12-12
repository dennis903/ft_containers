#include <iostream>
#include <vector>
#include "./includes/vector.hpp"

int         main()
{
	ft::vector<int> vt(10, 5);
	ft::vector<int> vt2;

	vt2 = vt;
	std::cout << &vt << std::endl;
	std::cout << &vt2 << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << vt2[i] << std::endl;
}