#pragma once

#include "image.hpp"

namespace image {

	template <typename DomainType, typename T>
	Image<DomainType, T>::Image(DomainType theDomain)
	      : theDomain(theDomain) {}

	template <typename DomainType, typename T>
	auto Image<DomainType, T>::operator[](point_type const& coord) -> value_type& {
#ifndef NDEBUG
		if(not theDomain.contains(coord)) {
			throw std::runtime_error("Accessing out of domain point in image");
		}
#endif

		return points[coord];
	}

	template <typename DomainType, typename T>
	auto Image<DomainType, T>::operator[](point_type const& coord) const
	        -> value_type {
#ifndef NDEBUG
		if(not theDomain.contains(coord)) {
			throw std::runtime_error("Accessing out of domain point in image");
		}
#endif

		if(points.count(coord)) {
			return points.at(coord);
		} else {
			return T();
		}
	}

	template <typename DomainType, typename T>
	DomainType Image<DomainType, T>::domain() const {
		return theDomain;
	}

}
