#pragma once

#include <cstddef>

namespace image {

	class Point2D {
	public:
		using coord_type                         = size_t;
		static constexpr size_t const dimensions = 2;

		Point2D() = default;
		Point2D(size_t x, size_t y);
		coord_type& x();
		coord_type& y();

		template <size_t dimension>
		coord_type& coord();

		template <size_t dimension>
		coord_type coord() const;

		bool operator==(Point2D const& other) const;
		bool operator!=(Point2D const& other) const;
		bool operator<(Point2D const& other) const;

	protected:
		size_t theX;
		size_t theY;
	};

} // namespace image

#include "point2d.tcc"
