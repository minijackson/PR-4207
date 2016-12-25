#pragma once

#include "point2d.hpp"
#include "box2d_iterator.hpp"

#include <cstddef>

namespace image {

	class Box2D {
	public:
		using point_type     = Point2D;
		using const_iterator = Box2DIterator;

		Box2D() = delete;

		Box2D(size_t height, size_t width);

		size_t height() const;
		size_t width() const;

		bool contains(point_type point) const;

		const_iterator begin() const;
		const_iterator end() const;

	protected:
		size_t theHeight;
		size_t theWidth;
	};

}
