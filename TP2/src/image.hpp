#pragma once

#include "concepts.hpp"
#include "box2d.hpp"

#include <map>

namespace image {

	template <typename DomainType, typename T>
	requires(concepts::Domain<DomainType>)
	class Image {
	public:
		using value_type  = T;
		using domain_type = DomainType;
		using point_type  = typename domain_type::point_type;

		Image() = delete;

		explicit Image(DomainType domain);

		value_type& operator[](point_type const& coord);
		value_type operator[](point_type const& coord) const;

	private:
		DomainType domain;
		std::map<point_type, value_type> points;
	};

	template <typename T>
	using Image2D = Image<Box2D, T>;

}

#include "image.tcc"
