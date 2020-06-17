#include <cstdint>

#include "./probius.hh"

auto quick_sort(Probius &probius, std::size_t b, std::size_t e) -> void;

auto main(void) -> int {
  Probius probius(32, 32);

  quick_sort(probius, 0, probius.size());

  return 0;
}

auto quick_sort(Probius &probius, std::size_t b, std::size_t e) -> void {
  if (e - b < 2) {
    return;
  }
  std::size_t p = b;
  std::size_t l = b + 1;
  std::size_t r = e - 1;

  while (l <= r) {
    if (probius.less(l, p)) {
      ++l;
    } else {
      probius.swap(l, r);
      --r;
    }
  }
  probius.swap(r, p);
  quick_sort(probius, b, l);
  quick_sort(probius, l, e);
}
