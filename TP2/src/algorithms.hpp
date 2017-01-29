#pragma once

#include "concepts.hpp"
#include "image.hpp"
#include "neighbours2d_iterator.hpp"
#include "utils.hpp"

#include <algorithm>
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

				std::find_if(domain.neighbours_begin(point),
				              domain.neighbours_end(),
				              [&domain, &input, &q, &point](auto neighbour) {
					              if(domain.contains(neighbour)) {
						              if(not input[neighbour]) {
							              q.push(point);
							              return true;
						              }
					              }
								  return false;
					          });
			}
		}

		while(not q.empty()) {
			Point2D p = q.front();
			q.pop();

			std::for_each(domain.neighbours_begin(p),
			              domain.neighbours_end(),
			              [&domain, &dmap, max, &p, &q](auto neighbour) {
				              if(domain.contains(neighbour) and dmap[neighbour] == max) {
					              dmap[neighbour] = dmap[p] + 1;
					              q.push(neighbour);
				              }
				          });
		}

		return dmap;
	}

	template <typename MyImage>
	requires(concepts::Image<MyImage>)
	Image<typename MyImage::domain_type, bool> backtrack(MyImage const& distanceMap,
	                                                     typename MyImage::point_type begin,
	                                                     typename MyImage::point_type end) {
		using Point         = typename MyImage::point_type;
		using Domain        = typename MyImage::domain_type;
		using SolutionImage = Image<Domain, bool>;

		auto domain   = distanceMap.domain();
		auto solution = SolutionImage(domain);

		Point current = end;

		while(current != begin) {
			solution[current] = true;

			std::find_if(domain.neighbours_begin(current),
			              domain.neighbours_end(),
			              [&domain, &distanceMap, &current](auto neighbour) {
				              if(domain.contains(neighbour) and
				                 distanceMap[neighbour] == (distanceMap[current] - 1)) {
					              current = neighbour;
					              return true;
				              }
							  return false;
				          });
		}
		solution[current] = true;

		return solution;
	}
}
