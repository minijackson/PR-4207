#pragma once

#include "concepts.hpp"

#include <iostream>
#include <functional>
#include <utility>

namespace image {

	namespace impl {

		template <typename Point, size_t dimensions, size_t i = dimensions>
		requires(concepts::Point<Point>)
		constexpr std::enable_if_t<(i == 1)> print_point(std::ostream& os, Point const& point) {
			os << point.template coord<dimensions - i>();
		}

		template <typename Point, size_t dimensions, size_t i = dimensions>
		requires(concepts::Point<Point>)
		constexpr std::enable_if_t<(i > 1)> print_point(std::ostream& os, Point const& point) {
			os << point.template coord<dimensions - i>() << ", ";
			print_point<Point, dimensions, i - 1>(os, point);
		}

	} // namespace impl

	template <typename Point>
	requires(concepts::Point<Point>)
	std::ostream& operator<<(std::ostream& os, Point const& point) {
		os << "(";
		impl::print_point<Point, Point::dimensions>(os, point);
		os << ")";
		return os;
	}

} // namespace image
