#include "box2d.hpp"

namespace image {

	Box2D::Box2D(coord_type width, coord_type height)
	      : theTopLeft{0, 0}
	      , theBottomRight{width, height} {}

	Box2D::Box2D(point_type topLeft, point_type bottomRight)
	      : theTopLeft(topLeft)
	      , theBottomRight(bottomRight) {}

	bool Box2D::contains(point_type point) const {
		return (theTopLeft.x() <= point.x()) and (point.x() < theBottomRight.x()) and
		       (theTopLeft.y() <= point.y()) and (point.y() < theBottomRight.y());
	}

	auto Box2D::topLeft() const -> point_type {
		return theTopLeft;
	}

	auto Box2D::bottomRight() const -> point_type {
		return theBottomRight;
	}

	auto Box2D::width() const -> coord_type {
		return theBottomRight.x() - theTopLeft.x();
	}

	auto Box2D::height() const -> coord_type {
		return theBottomRight.y() - theTopLeft.y();
	}

	auto Box2D::begin() const -> const_iterator {
		return const_iterator(theTopLeft, theBottomRight, theTopLeft);
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
