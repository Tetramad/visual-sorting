#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <random>

#include <cstdint>

#include "./prober.hh"

Prober::Prober(std::size_t n) : vector() {
  vector.resize(n);

  std::iota(std::begin(vector), std::end(vector), static_cast<u16>(0));

  std::shuffle(std::begin(vector), std::end(vector),
               std::minstd_rand{std::random_device{}()});

  std::cout << "Before: ";
  std::copy(std::begin(vector), std::end(vector),
            std::ostream_iterator<u16>(std::cout, " "));
  std::cout << std::endl;
}

Prober::~Prober() {
  std::cout << " After: ";
  std::copy(std::begin(vector), std::end(vector),
            std::ostream_iterator<u16>(std::cout, " "));
  std::cout << std::endl;
}

auto Prober::swap(std::size_t lhs, std::size_t rhs) -> void {
  std::swap(vector[lhs], vector[rhs]);
  for (std::size_t i = 0; i < vector.size(); ++i) {
    std::cout << " ";
    if (i == lhs || i == rhs) {
      std::cout << "\033[32m" << vector[i] << "\033[39m";
    } else {
      std::cout << vector[i];
    }
  }
  std::cout << std::ends;
  std::cin.get();
  std::cout << "\033[1F\033[1G\033[0K" << std::ends;
}

auto Prober::less(std::size_t lhs, std::size_t rhs) const -> bool {
  bool ret = vector[lhs] < vector[rhs];
  for (std::size_t i = 0; i < vector.size(); ++i) {
    std::cout << " ";
    if (i == lhs || i == rhs) {
      std::cout << "\033[4m" << vector[i] << "\033[24m";
    } else {
      std::cout << vector[i];
    }
  }
  std::cout << std::ends;
  std::cin.get();
  std::cout << "\033[1F\033[1G\033[0K" << std::ends;
  return ret;
}

auto Prober::size(void) const -> std::size_t { return vector.size(); }

auto Prober::read(std::size_t idx) const -> u16 {
  for (std::size_t i = 0; i < vector.size(); ++i) {
    std::cout << " ";
    if (i == idx) {
      std::cout << "\033[31m" << vector[i] << "\033[39m";
    } else {
      std::cout << vector[i];
    }
  }
  std::cout << std::ends;
  std::cin.get();
  std::cout << "\033[1F\033[1G\033[0K" << std::ends;
  return vector[idx];
}

auto Prober::write(std::size_t idx, u16 val) -> void {
  vector[idx] = val;
  for (std::size_t i = 0; i < vector.size(); ++i) {
    std::cout << " ";
    if (i == idx) {
      std::cout << "\033[33m" << vector[i] << "\033[39m";
    } else {
      std::cout << vector[i];
    }
  }
  std::cout << std::ends;
  std::cin.get();
  std::cout << "\033[1F\033[1G\033[0K" << std::ends;
}
