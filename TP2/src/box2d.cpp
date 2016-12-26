#include "box2d.hpp"

namespace image {

	Box2D::Box2D(size_t height, size_t width)
	      : theHeight(height)
	      , theWidth(width) {}

	bool Box2D::contains(point_type point) const {
		return (0 <= point.x()) && (point.x() < theWidth) && (0 <= point.y()) &&
		       (point.y() < theHeight);
	}

	auto Box2D::height() const -> coord_type {
		return theHeight;
	}

	auto Box2D::width() const -> coord_type {
		return theWidth;
	}

	auto Box2D::begin() const -> const_iterator {
		return const_iterator(theHeight, theWidth);
	}

	auto Box2D::end() const -> const_iterator {
		return const_iterator();
	}

	auto Box2D::neighbours_begin(point_type center) const -> neighbours_iterator {
		return neighbours_iterator(*this, center);
	}

	auto Box2D::neighbours_end() const -> neighbours_iterator {
		return neighbours_iterator();
	}

}
