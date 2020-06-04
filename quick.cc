#include <cstdint>

#include "./prober.hh"

auto quick_sort(Prober &prober, std::size_t b, std::size_t e) -> void;

auto main(void) -> int {
  Prober prober(32);

  quick_sort(prober, 0, prober.size());

  return 0;
}

auto quick_sort(Prober &prober, std::size_t b, std::size_t e) -> void {
  if (e - b < 2) {
    return;
  }
  std::size_t p = b;
  std::size_t l = b + 1;
  std::size_t r = e - 1;

  while (l <= r) {
    if (prober.less(l, p)) {
      ++l;
    } else {
      prober.swap(l, r);
      --r;
    }
  }
  prober.swap(r, p);
  quick_sort(prober, b, l);
  quick_sort(prober, l, e);
}
