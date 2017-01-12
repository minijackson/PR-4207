#pragma once

#include "point2d.hpp"

#include <iterator>

#include <cstddef>

namespace image {

	class Box2D;

	class Box2DIterator {
	public:
		using domain_type = Box2D;
		using coord_type  = typename Point2D::coord_type;

		using value_type        = Point2D;
		using difference_type   = std::ptrdiff_t;
		using reference         = Point2D&;
		using pointer           = Point2D*;
		using iterator_category = std::forward_iterator_tag;

		Box2DIterator(value_type topLeft, value_type bottomRight, value_type value);
		Box2DIterator();

		value_type topLeft() const;
		value_type bottomRight() const;

		bool isEnd() const;

		value_type operator*() const;

		bool operator==(Box2DIterator const& other) const;
		bool operator!=(Box2DIterator const& other) const;

		Box2DIterator& operator++(int);
		Box2DIterator& operator++();

	protected:
		void increment_value();

		value_type theTopLeft;
		value_type theBottomRight;
		value_type value;
		bool end = false;
	};

} // namespace image
