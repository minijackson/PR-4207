#pragma once

#include "concepts.hpp"
#include "box2d.hpp"
#include "partial_box2d.hpp"

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

		explicit Image(domain_type domain);

		template <typename OtherImage>
		requires(concepts::Image<OtherImage>)
		explicit Image(OtherImage const& image);

		template <typename OtherImage>
		requires(concepts::Image<OtherImage>)
		explicit Image(domain_type domain, OtherImage const& image);

		value_type& operator[](point_type const& coord);
		value_type operator[](point_type const& coord) const;

		domain_type domain() const;

	private:
		DomainType theDomain;
		std::map<point_type, value_type> points;
	};

	template <typename T>
	using Image2D = Image<Box2D, T>;

	template <typename Box, typename T>
	requires(concepts::Domain<Box>)
	class PartialBox2D;

	template <typename T>
	using PartialImage2D = Image<PartialBox2D<Box2D, T>, T>;

}

#include "image.tcc"
