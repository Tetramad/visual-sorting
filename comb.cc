#include <cstdint>

#include "./prober.hh"

auto comb_sort(Prober &prober) -> void;

auto main(void) -> int {
  Prober prober(32);

  comb_sort(prober);

  return 0;
}

auto comb_sort(Prober &prober) -> void {
  std::size_t gap = prober.size();
  double shrink = 1.3;
  bool sorted = false;

  while (!sorted) {
    gap = gap / shrink;
    if (gap <= 1) {
      gap = 1;
      sorted = true;
    }

    for (std::size_t i = 0; i + gap < prober.size(); ++i) {
      if (prober.less(i + gap, i)) {
        prober.swap(i, i + gap);
        sorted = false;
      }
    }
  }
}
