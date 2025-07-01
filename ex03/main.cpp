#include "Matrix.hpp"
#include "Vector.hpp"

#include <iostream>

int main()
{
	std::cout << Vec<float, 2>({0.0f, 0.0f}).dot<float>(Vec<float, 2>({1.0f, 1.0f})) << std::endl;
	std::cout << Vec<float, 2>({1.0f, 1.0f}).dot<float>(Vec<float, 2>({1.0f, 1.0f})) << std::endl;
	std::cout << Vec<float, 2>({-1.0f, 6.0f}).dot<float>(Vec<float, 2>({3.0f, 2.0f})) << std::endl;

	return 0;
}