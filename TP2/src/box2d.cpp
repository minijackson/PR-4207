#include "box2d.hpp"

namespace image {

	Box2D::Box2D(size_t height, size_t width)
	      : theHeight(height)
	      , theWidth(width) {}

	bool Box2D::contains(point_type point) const {
		return (point.x() < theWidth) && (point.y() < theHeight);
	}

	size_t Box2D::height() const {
		return theHeight;
	}

	size_t Box2D::width() const {
		return theWidth;
	}

	auto Box2D::begin() const -> const_iterator {
		return const_iterator(theHeight, theWidth);
	}

	auto Box2D::end() const -> const_iterator {
		return const_iterator();
	}

} // namespace image
