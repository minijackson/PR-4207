#pragma once

#include <cstddef>

namespace tp1 {

	template <typename T, size_t vec_size>
	class Vector {
	public:
		using value_type = T;

		static constexpr size_t const size = vec_size;

		Vector() = default;

		value_type operator[](size_t index) const;
		value_type& operator[](size_t index);

		bool operator==(Vector<T, size> const& other) const;

	protected:
		value_type data[size];
	};
}

#include "vector.tcc"
