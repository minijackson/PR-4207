#pragma once

#include "partial_box2d.hpp"

namespace image {

	template <typename Box, typename T>
	PartialBox2D<Box, T>::PartialBox2D(Image<Box, T> parent)
	      : parent(parent) {}

	template <typename Box, typename T>
	auto PartialBox2D<Box, T>::width() const -> coord_type {
		return parent.domain().width();
	}

	template <typename Box, typename T>
	auto PartialBox2D<Box, T>::height() const -> coord_type {
		return parent.domain().height();
	}

	template <typename Box, typename T>
	bool PartialBox2D<Box, T>::contains(point_type point) const {
		return parent.domain().contains(point) and (parent[point] != 0);
	}

	template <typename Box, typename T>
	auto PartialBox2D<Box, T>::begin() const -> const_iterator {
		auto domain = parent.domain();
		return const_iterator(parent, domain.topLeft(), domain.bottomRight(), domain.topLeft());
	}

	template <typename Box, typename T>
	auto PartialBox2D<Box, T>::end() const -> const_iterator {
		return const_iterator(parent);
	}

	template <typename Box, typename T>
	auto PartialBox2D<Box, T>::neighbours_begin(point_type center) const -> neighbours_iterator {
		return neighbours_iterator(*this, center);
	}

	template <typename Box, typename T>
	auto PartialBox2D<Box, T>::neighbours_end() const -> neighbours_iterator {
		return neighbours_iterator(*this);
	}

}
