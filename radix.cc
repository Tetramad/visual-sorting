#include <vector>

#include <cstdint>

#include "./prober.hh"

auto radix_sort(Prober &prober) -> void;
auto key(u16 val, u16 mask) -> std::size_t;

auto main(void) -> int {
  Prober prober(10);

  radix_sort(prober);

  return 0;
}

auto radix_sort(Prober &prober) -> void {
  std::size_t count[10];
  std::vector<u16> aux(prober.size());

  u16 max = 0;
  for (std::size_t i = 0; i < prober.size(); ++i) {
    u16 const tmp = prober.read(i);
    if (tmp > max) {
      max = tmp;
    }
  }

  for (std::size_t mask = 1; max > 0; mask *= 10, max /= 10) {
    for (std::size_t i = 0; i < 10; ++i) {
      count[i] = 0;
    }

    for (std::size_t i = 0; i < prober.size(); ++i) {
      ++count[key(prober.read(i), mask)];
    }

    std::size_t total = 0;
    for (std::size_t i = 0; i < 10; ++i) {
      std::size_t const tmp = total;
      total += count[i];
      count[i] = tmp;
    }

    for (std::size_t i = 0; i < prober.size(); ++i) {
      u16 const val = prober.read(i);
      aux[count[key(val, mask)]] = val;
      ++count[key(val, mask)];
    }

    for (std::size_t i = 0; i < prober.size(); ++i) {
      prober.write(i, aux[i]);
    }
  }
}

auto key(u16 val, u16 mask) -> std::size_t {
  return static_cast<std::size_t>(val / mask % 10);
}
