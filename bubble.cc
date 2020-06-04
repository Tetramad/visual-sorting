#include <cstdint>

#include "./prober.hh"

auto bubble_sort(Prober &prober) -> void;

auto main(void) -> int {
  Prober prober(32);

  bubble_sort(prober);

  return 0;
}

auto bubble_sort(Prober &prober) -> void {
  bool sorted = false;

  while (!sorted) {
    sorted = true;

    for (std::size_t i = 1; i < prober.size(); ++i) {
      if (prober.less(i, i - 1)) {
        prober.swap(i - 1, i);
        sorted = false;
      }
    }
  }
}
