#pragma once

#include "point2d.hpp"
#include "domain2d_iterator.hpp"

#include <cstddef>

namespace image {

	class Domain2D {
	public:
		using point_type     = Point2D;
		using const_iterator = Domain2DIterator;

		Domain2D(size_t height, size_t width);

		size_t height() const;
		size_t width() const;

		const_iterator begin() const;
		const_iterator end() const;

	protected:
		size_t theHeight;
		size_t theWidth;
	};

} // namespace image
