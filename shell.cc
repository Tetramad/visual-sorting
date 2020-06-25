#include <cstdint>

#include "./probius.hh"

auto shell_sort(Probius &probius) -> void;

auto main(void) -> int {
  Probius probius;

  shell_sort(probius);

  return 0;
}

auto shell_sort(Probius &probius) -> void {
  for (std::size_t gap = probius.size() >> 1; gap > 0; gap >>= 1) {
    for (std::size_t i = gap; i < probius.size(); ++i) {
      for (std::size_t j = i; j >= gap && probius.less(j, j - gap); j -= gap) {
        probius.swap(j, j - gap);
      }
    }
  }
}
