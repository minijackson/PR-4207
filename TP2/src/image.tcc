#pragma once

#include "image.hpp"

namespace image {

	template <typename DomainType, typename T>
	Image<DomainType, T>::Image(DomainType domain)
	      : domain(domain) {}

	template <typename DomainType, typename T>
	auto Image<DomainType, T>::operator[](point_type const& coord) -> value_type& {
		return points[coord];
	}

	template <typename DomainType, typename T>
	auto Image<DomainType, T>::operator[](point_type const& coord) const
	        -> value_type {
		return points[coord];
	}
}
