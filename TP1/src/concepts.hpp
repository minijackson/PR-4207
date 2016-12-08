#pragma once

namespace concepts {

	template <typename T>
	concept bool SimpleContainer = requires(T t) {
		typename T::value_type;
	};

	template <typename T>
	concept bool Vector = SimpleContainer<T> &&
	requires {
		{T::size} -> size_t;
	} &&
	requires(T t, size_t i) {
		{t[i]} -> typename T::value_type;
	};

	template <typename T>
	concept bool Matrix = SimpleContainer<T> &&
	requires {
		{T::nrows} -> size_t;
		{T::ncols} -> size_t;
	} &&
	requires(T t, size_t i, size_t j) {
		{t(i, j)} -> typename T::value_type;
	};

	template <typename Mat, typename Vec>
	requires Matrix<Mat> && Vector<Vec>
	concept bool Multiplicable = (Mat::ncols == Vec::size);

	//
	// Makes g++ segfault
	//
	//template <typename T, typename V>
	//concept bool Multiplicable = requires(T t, V v) {
		//t * v;
	//};

}
