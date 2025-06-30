#include "Matrix.hpp"
#include "Vector.hpp"

#include <iostream>

int main()
{
	std::cout << lerp(0., 1., 0) << std::endl;
	std::cout << lerp(0., 1., 1) << std::endl;
	std::cout << lerp(0., 1., 0.5) << std::endl;
	std::cout << lerp(21., 42., 0.3) << std::endl;
	std::cout << lerp(Vec<float, 2>({2.f, 1.f}), Vec<float, 2>({4.f, 2.f}), 0.3) << std::endl;
	std::cout << lerp(Mat<float, 2, 2>({2.f, 1.f, 3.f, 4.f}), Mat<float, 2, 2>({20.f, 10.f, 30.f, 40.f}), 0.5) << std::endl;

	return 0;
}