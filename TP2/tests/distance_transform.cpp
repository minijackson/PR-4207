#include "../src/algorithms.hpp"
#include "../src/concepts.hpp"
#include "../src/image.hpp"
#include "../src/utils.hpp"

#include <iostream>
#include <random>

int main() {
	using image::operator<<;

	image::Box2D domain1(3, 3);
	image::Image2D<bool> input1(domain1);

	input1[{1, 1}] = true;

	std::cout << "==============================" << std::endl;
	std::cout << input1;
	std::cout << "==============================" << std::endl;
	std::cout << image::distanceTransform(input1);

	image::Box2D domain2({10, 10}, {20, 20});
	image::Image2D<bool> input2(domain2);

	input2[{12, 12}] = true;
	input2[{17, 12}] = true;

	input2[{11, 16}] = true;
	input2[{12, 17}] = true;
	input2[{13, 17}] = true;
	input2[{14, 17}] = true;
	input2[{15, 17}] = true;
	input2[{16, 17}] = true;
	input2[{17, 17}] = true;
	input2[{18, 16}] = true;

	std::cout << "==============================" << std::endl;
	std::cout << input2;
	std::cout << "==============================" << std::endl;
	std::cout << image::distanceTransform(input2);

	std::random_device r;
	std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
	std::mt19937 gen(seed);
	std::uniform_int_distribution<> dist(0, 5);

	image::Box2D domain3(25, 25);
	image::Image2D<bool> input3(domain3);

	for(auto const& point : domain3) {
		input3[point] = (dist(gen) > 4);
	}

	std::cout << "==============================" << std::endl;
	std::cout << input3;
	std::cout << "==============================" << std::endl;
	std::cout << image::distanceTransform(input3);
}
