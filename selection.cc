#include <cstdint>

#include "./probius.hh"

auto selection_sort(Probius &probius) -> void;

auto main(void) -> int {
  Probius probius;

  selection_sort(probius);

  return 0;
}

auto selection_sort(Probius &probius) -> void {
  for (std::size_t i = 0; i < probius.size(); ++i) {
    std::size_t mini = i;
    for (std::size_t j = i + 1; j < probius.size(); ++j) {
      if (probius.less(j, mini)) {
        mini = j;
      }
    }
    probius.swap(i, mini);
  }
}
