#pragma once

#include "point2d.hpp"
#include "box2d_iterator.hpp"

#include <iterator>

namespace image {

	template <typename Domain, typename T>
	requires(concepts::Domain<Domain>)
	class Image;

	template <typename Box, typename T>
	requires(concepts::Domain<Box>)
	class PartialBox2D;

	template <typename Box, typename T>
	requires(concepts::Domain<Box>)
	class PartialBox2DIterator {
	public:
		using domain_type = PartialBox2D<Box, T>;
		using coord_type  = typename Point2D::coord_type;

		using value_type        = Point2D;
		using difference_type   = std::ptrdiff_t;
		using reference         = Point2D&;
		using pointer           = Point2D*;
		using iterator_category = std::forward_iterator_tag;

		PartialBox2DIterator(Image<Box, T> const& image, value_type topLeft, value_type bottomRight, value_type value);
		PartialBox2DIterator(Image<Box, T> const& image);

		value_type topLeft() const;
		value_type bottomRight() const;

		bool isEnd() const;

		value_type operator*() const;

		bool operator==(PartialBox2DIterator const& other) const;
		bool operator!=(PartialBox2DIterator const& other) const;

		PartialBox2DIterator& operator++(int);
		PartialBox2DIterator& operator++();

	protected:
		void increment_value();

		Box2DIterator parentIterator;
		Image<Box, T>  image;
	};

}

#include "partial_box2d_iterator.tcc"
