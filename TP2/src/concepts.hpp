#pragma once

#ifdef __cpp_concepts

#include <cstddef>

namespace concepts {

	template <typename T>
	concept bool Point = requires(T t, size_t i){
		typename T::coord_type;
		{T::dimensions} -> size_t;

		// Not working…
		//{t.template coord<i>()} -> typename T::coord_type;
	};

	//template <typename T>
	//concept bool Domain = requires(T t){
	//};

	//template <typename T>
	//concept bool DomainIterator = requires(T t){
	//};

	//template <typename T>
	//concept bool Image = requires(T t){
	//};

	//template <typename T>
	//concept bool NeighboursIterator = requires(T t){
	//};

}

#else

#	define requires(X)

#endif
