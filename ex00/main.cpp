#include "Matrix.hpp"
#include "Vector.hpp"

#include <iostream>

int main()
{
	Mat<float, 2, 3> mat1 = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
	Mat<float, 2, 3> mat2 = {6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f};
	std::cout << (mat1 + mat2) << std::endl;
	std::cout << (mat1 - mat2) << std::endl;
	std::cout << (mat1 * 2.0f) << std::endl;

	Vec<float, 6> vec1 = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
	Vec<float, 6> vec2 = {6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f};
	std::cout << (vec1 + vec2) << std::endl;
	std::cout << (vec1 - vec2) << std::endl;
	std::cout << (vec1 * 2.0f) << std::endl;
	return 0;
}