#pragma once

#include "common.hpp"

template <Scalar Type, unsigned int Size>
class Vec
{

	typedef Vec<Type, Size> Vec_t;

public:

	Vec()
	{
		for (unsigned int i = 0; i < Size; ++i)
		{
			data[i] = Type();
		}
	}

	Vec(std::initializer_list<Type> list)
	{
		if (list.size() != Size)
		{
			throw std::invalid_argument("Initializer list size does not match vector size.");
		}

		auto it = list.begin();
		for (unsigned int i = 0; i < Size; ++i)
		{
			data[i] = *it++;
		}
	}

	Vec(const Vec_t & other)
	{
		for (unsigned int i = 0; i < Size; ++i)
		{
			data[i] = other.data[i];
		}
	}

	Vec(Vec_t && other) noexcept
	{
		for (unsigned int i = 0; i < Size; ++i)
		{
			data[i] = std::move(other.data[i]);
		}
	}

	~Vec() = default;

	Vec_t & operator=(const Vec_t & other)
	{
		if (this != &other)
		{
			for (unsigned int i = 0; i < Size; ++i)
			{
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	Vec_t & operator=(Vec_t && other) noexcept
	{
		if (this != &other)
		{
			for (unsigned int i = 0; i < Size; ++i)
			{
				data[i] = std::move(other.data[i]);
			}
		}
		return *this;
	}


	Type & operator[](unsigned int index)
	{
		if (index >= Size)
			throw std::out_of_range("Index out of range.");
		
		return data[index];
	}

	const Type & operator[](unsigned int index) const
	{
		if (index >= Size)
			throw std::out_of_range("Index out of range.");
		
		return data[index];
	}


	Vec_t operator+(const Vec_t & other) const
	{
		Vec_t result;
		for (unsigned int i = 0; i < Size; ++i)
		{
			result.data[i] = this->data[i] + other.data[i];
		}
		return result;
	}

	Vec_t operator-(const Vec_t & other) const
	{
		Vec_t result;
		for (unsigned int i = 0; i < Size; ++i)
		{
			result.data[i] = this->data[i] - other.data[i];
		}
		return result;
	}

	template <Scalar T>
	Vec_t operator*(T scalar) const
	{
		Vec_t result;
		for (unsigned int i = 0; i < Size; ++i)
		{
			result.data[i] = this->data[i] * scalar;
		}
		return result;
	}


	template <Scalar T>
	static Vec_t linearCombination(const Vec_t * const vecs, const T * const scalars, unsigned int count)
	{
		Vec_t result;
		for (unsigned int i = 0; i < Size; ++i)
		{
			result.data[i] = 0;
			for (unsigned int j = 0; j < count; ++j)
			{
				result.data[i] += vecs[j].data[i] * scalars[j];
			}
		}
		return result;
	}

private:

	Type data[Size];

};

template <typename Type, unsigned int Size>
std::ostream & operator<<(std::ostream & os, const Vec<Type, Size> & vec)
{
	os << "vec" << Size << "[";
	for (unsigned int i = 0; i < Size; ++i)
	{
		os << vec[i];
		if (i < Size - 1)
			os << ", ";
	}
	os << "]";
	return os;
}
