#pragma once

#include "neighbours2d_iterator.hpp"

namespace image {

	template <typename DomainType>
	Neighbours2DIterator<DomainType>::Neighbours2DIterator(domain_type domain, value_type point)
	      : domain(domain)
	      , point(point)
	      , currentDirection(impl::NORTH)
	      , neighbour(point + to_translate_vector(currentDirection))
	      , end(false) {}

	template <typename DomainType>
	bool Neighbours2DIterator<DomainType>::isEnd() const {
		return end;
	}

	template <typename DomainType>
	auto Neighbours2DIterator<DomainType>::operator*() const -> value_type {
		return neighbour;
	}

	template <typename DomainType>
	bool Neighbours2DIterator<DomainType>::operator==(Neighbours2DIterator const& other) const {
		return (end and other.end) or
		       ((end == other.end) and (point == other.point) and (neighbour == other.neighbour));
	}

	template <typename DomainType>
	bool Neighbours2DIterator<DomainType>::operator!=(Neighbours2DIterator const& other) const {
		return not (*this == other);
	}

	template <typename DomainType>
	Neighbours2DIterator<DomainType>& Neighbours2DIterator<DomainType>::operator++() {
		increment_value();
		return *this;
	}

	template <typename DomainType>
	Neighbours2DIterator<DomainType>& Neighbours2DIterator<DomainType>::operator++(int) {
		// decltype(auto) to remove references, const modifier, etc.
		decltype(auto) before = *this;
		increment_value();
		return before;
	}

	template <typename DomainType>
	void Neighbours2DIterator<DomainType>::increment_value() {
		if(end) {
			return;
		}

		do {
			if(currentDirection != impl::SOUTH) {
				currentDirection = static_cast<impl::NeighbourDirection>(currentDirection + 1);
				neighbour        = point + to_translate_vector(currentDirection);
			} else {
				end = true;
				return;
			}
		} while(not domain.contains(neighbour));
	}

	template <typename DomainType>
	auto Neighbours2DIterator<DomainType>::to_translate_vector(impl::NeighbourDirection direction) const
	        -> value_type {
		switch(direction) {
			case impl::NORTH:
				return {0, -1};
			case impl::WEST:
				return {-1, 0};
			case impl::EAST:
				return {1, 0};
			case impl::SOUTH:
				return {0, 1};
		}

		// To silence warning
		return {};
	}

}
