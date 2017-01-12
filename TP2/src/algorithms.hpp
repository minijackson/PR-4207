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

		Image<DomainType, size_t> dmap(domain);
		size_t max = std::numeric_limits<size_t>::max();

		for(auto const& point : domain) {
			dmap[point] = max;
		}

		std::queue<Point2D> q;

		for(auto const& point : domain) {
			if(input[point]) {
				dmap[point] = 0;

				for(auto it = domain.neighbours_begin(point), end = domain.neighbours_end();
				    it != end;
				    ++it) {

					auto neighbour = *it;

					if(domain.contains(neighbour)) {
						if(not input[neighbour]) {
							q.push(point);
							break;
						}
					}

				}
			}
		}

		while(not q.empty()) {
			Point2D p = q.front();
			q.pop();

			for(auto it = domain.neighbours_begin(p), end = domain.neighbours_end(); it != end;
			    ++it) {
				auto neighbour = *it;

				if(domain.contains(neighbour) and dmap[neighbour] == max) {
					dmap[neighbour] = dmap[p] + 1;
					q.push(neighbour);
				}
			}
		}

		return dmap;
	}

}
