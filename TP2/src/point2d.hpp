#pragma once

#include <cstddef>

namespace image {

	class Point2D {
	public:
		using coord_type                         = int;
		using difference_type                    = Point2D;
		static constexpr size_t const dimensions = 2;

		constexpr Point2D();
		constexpr Point2D(coord_type x, coord_type y);

		coord_type& x();
		coord_type const& x() const;
		coord_type& y();
		coord_type const& y() const;

		template <size_t dimension>
		coord_type& coord();

		template <size_t dimension>
		coord_type coord() const;

		bool operator==(Point2D const& other) const;
		bool operator!=(Point2D const& other) const;
		bool operator<(Point2D const& other) const;

		Point2D operator+(Point2D const& other) const;
		difference_type operator-(Point2D const& other) const;

	protected:
		coord_type theX;
		coord_type theY;
	};

}

#include "point2d.tcc"
