#pragma once

#include "point2d.hpp"

#include <iterator>

#include <cstddef>

namespace image {

	class Domain2D;

	class Domain2DIterator {
	public:
		using domain_type = Domain2D;

		using value_type = Point2D;
		using difference_type = size_t;
		using reference = Point2D&;
		using pointer = Point2D*;
		using iterator_category = std::forward_iterator_tag;

		Domain2DIterator(size_t height, size_t width, Point2D value = Point2D{0, 0});
		Domain2DIterator();

		size_t height() const;
		size_t width() const;

		value_type operator*() const;

		Domain2DIterator& operator++(int);
		Domain2DIterator& operator++();

	protected:
		void increment_value();

		size_t theHeight;
		size_t theWidth;
		Point2D value;
		bool end = false;
	};

} // namespace image
