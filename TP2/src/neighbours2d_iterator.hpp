#pragma once

#include "box2d.hpp"
#include "concepts.hpp"
#include "point2d.hpp"

namespace image {

	namespace impl {
		enum NeighbourDirection {
			      NORTH,
			WEST,        EAST,
			      SOUTH, 
		};

	}

	template <typename DomainType>
	class Neighbours2DIterator {
	public:
		using domain_type = DomainType;

		using value_type        = Point2D;
		using difference_type   = std::ptrdiff_t;
		using reference         = Point2D&;
		using pointer           = Point2D*;
		using iterator_category = std::forward_iterator_tag;

		Neighbours2DIterator() = default;
		Neighbours2DIterator(DomainType domain);
		explicit Neighbours2DIterator(domain_type domain, value_type point);

		bool isEnd() const;

		value_type operator*() const;

		bool operator==(Neighbours2DIterator const& other) const;
		bool operator!=(Neighbours2DIterator const& other) const;

		Neighbours2DIterator& operator++(int);
		Neighbours2DIterator& operator++();

	private:
		void increment_value();
		value_type to_translate_vector(impl::NeighbourDirection direction) const;

		domain_type domain;
		// Not const because it would not be copy-assignable anymore
		value_type /*const*/ point;
		impl::NeighbourDirection currentDirection;
		value_type neighbour;
		bool end = true;
	};

}

#include "neighbours2d_iterator.tcc"
