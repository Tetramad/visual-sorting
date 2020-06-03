#include <cstdint>

#include "./prober.hh"

auto selection_sort(Prober &prober) -> void;

auto main(void) -> int {
  Prober prober(10);

  selection_sort(prober);

  return 0;
}

auto selection_sort(Prober &prober) -> void {
  for (std::size_t i = 0; i < prober.size(); ++i) {
    std::size_t mini = i;
    for (std::size_t j = i + 1; j < prober.size(); ++j) {
      if (prober.less(j, mini)) {
        mini = j;
      }
    }
    prober.swap(i, mini);
  }
}
