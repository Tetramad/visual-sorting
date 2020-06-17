#include <cstdint>

#include "./probius.hh"

auto bubble_sort(Probius &probius) -> void;

auto main(void) -> int {
  Probius probius(32, 32);

  bubble_sort(probius);

  return 0;
}

auto bubble_sort(Probius &probius) -> void {
  bool sorted = false;

  while (!sorted) {
    sorted = true;

    for (std::size_t i = 1; i < probius.size(); ++i) {
      if (probius.less(i, i - 1)) {
        probius.swap(i - 1, i);
        sorted = false;
      }
    }
  }
}
