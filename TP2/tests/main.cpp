#include "../src/box2d.hpp"
#include "../src/concepts.hpp"
#include "../src/image.hpp"
#include "../src/neighbours2d_iterator.hpp"
#include "../src/point2d.hpp"
#include "../src/utils.hpp"

#include <iostream>

#include <cassert>

template <typename T>
requires(concepts::Domain<T>)
void print_domain(T d) {
	std::cout << "==============================" << std::endl;
	for(typename T::point_type const& i : d) {
		std::cout << i << std::endl;
	}
}

int main() {
	using image::operator<<;

	image::Point2D p1{1, 2};
	image::Point2D p2;

	std::cout << p1 << std::endl;

	image::Box2D d1(10, 10);

	assert((d1.contains({4, 2})));
	assert((not d1.contains({13, 37})));
	assert((not d1.contains({-1, 5})));
	assert((not d1.contains({1, -5})));

	std::cout << d1.topLeft() << ", " << d1.bottomRight() << std::endl;

	image::Image2D<bool> im1(d1);
	im1[{2, 2}] = true;

	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			if(i == 2 and j == 2) {
				assert((im1[{i, j}]));
			} else {
				assert((not im1[{i, j}]));
			}
		}
	}

	// FTW
	im1[{7, 2}] = true;

	im1[{1, 6}] = true;
	im1[{2, 7}] = true;
	im1[{3, 7}] = true;
	im1[{4, 7}] = true;
	im1[{5, 7}] = true;
	im1[{6, 7}] = true;
	im1[{7, 7}] = true;
	im1[{8, 6}] = true;

	std::cout << im1;

	image::Image2D<size_t> im2(d1);
	im2[{7, 3}] = 42;
	std::cout << im2;

	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			if(i == 7 and j == 3) {
				assert((im2[{i, j}] == 42));
			} else {
				assert((im2[{i, j}] == 0));
			}
		}
	}

	print_domain(d1);

	std::cout << "==============================" << std::endl;
	{
		auto it = d1.neighbours_begin(p1), end = d1.neighbours_end();
		while(it != end) {
			std::cout << *it << std::endl;
			++it;
		}
	}
}
