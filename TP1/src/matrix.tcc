#pragma once

#include "matrix.hpp"

#include <stdexcept>

namespace tp1 {

	template <typename T, size_t rows, size_t cols>
	T Matrix<T, rows, cols>::operator()(size_t i, size_t j) const {
		return data[(i * rows) + j];
	}

	template <typename T, size_t rows, size_t cols>
	T& Matrix<T, rows, cols>::operator()(size_t i, size_t j) {
		return data[(i * rows) + j];
	}

	template <typename T, size_t rows, size_t cols>
	bool Matrix<T, rows, cols>::operator==(Matrix<T, rows, cols> const& other) const {
		for(size_t i = 0; i < rows * cols; ++i) {
			if(data[i] != other.data[i]) {
				return false;
			}
		}

		return true;
	}



	template <typename T, size_t size>
	T DiagonalMatrix<T, size>::operator()(size_t i, size_t j) const {
		if(i == j) {
			return value;
		} else {
			return 0;
		}
	}

	template <typename T, size_t size>
	T& DiagonalMatrix<T, size>::operator()(size_t i, size_t j) {
		if(i == j) {
			return value;
		} else {
			throw std::invalid_argument("");
		}
	}

}
