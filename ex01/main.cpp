#include "Matrix.hpp"
#include "Vector.hpp"

#include <iostream>

int main()
{
	{
		Vec<float, 3> v1{1.0f, 0.0f, 0.0f};
		Vec<float, 3> v2{0.0f, 1.0f, 0.0f};
		Vec<float, 3> v3{0.0f, 0.0f, 1.0f};

		Vec<float, 3> vecs[] = {v1, v2, v3};
		float scalars[] = {10.0f, -2.0f, 0.5f};

		Vec<float, 3> result = Vec<float, 3>::linearCombination(vecs, scalars, 3);

		std::cout << "Result of linear combination: " << result << std::endl;
	}

	{
		Vec<float, 3> v1{1.0f, 2.0f, 3.0f};
		Vec<float, 3> v2{0.0f, 10.0f, -100.0f};

		Vec<float, 3> vecs[] = {v1, v2};
		float scalars[] = {10.0f, -2.0f};

		Vec<float, 3> result = Vec<float, 3>::linearCombination(vecs, scalars, 2);

		std::cout << "Result of linear combination: " << result << std::endl;
	}

	return 0;
}