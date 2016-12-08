#pragma once

#include "vector.hpp"

namespace tp1 {

	template <typename T, size_t size>
	T Vector<T, size>::operator[](size_t index) const {
		return data[index];
	}

	template <typename T, size_t size>
	T& Vector<T, size>::operator[](size_t index) {
		return data[index];
	}

	template <typename T, size_t size>
	bool Vector<T, size>::operator==(Vector<T, size> const& other) const {
		for(size_t i = 0; i < size; ++i) {
			if(data[i] != other.data[i]) {
				return false;
			}
		}

		return true;
	}

}
