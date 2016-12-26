#pragma once

#ifdef __cpp_concepts

#include <iterator>
#include <type_traits>

#include <cstddef>

namespace concepts {

	template <typename T>
	concept bool Point = requires(T t, size_t i) {
		typename T::coord_type;
		{T::dimensions} -> size_t;

		t == t;
		t != t;
		{t + t} -> T;

		// Makes gcc segfault (probably because of infinite recursion with Point2D)
		//requires Point<decltype(t - t)>;

		typename T::difference_type;
		// Makes gcc segfault (again…)
		//requires Point<typename T::difference_type>;
		{t - t} -> typename T::difference_type;

		// Not working…
		//{t.template coord<i>()} -> typename T::coord_type;
	};

	// http://en.cppreference.com/w/cpp/concept/Iterator
	template <typename T>
	concept bool Iterator = std::is_copy_constructible<T>::value &&
	std::is_copy_assignable<T>::value &&
	std::is_destructible<T>::value &&
	//std::is_swappable<T>::value &&
	requires(T t) {
		typename std::iterator_traits<T>::value_type;
		typename std::iterator_traits<T>::difference_type;
		typename std::iterator_traits<T>::reference;
		typename std::iterator_traits<T>::pointer;
		typename std::iterator_traits<T>::iterator_category;

		{*t} -> typename std::iterator_traits<T>::value_type;
		{++t} -> T&;
	};

	template <typename T>
	concept bool DomainIterator = Iterator<T> &&
	requires(T t) {
		typename T::domain_type;
	};

	template <typename T>
	concept bool NeighboursIterator = Iterator<T> &&
	requires(T t) {
		t;
	};

	template <typename T>
	concept bool Domain = requires(T t){
		typename T::point_type;
		typename T::const_iterator;

		requires DomainIterator<typename T::const_iterator>;

		{t.begin()} -> typename T::const_iterator;
		{*(t.begin())} -> typename T::point_type;
		{t.end()} -> typename T::const_iterator;
	} && requires(T t, typename T::point_type point) {
		{t.contains(point)} -> bool;
	};

	template <typename T>
	concept bool Image = requires(T t){
		typename T::value_type;
		typename T::domain_type;
		typename T::point_type;

		{t.domain()} -> typename T::domain_type;
	} && requires(T t, typename T::point_type point) {
		{t[point]} -> typename T::value_type;
	};

}

#else

#	define requires(X)

#endif
