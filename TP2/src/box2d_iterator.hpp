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

		Box2DIterator(size_t height, size_t width, Point2D value = Point2D{0, 0});
		Box2DIterator();

		coord_type height() const;
		coord_type width() const;

		bool isEnd() const;

		value_type operator*() const;

		bool operator==(Box2DIterator const& other) const;
		bool operator!=(Box2DIterator const& other) const;

		Box2DIterator& operator++(int);
		Box2DIterator& operator++();

	protected:
		void increment_value();

		coord_type theHeight;
		coord_type theWidth;
		Point2D value;
		bool end = false;
	};

} // namespace image
