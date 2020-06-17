#include <algorithm>
#include <cstdint>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

#include "./probius.hh"
#include "./terminal.hh"

Probius::Probius(std::size_t width, std::size_t height)
    : width(width), height(height), vector() {

  vector.resize([width]() -> std::size_t {
    auto w = width;
    auto count = 0;
    while (w > 1) {
      w >>= 1;
      ++count;
    }
    return 1 << count;
  }());

  std::iota(vector.begin(), vector.end(), static_cast<u16>(1));

  std::shuffle(std::begin(vector), std::end(vector),
               std::minstd_rand(std::random_device{}()));

	std::cout << screen::clear;
  display();
}

Probius::~Probius() {
	display();
}

auto Probius::display(char const *c,
                      std::initializer_list<std::size_t> lst) const -> void {
  std::cout << cursor::origin;

  std::vector<bool> hit(vector.size());

  for (std::size_t h = 0; h < height; ++h) {
    for (std::size_t i = 0; i < vector.size(); ++i) {
      if (height - h <= vector[i]) {
        if (std::find(lst.begin(), lst.end(), i) != lst.end()) {
          std::cout << c;
        } else {
          std::cout << background::white;
        }
        if (hit[i] == false) {
          hit[i] = true;
          std::cout << std::setw(2) << vector[i] % 100;
        } else {
          std::cout << "  ";
        }
        std::cout << background::clear;
      } else {
        std::cout << "  ";
      }
    }
    std::cout << "\n";
  }
  std::cin.get();
}

auto Probius::swap(std::size_t lhs, std::size_t rhs) -> void {
  std::swap(vector[lhs], vector[rhs]);
  display(background::green, {lhs, rhs});
}

auto Probius::less(std::size_t lhs, std::size_t rhs) const -> bool {
  bool ret = vector[lhs] < vector[rhs];
  display(background::yellow, {lhs, rhs});
  return ret;
}

auto Probius::size(void) const -> std::size_t { return vector.size(); }

auto Probius::read(std::size_t idx) const -> u16 {
  u16 ret = vector[idx];
  display(background::blue, {idx});
  return ret;
}

auto Probius::write(std::size_t idx, u16 val) -> void {
  vector[idx] = val;
  display(background::red, {idx});
}
