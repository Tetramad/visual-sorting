#include <vector>

#include <cstdint>

#include "./probius.hh"

auto radix_sort(Probius &probius) -> void;
auto key(u16 val, u16 mask) -> std::size_t;

auto main(void) -> int {
  Probius probius;

  radix_sort(probius);

  return 0;
}

auto radix_sort(Probius &probius) -> void {
  std::size_t count[10];
  std::vector<u16> aux(probius.size());

  u16 max = 0;
  for (std::size_t i = 0; i < probius.size(); ++i) {
    u16 const tmp = probius.read(i);
    if (tmp > max) {
      max = tmp;
    }
  }

  for (std::size_t mask = 1; max > 0; mask *= 10, max /= 10) {
    for (std::size_t i = 0; i < 10; ++i) {
      count[i] = 0;
    }

    for (std::size_t i = 0; i < probius.size(); ++i) {
      ++count[key(probius.read(i), mask)];
    }

    std::size_t total = 0;
    for (std::size_t i = 0; i < 10; ++i) {
      std::size_t const tmp = total;
      total += count[i];
      count[i] = tmp;
    }

    for (std::size_t i = 0; i < probius.size(); ++i) {
      u16 const val = probius.read(i);
      aux[count[key(val, mask)]] = val;
      ++count[key(val, mask)];
    }

    for (std::size_t i = 0; i < probius.size(); ++i) {
      probius.write(i, aux[i]);
    }
  }
}

auto key(u16 val, u16 mask) -> std::size_t {
  return static_cast<std::size_t>(val / mask % 10);
}
