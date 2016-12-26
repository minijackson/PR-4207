#pragma once

#include "box2d_iterator.hpp"
#include "neighbours2d_iterator.hpp"
#include "point2d.hpp"

#include <cstddef>

namespace image {

	class Box2D {
	public:
		using point_type          = Point2D;
		using coord_type          = typename Point2D::coord_type;
		using const_iterator      = Box2DIterator;
		using neighbours_iterator = Neighbours2DIterator<Box2D>;

		// Creates null-sized box
		Box2D() = default;

		Box2D(size_t height, size_t width);

		coord_type height() const;
		coord_type width() const;

		bool contains(point_type point) const;

		const_iterator begin() const;
		const_iterator end() const;

		neighbours_iterator neighbours_begin(point_type center) const;
		neighbours_iterator neighbours_end() const;

	protected:
		coord_type theHeight;
		coord_type theWidth;
	};

}
