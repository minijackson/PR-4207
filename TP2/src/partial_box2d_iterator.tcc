#pragma once

#include "partial_box2d_iterator.hpp"

namespace image {

	template <typename Box, typename T>
	PartialBox2DIterator<Box, T>::PartialBox2DIterator(Image<Box, T> const& image,
	                                                     value_type topLeft,
	                                                     value_type bottomRight,
	                                                     value_type value)
	      : parentIterator(topLeft, bottomRight, value)
	      , image(image) {
		if(not isEnd() and image[*parentIterator] == 0) {
			increment_value();
		}
	}

	template <typename Box, typename T>
	PartialBox2DIterator<Box, T>::PartialBox2DIterator(Image<Box, T> const& image)
	      : parentIterator(), image(image) {}

	template <typename Box, typename T>
	auto PartialBox2DIterator<Box, T>::topLeft() const -> value_type {
		return parentIterator.topLeft();
	}

	template <typename Box, typename T>
	auto PartialBox2DIterator<Box, T>::bottomRight() const -> value_type {
		return parentIterator.bottomRight();
	}

	template <typename Box, typename T>
	bool PartialBox2DIterator<Box, T>::isEnd() const {
		return parentIterator.isEnd();
	}

	template <typename Box, typename T>
	auto PartialBox2DIterator<Box, T>::operator*() const -> value_type {
		return *parentIterator;
	}

	template <typename Box, typename T>
	bool PartialBox2DIterator<Box, T>::operator==(PartialBox2DIterator<Box, T> const& other) const {
		return this->parentIterator == other.parentIterator;
	}

	template <typename Box, typename T>
	bool PartialBox2DIterator<Box, T>::operator!=(PartialBox2DIterator<Box, T> const& other) const {
		return this->parentIterator != other.parentIterator;
	}

	template <typename Box, typename T>
	PartialBox2DIterator<Box, T>& PartialBox2DIterator<Box, T>::operator++() {
		increment_value();
		return *this;
	}

	template <typename Box, typename T>
	PartialBox2DIterator<Box, T>& PartialBox2DIterator<Box, T>::operator++(int) {
		// decltype(auto) to remove references, const modifier, etc.
		decltype(auto) before = *this;
		increment_value();
		return before;
	}

	template <typename Box, typename T>
	void PartialBox2DIterator<Box, T>::increment_value() {
		do {
			++parentIterator;
		} while(not isEnd() and image[*parentIterator] == 0);
	}

}
