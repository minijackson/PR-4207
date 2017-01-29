#include "../src/algorithms.hpp"
#include "../src/concepts.hpp"
#include "../src/image.hpp"
#include "../src/utils.hpp"

#include <algorithm>
#include <iostream>
#include <random>

int main() {
	using image::operator<<;

	// 1 0 0 0
	//       0
	//   0 0 0
	//   0   0
	// 0 0
	//   0 0 0 0
	image::Box2D domain(5, 6);
	image::Image2D<size_t> input(domain);

	input[{0, 0}] = 2;
	input[{1, 0}] = 1;
	input[{2, 0}] = 1;
	input[{3, 0}] = 1;

	input[{3, 1}] = 1;

	input[{1, 2}] = 1;
	input[{2, 2}] = 1;
	input[{3, 2}] = 1;

	input[{1, 3}] = 1;
	input[{3, 3}] = 1;

	input[{0, 4}] = 1;
	input[{1, 4}] = 1;

	input[{1, 5}] = 1;
	input[{2, 5}] = 1;
	input[{3, 5}] = 1;
	input[{4, 5}] = 3;

	auto partialInput = image::PartialImage2D<size_t>(input);

	for(auto point : partialInput.domain()) {
		if(partialInput[point] == 2) {
			partialInput[point] = 1;
		} else {
			partialInput[point] = 0;
		}
	}

	auto boolPartialInput = image::Image<image::PartialBox2D<image::Box2D, size_t>, bool>(
	        partialInput.domain(), partialInput);

	std::cout << boolPartialInput;

	std::cout << "==============================" << std::endl;

	auto distanceMap = image::distanceTransform(boolPartialInput);

	std::cout << distanceMap;

	std::cout << "==============================" << std::endl;

	image::Point2D begin = *std::find_if(
	        input.domain().begin(), input.domain().end(), [input](image::Point2D point) {
		        return input[point] == 2;
		    });

	image::Point2D end = *std::find_if(input.domain().begin(),
	                                   input.domain().end(),
	                                   [input](image::Point2D point) { return input[point] == 3; });

	auto solution = image::backtrack(distanceMap, begin, end);

	std::cout << solution;
}
