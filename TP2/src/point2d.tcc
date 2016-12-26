#pragma once

namespace image {

	constexpr Point2D::Point2D()
	      : theX()
	      , theY() {}

	constexpr Point2D::Point2D(coord_type x, coord_type y)
	      : theX(x)
	      , theY(y) {}

}
