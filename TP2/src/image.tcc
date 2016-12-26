#pragma once

#include <iostream>

#include "image.hpp"

namespace image {

	template <typename DomainType, typename T>
	Image<DomainType, T>::Image(DomainType theDomain)
	      : theDomain(theDomain) {}

	template <typename DomainType, typename T>
	auto Image<DomainType, T>::operator[](point_type const& coord) -> value_type& {
		return points[coord];
	}

	template <typename DomainType, typename T>
	auto Image<DomainType, T>::operator[](point_type const& coord) const
	        -> value_type {
		return points[coord];
	}

	template <typename DomainType, typename T>
	DomainType Image<DomainType, T>::domain() const {
		return theDomain;
	}

}
