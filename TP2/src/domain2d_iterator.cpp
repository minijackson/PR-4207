#include "domain2d_iterator.hpp"

#include <iostream>

namespace image {

	Domain2DIterator::Domain2DIterator(size_t height, size_t width, Point2D value)
	      : theHeight(height)
	      , theWidth(width)
	      , value(value) {}

	Domain2DIterator::Domain2DIterator()
	      : value{0, 0}
	      , end(true) {}

	size_t Domain2DIterator::height() const {
		return theHeight;
	}

	size_t Domain2DIterator::width() const {
		return theWidth;
	}

	auto Domain2DIterator::operator*() const -> value_type {
#ifndef NDEBUG
		if(end) {
			std::cerr << "Dereferencing end Point2DIterator" << std::endl;
			std::exit(-1);
		}
#endif

		return value;
	}

	Domain2DIterator& Domain2DIterator::operator++(int) {
		increment_value();
		return *this;
	}

	Domain2DIterator& Domain2DIterator::operator++() {
		// decltype(auto) to remove references, const modifier, etc.
		decltype(auto) before = *this;
		increment_value();
		return before;
	}

	void Domain2DIterator::increment_value() {
		if(value.x() == theWidth - 1) {
			if(value.y() == theHeight - 1) {
				end = true;
			} else {
				value.x() = 0;
				++value.y();
			}
		} else {
			++value.x();
		}
	}

} // namespace image
