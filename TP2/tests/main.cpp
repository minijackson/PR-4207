#include "../src/concepts.hpp"
#include "../src/point2d.hpp"
#include "../src/domain2d.hpp"
#include "../src/utils.hpp"

#include <iostream>

template <typename T>
requires(concepts::DomainIterator<T>)
void print_it(T it) {
	for(size_t i = 0; i < 1'000; ++i) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main() {
	using image::operator<<;

	image::Point2D p1{1, 2};

	std::cout << p1 << std::endl;

	image::Domain2D d1(10, 10);

	std::cout << d1.width() << ", " << d1.height() << std::endl;

	image::Domain2D::const_iterator beginning = d1.begin();

	print_it(beginning);
}
