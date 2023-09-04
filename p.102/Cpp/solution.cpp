#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <optional>
#include <sstream>
#include <string>

using Point = std::array<double, 2>;
using Triangle = std::array<Point, 3>;

std::optional<Triangle> parse_line(const std::string &&line) {
  Triangle triangle;
  char comma;
  std::istringstream iss(line);
  if (!(iss >> triangle[0][0] >> comma >> triangle[0][1] >> comma >>
        triangle[1][0] >> comma >> triangle[1][1] >> comma >> triangle[2][0] >>
        comma >> triangle[2][1])) {
    return {};
  }
  return triangle;
}

double triangle_area(const Triangle &triangle) {
  auto [p1, p2, p3] = triangle;
  return 0.5 * std::abs(p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) +
                        p3[0] * (p1[1] - p2[1]));
}

bool origin_in_triangle(const Triangle &triangle) {
  auto total_area = triangle_area(triangle);
  Triangle t1 = {{{0, 0}, triangle[1], triangle[2]}};
  Triangle t2 = {{{0, 0}, triangle[0], triangle[2]}};
  Triangle t3 = {{{0, 0}, triangle[0], triangle[1]}};
  return total_area ==
         triangle_area(t1) + triangle_area(t2) + triangle_area(t3);
}

int main() {
  std::ifstream file("../0102_triangles.txt");
  if (!file) {
    std::cerr << "Could not open file triangles\n";
    return 1;
  }

  std::string line;
  int count = 0;
  while (std::getline(file, line)) {
    auto triangle = parse_line(std::move(line));
    if (triangle && origin_in_triangle(triangle.value())) {
      ++count;
    }
  }
  std::cout << count << std::endl;
  return 0;
}
