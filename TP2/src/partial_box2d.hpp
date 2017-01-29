#pragma once

#include "partial_box2d_iterator.hpp"

#include <set>

namespace image {

	template <typename Domain, typename T>
	requires(concepts::Domain<Domain>)
	class Image;

	template <typename Box, typename T>
	requires(concepts::Domain<Box>)
	class PartialBox2D {
	public:
		using point_type          = typename Box::point_type;
		using coord_type          = typename point_type::coord_type;
		using const_iterator      = PartialBox2DIterator<Box, T>;
		using neighbours_iterator = Neighbours2DIterator<PartialBox2D>;
	
		PartialBox2D() = delete;

		PartialBox2D(Image<Box, T> parent);

		coord_type width() const;
		coord_type height() const;

		bool contains(point_type point) const;

		const_iterator begin() const;
		const_iterator end() const;

		neighbours_iterator neighbours_begin(point_type center) const;
		neighbours_iterator neighbours_end() const;

	protected:
		Image<Box, T> parent;
	};

}

#include "partial_box2d.tcc"
