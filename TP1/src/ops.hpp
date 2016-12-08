#pragma once

#include "concepts.hpp"

namespace tp1 {

	template <typename Mat, typename Vec>
	requires concepts::Multiplicable<Mat, Vec>
	Vec operator*(Mat const& mat, Vec const& vec) {
		constexpr size_t const rows = Mat::nrows;
		constexpr size_t const cols = Mat::ncols;

		Vec res{};

		for(size_t i = 0; i < rows; ++i) {
			unsigned acc = 0;

			for(size_t j = 0; j < cols; ++j) {
				acc += mat(i, j) * vec[j];
			}

			res[i] = acc;
		}

		return res;
	}


	template <typename Vec>
	requires concepts::Vector<Vec>
	void fill(Vec& vec, typename Vec::value_type value) {
		constexpr size_t const size = Vec::size;

		for(size_t i = 0; i < size; ++i) {
			vec[i] = value;
		}
	}

	template <typename Mat>
	requires concepts::Matrix<Mat>
	void fill(Mat& matrix, typename Mat::value_type value) {
		constexpr size_t const rows = Mat::nrows;
		constexpr size_t const cols = Mat::ncols;

		for(size_t i = 0; i < rows; ++i) {
			for(size_t j = 0; j < cols; ++j) {
				matrix(i, j) = value;
			}
		}
	}
}
