#pragma once

#include <iostream>
#include <type_traits>
#include <initializer_list>
#include <concepts>
#include <stdexcept>
#include <cmath>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <typename T, Scalar U>
T lerp(const T & a, const T & b, U t)
{
	// a * (1 - t) + b * t
	// a - a * t + b * t
	// a + (b - a) * t
	return a + (b - a) * t;
}