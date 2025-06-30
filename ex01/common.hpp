#pragma once

#include <iostream>
#include <type_traits>
#include <initializer_list>
#include <concepts>
#include <stdexcept>
#include <cmath>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;
