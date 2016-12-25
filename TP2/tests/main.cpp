#include "../src/concepts.hpp"
#include "../src/image.hpp"
#include "../src/point2d.hpp"
#include "../src/box2d.hpp"
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

	std::cout << d1.width() << ", " << d1.height() << std::endl;

	image::Image2D<bool> im(d1);

	im[{1, 2}] = true;

	for(size_t i = 0; i < 10; ++i) {
		for(size_t j = 0; j < 10; ++j) {
			if(i == 1 && j == 2) {
				assert((im[{i, j}]));
			} else {
				assert((!im[{i, j}]));
			}
		}
	}

	print_domain(d1);
}
