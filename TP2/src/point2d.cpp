#include "point2d.hpp"

namespace image {

	Point2D::coord_type& Point2D::x() {
		return theX;
	}

	Point2D::coord_type const& Point2D::x() const {
		return theX;
	}

	Point2D::coord_type& Point2D::y() {
		return theY;
	}

	Point2D::coord_type const& Point2D::y() const {
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

	bool Point2D::operator==(Point2D const& other) const {
		return (theX == other.theX) and (theY == other.theY);
	}

	bool Point2D::operator!=(Point2D const& other) const {
		return not (*this == other);
	}

	bool Point2D::operator<(Point2D const& other) const {
		if(theX == other.theX) {
			return theY < other.theY;
		}

		return theX < other.theX;
	}

	Point2D Point2D::operator+(Point2D const& other) const {
		return {theX + other.theX, theY + other.theY};
	}

	auto Point2D::operator-(Point2D const& other) const -> difference_type {
		return {theX - other.theX, theY - other.theY};
	}


} // namespace image
