#pragma once

#include "image.hpp"

#include <iostream>

namespace image {

	template <typename DomainType, typename T>
	Image<DomainType, T>::Image(DomainType theDomain)
	      : theDomain(theDomain) {}

	template <typename DomainType, typename T>
	auto Image<DomainType, T>::operator[](point_type const& coord) -> value_type& {
#ifndef NDEBUG
		if(not theDomain.contains(coord)) {
			std::cerr << "Accessing out of domain point in image: " << coord << std::endl;
			std::exit(-1);
		}
#endif

		return points[coord];
	}

	template <typename DomainType, typename T>
	auto Image<DomainType, T>::operator[](point_type const& coord) const
	        -> value_type {
#ifndef NDEBUG
		if(not theDomain.contains(coord)) {
			std::cerr << "Accessing out of domain point in image: " << coord << std::endl;
			std::exit(-1);
		}
#endif

		return points[coord];
	}

	template <typename DomainType, typename T>
	DomainType Image<DomainType, T>::domain() const {
		return theDomain;
	}

}
