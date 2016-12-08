#include "../src/vector.hpp"
#include "../src/matrix.hpp"
#include "../src/ops.hpp"

#include <iostream>

#include <cassert>

int main() {
	/*============*/
	/*== Vector ==*/
	/*============*/
	tp1::Vector<int, 3> v1{}, v2{};

	v1[0] = 0;
	v1[1] = 1;
	v1[0] = 0;

	assert(v1[1] == 1);

	v2 = v1;

	assert(v2[1] == 1);

	/*============*/
	/*== Matrix ==*/
	/*============*/
	tp1::Matrix<int, 3, 3> m1{}, m2{};

	for(size_t i = 0; i < 3; ++i) {
		for(size_t j = 0; j < 3; ++j) {
			m1(i, j) = 0;
		}
	}

	m1(0, 0) = 1;
	m1(1, 1) = 1;
	m1(2, 2) = 1;

	assert(m1 * v1 == v1);

	/*==========*/
	/*== Fill ==*/
	/*==========*/
	{
		tp1::Vector<int, 3> expected{};
		for(size_t i = 0; i < 3; ++i) {
			expected[i] = 42;
		}

		fill(v2, 42);

		assert(v2 == expected);
	}

	{
		tp1::Matrix<int, 3, 3> expected{};
		for(size_t i = 0; i < 3; ++i) {
			for(size_t j = 0; j < 3; ++j) {
				expected(i, j) = 42;
			}
		}

		fill(m2, 42);

		assert(m2 == expected);
	}
}
