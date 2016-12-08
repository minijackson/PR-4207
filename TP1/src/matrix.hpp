#pragma once

#include <cstddef>

namespace tp1 {

	template <typename T, size_t rows, size_t cols>
	class Matrix {
	public:
		using value_type = T;

		static constexpr size_t const nrows = rows;
		static constexpr size_t const ncols = cols;

		Matrix() = default;

		value_type operator()(size_t i, size_t j) const;
		value_type& operator()(size_t i, size_t j);

		bool operator==(Matrix<value_type, rows, cols> const& other) const;
	protected:
		T data[rows * cols];
	};

	template <typename T, size_t size>
	class DiagonalMatrix {
	public:
		using value_type = T;

		static constexpr size_t const nrows = size;
		static constexpr size_t const ncols = size;

		DiagonalMatrix() = default;

		value_type operator()(size_t i, size_t j) const;
		value_type& operator()(size_t i, size_t j);

		bool operator==(DiagonalMatrix<value_type, size> const& other) const;
	protected:
		T value;
	};
}

#include "matrix.tcc"
