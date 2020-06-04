#include <cstdint>

#include "./prober.hh"

auto insertion_sort(Prober &prober) -> void;

auto main(void) -> int {
  Prober prober(32);

  insertion_sort(prober);

  return 0;
}

auto insertion_sort(Prober &prober) -> void {
  for (std::size_t i = 1; i < prober.size(); ++i) {
    for (std::size_t j = i; j > 0 && prober.less(j, j - 1); --j) {
      prober.swap(j, j - 1);
    }
  }
}
