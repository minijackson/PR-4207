#include "box2d_iterator.hpp"

#include <iostream>

namespace image {

	Box2DIterator::Box2DIterator(size_t height, size_t width, Point2D value)
	      : theHeight(height)
	      , theWidth(width)
	      , value(value) {}

	Box2DIterator::Box2DIterator()
	      : value{0, 0}
	      , end(true) {}

	size_t Box2DIterator::height() const {
		return theHeight;
	}

	size_t Box2DIterator::width() const {
		return theWidth;
	}

	bool Box2DIterator::isEnd() const {
		return end;
	}

	auto Box2DIterator::operator*() const -> value_type {
#ifndef NDEBUG
		if(end) {
			std::cerr << "Dereferencing past-the-end Point2DIterator" << std::endl;
			std::exit(-1);
		}
#endif

		return value;
	}

	bool Box2DIterator::operator==(Box2DIterator const& other) const {
		return (end && other.end) || ((end == other.end) && (value == other.value));
	}

	bool Box2DIterator::operator!=(Box2DIterator const& other) const {
		return !(*this == other);
	}

	Box2DIterator& Box2DIterator::operator++() {
		increment_value();
		return *this;
	}

	Box2DIterator& Box2DIterator::operator++(int) {
		// decltype(auto) to remove references, const modifier, etc.
		decltype(auto) before = *this;
		increment_value();
		return before;
	}

	void Box2DIterator::increment_value() {
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
