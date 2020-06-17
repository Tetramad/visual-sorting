#include <tuple>

#include <cstdint>

#include "./probius.hh"

auto bitonic_sort(Probius &probius, bool ascending, std::size_t b, std::size_t e)
    -> std::tuple<std::size_t, std::size_t>;
auto bitonic_merge(Probius &probius, bool ascending, std::size_t b, std::size_t e)
    -> std::tuple<std::size_t, std::size_t>;
auto bitonic_swap(Probius &probius, bool ascending, std::size_t b, std::size_t e)
    -> void;

auto main(void) -> int {
  Probius probius(32, 32);

  bitonic_sort(probius, true, 0, probius.size());

  return 0;
}

auto bitonic_sort(Probius &probius, bool ascending, std::size_t b, std::size_t e)
    -> std::tuple<std::size_t, std::size_t> {
  if (e <= b + 1) {
    return {b, e};
  } else {
    auto [lb, le] = bitonic_sort(probius, true, b, b + (e - b) / 2);
    auto [rb, re] = bitonic_sort(probius, false, b + (e - b) / 2, e);
    return bitonic_merge(probius, ascending, lb, re);
  }
}

auto bitonic_merge(Probius &probius, bool ascending, std::size_t b, std::size_t e)
    -> std::tuple<std::size_t, std::size_t> {
  if (e <= b + 1) {
    return {b, e};
  } else {
    bitonic_swap(probius, ascending, b, e);
    auto [lb, le] = bitonic_merge(probius, ascending, b, b + (e - b) / 2);
    auto [rb, re] = bitonic_merge(probius, ascending, b + (e - b) / 2, e);
    return {lb, re};
  }
}

auto bitonic_swap(Probius &probius, bool ascending, std::size_t b, std::size_t e)
    -> void {
  std::size_t d = (e - b) / 2;
  for (std::size_t i = 0; i < d; ++i) {
    if (probius.less(b + i + d, b + i) == ascending) {
      probius.swap(b + i + d, b + i);
    }
  }
}
