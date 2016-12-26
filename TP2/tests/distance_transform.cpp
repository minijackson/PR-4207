#include "../src/algorithms.hpp"
#include "../src/concepts.hpp"
#include "../src/image.hpp"
#include "../src/utils.hpp"

int main() {
	using image::operator<<;

	image::Box2D domain1(3, 3);
	image::Image2D<bool> input1(domain1);

	input1[{1, 1}] = true;

	std::cout << "==============================" << std::endl;
	std::cout << input1;
	std::cout << "==============================" << std::endl;
	std::cout << image::distanceTransform(input1);

	image::Box2D domain2(10, 10);
	image::Image2D<bool> input2(domain2);

	input2[{2, 2}] = true;
	input2[{7, 2}] = true;

	input2[{1, 6}] = true;
	input2[{2, 7}] = true;
	input2[{3, 7}] = true;
	input2[{4, 7}] = true;
	input2[{5, 7}] = true;
	input2[{6, 7}] = true;
	input2[{7, 7}] = true;
	input2[{8, 6}] = true;

	std::cout << "==============================" << std::endl;
	std::cout << input2;
	std::cout << "==============================" << std::endl;
	std::cout << image::distanceTransform(input2);

}
