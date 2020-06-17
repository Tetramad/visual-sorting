#include <cstdint>

#include "./probius.hh"

auto comb_sort(Probius &probius) -> void;

auto main(void) -> int {
  Probius probius(32, 32);

  comb_sort(probius);

  return 0;
}

auto comb_sort(Probius &probius) -> void {
  std::size_t gap = probius.size();
  double shrink = 1.3;
  bool sorted = false;

  while (!sorted) {
    gap = gap / shrink;
    if (gap <= 1) {
      gap = 1;
      sorted = true;
    }

    for (std::size_t i = 0; i + gap < probius.size(); ++i) {
      if (probius.less(i + gap, i)) {
        probius.swap(i, i + gap);
        sorted = false;
      }
    }
  }
}
