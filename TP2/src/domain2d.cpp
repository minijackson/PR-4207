#include "domain2d.hpp"

namespace image {

	Domain2D::Domain2D(size_t height, size_t width)
	      : theHeight(height)
	      , theWidth(width) {}

	size_t Domain2D::height() const {
		return theHeight;
	}

	size_t Domain2D::width() const {
		return theWidth;
	}

	auto Domain2D::begin() const -> const_iterator {
		return const_iterator(theHeight, theWidth);
	}

	auto Domain2D::end() const -> const_iterator {
		return const_iterator();
	}

} // namespace image
