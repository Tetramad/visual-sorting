#include <cstdint>

#include "./prober.hh"

auto bubble_sort(Prober &prober) -> void;

auto main(void) -> int {
  Prober prober(10);

  bubble_sort(prober);

  return 0;
}

auto bubble_sort(Prober &prober) -> void {
  for (;;) {
    bool sorted = true;

    for (std::size_t i = 1; i < prober.size(); ++i) {
      if (prober.less(i, i - 1)) {
        prober.swap(i - 1, i);
        sorted = false;
      }
    }

    if (sorted) {
      break;
    }
  }
}
