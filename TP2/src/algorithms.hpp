#pragma once

#include "concepts.hpp"
#include "image.hpp"
#include "neighbours2d_iterator.hpp"
#include "utils.hpp"

#include <limits>
#include <queue>

namespace image {

	template <typename DomainType>
	Image<DomainType, size_t> distanceTransform(Image<DomainType, bool> input) {
		auto const& domain = input.domain();
		std::queue<Point2D> q;

		Image<DomainType, size_t> dmap(domain);

		for(auto const& point : domain) {
			dmap[point] = std::numeric_limits<size_t>::max();
		}

		for(auto const& point : domain) {
			if(input[point]) {
				dmap[point] = 0;

				auto it = domain.neighbours_begin(point), end = domain.neighbours_end();
				while(it != end) {
					if(!input[*it]) {
						q.push(point);
						break;
					}

					++it;
				}

			}
		}

		while(q.size() != 0) {
			Point2D p = q.front();
			q.pop();

			auto it = domain.neighbours_begin(p), end = domain.neighbours_end();
			while(it != end) {
				if(dmap[*it] == std::numeric_limits<size_t>::max()) {
					dmap[*it] = dmap[p] + 1;
					q.push(*it);
				}

				++it;
			}
		}

		return dmap;
	}

}
