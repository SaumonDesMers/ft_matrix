#pragma once

#include "common.hpp"


template <Scalar Type, unsigned int Rows, unsigned int Cols>
class Mat
{

	typedef Mat<Type, Rows, Cols> Mat_t;

public:

	Mat()
	{
		for (unsigned int i = 0; i < Rows * Cols; ++i)
		{
			data[i] = Type();
		}
	}

	Mat(std::initializer_list<Type> list)
	{
		if (list.size() != Rows * Cols)
		{
			throw std::invalid_argument("Initializer list size does not match matrix dimensions.");
		}

		auto it = list.begin();
		for (unsigned int i = 0; i < Rows * Cols; ++i)
		{
			data[i] = *it++;
		}
	}

	Mat(const Mat_t & other)
	{
		for (unsigned int i = 0; i < Rows * Cols; ++i)
		{
			data[i] = other.data[i];
		}
	}

	Mat(const Mat_t && other) noexcept
	{
		for (unsigned int i = 0; i < Rows * Cols; ++i)
		{
			data[i] = std::move(other.data[i]);
		}
	}

	~Mat() = default;

	Mat_t & operator=(const Mat_t & other)
	{
		if (this != &other)
		{
			for (unsigned int i = 0; i < Rows * Cols; ++i)
			{
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	Mat_t & operator=(Mat_t && other) noexcept
	{
		if (this != &other)
		{
			for (unsigned int i = 0; i < Rows * Cols; ++i)
			{
				data[i] = std::move(other.data[i]);
			}
		}
		return *this;
	}

	
	Type * operator[](unsigned int index)
	{
		if (index >= Rows)
		{
			throw std::out_of_range("Index out of range.");
		}
		return &data[index * Cols];
	}

	const Type * operator[](unsigned int index) const
	{
		if (index >= Rows)
		{
			throw std::out_of_range("Index out of range.");
		}
		return &data[index * Cols];
	}


	Mat_t operator+(const Mat_t & other) const
	{
		Mat_t result;
		for (unsigned int i = 0; i < Rows * Cols; ++i)
		{
			result.data[i] = this->data[i] + other.data[i];
		}
		return result;
	}

	Mat_t operator-(const Mat_t & other) const
	{
		Mat_t result;
		for (unsigned int i = 0; i < Rows * Cols; ++i)
		{
			result.data[i] = this->data[i] - other.data[i];
		}
		return result;
	}

	template <Scalar T>
	Mat_t operator*(const T & scalar) const
	{
		Mat_t result;
		for (unsigned int i = 0; i < Rows * Cols; ++i)
		{
			result.data[i] = this->data[i] * scalar;
		}
		return result;
	}

private:

	Type data[Rows * Cols];

};

template <Scalar Type, unsigned int Rows, unsigned int Cols>
std::ostream & operator<<(std::ostream & os, const Mat<Type, Rows, Cols> & mat)
{
	os << "mat" << Rows << "x" << Cols << "[";
	for (unsigned int i = 0; i < Rows; ++i)
	{
		os << "[";
		for (unsigned int j = 0; j < Cols; ++j)
		{
			os << mat[i][j];
			if (j < Cols - 1)
			{
				os << ", ";
			}
		}
		os << "]";
		if (i < Rows - 1)
		{
			os << ", ";
		}
	}
	os << "]";
	return os;
}