#pragma once

#include "concepts.hpp"

#include <iostream>
#include <functional>
#include <utility>

namespace image {

	namespace impl {

		template <typename T, size_t i, size_t j = i>
		requires(concepts::Point<T>)
		constexpr std::enable_if_t<(j == 1)> print_point(std::ostream& os, T const& point) {
			os << point.template coord<i - j>();
		}

		template <typename T, size_t i, size_t j = i>
		requires(concepts::Point<T>)
		constexpr std::enable_if_t<(j > 1)> print_point(std::ostream& os, T const& point) {
			os << point.template coord<i - j>() << ", ";
			print_point<T, i, j - 1>(os, point);
		}

	} // namespace impl

	template <typename T>
	requires(concepts::Point<T>)
	std::ostream& operator<<(std::ostream& os, T const& point) {
		os << "(";
		impl::print_point<T, T::dimensions>(os, point);
		os << ")";
		return os;
	}

} // namespace image
