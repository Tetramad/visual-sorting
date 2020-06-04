#include <cstdint>

#include "./prober.hh"

auto shell_sort(Prober &prober) -> void;

auto main(void) -> int {
  Prober prober(32);

  shell_sort(prober);

  return 0;
}

auto shell_sort(Prober &prober) -> void {
  for (std::size_t gap = prober.size() >> 1; gap > 0; gap >>= 1) {
    for (std::size_t i = gap; i < prober.size(); ++i) {
      for (std::size_t j = i; j >= gap && prober.less(j, j - gap); j -= gap) {
        prober.swap(j, j - gap);
      }
    }
  }
}
