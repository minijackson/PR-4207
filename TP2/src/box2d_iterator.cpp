#include "box2d_iterator.hpp"

namespace image {

	Box2DIterator::Box2DIterator(value_type topLeft, value_type bottomRight, value_type value)
	      : theTopLeft(topLeft)
	      , theBottomRight(bottomRight)
	      , value(value) {}

	Box2DIterator::Box2DIterator()
	      : theTopLeft()
	      , theBottomRight()
	      , value()
	      , end(true) {}

	auto Box2DIterator::topLeft() const -> value_type {
		return theTopLeft;
	}

	auto Box2DIterator::bottomRight() const -> value_type {
		return theBottomRight;
	}

	bool Box2DIterator::isEnd() const {
		return end;
	}

	auto Box2DIterator::operator*() const -> value_type {
#ifndef NDEBUG
		if(end) {
			throw std::runtime_error("Dereferencing past-the-end Point2DIterator");
		}
#endif

		return value;
	}

	bool Box2DIterator::operator==(Box2DIterator const& other) const {
		return (end and other.end) or ((end == other.end) and (value == other.value));
	}

	bool Box2DIterator::operator!=(Box2DIterator const& other) const {
		return not (*this == other);
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
		if(value.x() == theBottomRight.x() - 1) {
			if(value.y() == theBottomRight.y() - 1) {
				end = true;
			} else {
				value.x() = theTopLeft.x();
				++value.y();
			}
		} else {
			++value.x();
		}
	}

}
