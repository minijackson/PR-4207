#pragma once

#include "concepts.hpp"
#include "image.hpp"

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

	}

	template <typename Point>
	requires(concepts::Point<Point>)
	std::ostream& operator<<(std::ostream& os, Point const& point) {
		os << "(";
		impl::print_point<Point, Point::dimensions>(os, point);
		os << ")";
		return os;
	}

	namespace impl {
		template <typename Domain, typename T, typename Functor>
		std::ostream& print_image2d(std::ostream& os, Image<Domain, T> image, Functor&& print_char) {
			auto domain  = image.domain();
			size_t width = domain.width(), counter = width;

			for(auto const& point : domain) {
				print_char(os, point, image[point]);

				if(--counter == 0) {
					os << std::endl;
					counter = width;
				}
			}

			return os;
		}
	}

	template <typename T>
	std::ostream& operator<<(std::ostream& os, Image2D<T> image) {
		using Point = typename Image2D<T>::point_type;
		return impl::print_image2d(
		        os, image, [](std::ostream& os, Point /* p */, T value) { os << " " << value; });
	}

	template <>
	std::ostream& operator<<(std::ostream& os, Image2D<bool> image) {
		using Point = typename Image2D<bool>::point_type;
		return impl::print_image2d(os, image, [](std::ostream& os, Point /* p */, bool value) {
			if(value) {
				os << "██";
			} else {
				os << "  ";
			}
		});
		os << std::endl << std::endl << std::endl << std::endl;
	}

	template <typename T, typename U>
	std::ostream& operator<<(std::ostream& os, Image<PartialBox2D<Box2D, T>, U> image) {
		using Point = typename PartialImage2D<bool>::point_type;
		os << "\033[2J";
		impl::print_image2d(os, image, [](std::ostream& os, Point p, T value) {
			os << "\033[" << p.y() + 1 << ";" << (p.x() * 2 + 1) << "H" << value;
		});
		os << std::endl;
		return os;
	}

	template <typename T>
	std::ostream& operator<<(std::ostream& os, Image<PartialBox2D<Box2D, T>, bool> image) {
		using Point = typename PartialImage2D<bool>::point_type;
		os << "\033[2J";
		impl::print_image2d(os, image, [](std::ostream& os, Point p, bool value) {
			os << "\033[" << (p.y() + 1) << ";" << (p.x() * 2 + 1) << "H";
			if(value) {
				os << "██";
			} else {
				os << "░░";
			}
		});
		os << std::endl;
		return os;
	}

}
