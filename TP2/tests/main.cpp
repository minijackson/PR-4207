#include "../src/concepts.hpp"
#include "../src/point2d.hpp"
#include "../src/utils.hpp"

#include <iostream>

int main() {
	using image::operator<<;

	image::Point2D p1{1, 2};

	std::cout << p1 << std::endl;
}
