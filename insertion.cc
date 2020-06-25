#include <cstdint>

#include "./probius.hh"

auto insertion_sort(Probius &probius) -> void;

auto main(void) -> int {
  Probius probius;

  insertion_sort(probius);

  return 0;
}

auto insertion_sort(Probius &probius) -> void {
  for (std::size_t i = 1; i < probius.size(); ++i) {
    for (std::size_t j = i; j > 0 && probius.less(j, j - 1); --j) {
      probius.swap(j, j - 1);
    }
  }
}
