#include "point2d.hpp"

namespace image {

	Point2D::Point2D(size_t x, size_t y)
	      : theX(x)
	      , theY(y) {}

	Point2D::coord_type& Point2D::x() {
		return theX;
	}

	Point2D::coord_type& Point2D::y() {
		return theY;
	}

	template <>
	Point2D::coord_type& Point2D::coord<0>() {
		return theX;
	}

	template <>
	Point2D::coord_type& Point2D::coord<1>() {
		return theY;
	}

	template <>
	Point2D::coord_type Point2D::coord<0>() const {
		return theX;
	}

	template <>
	Point2D::coord_type Point2D::coord<1>() const {
		return theY;
	}

} // namespace image