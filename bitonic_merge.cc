#include <tuple>

#include <cstdint>

#include "./prober.hh"

auto bitonic_sort(Prober &prober, bool ascending, std::size_t b, std::size_t e)
    -> std::tuple<std::size_t, std::size_t>;
auto bitonic_merge(Prober &prober, bool ascending, std::size_t b, std::size_t e)
    -> std::tuple<std::size_t, std::size_t>;
auto bitonic_swap(Prober &prober, bool ascending, std::size_t b, std::size_t e)
    -> void;

auto main(void) -> int {
  Prober prober(32);

  bitonic_sort(prober, true, 0, prober.size());

  return 0;
}

auto bitonic_sort(Prober &prober, bool ascending, std::size_t b, std::size_t e)
    -> std::tuple<std::size_t, std::size_t> {
  if (e <= b + 1) {
    return {b, e};
  } else {
    auto [lb, le] = bitonic_sort(prober, true, b, b + (e - b) / 2);
    auto [rb, re] = bitonic_sort(prober, false, b + (e - b) / 2, e);
    return bitonic_merge(prober, ascending, lb, re);
  }
}

auto bitonic_merge(Prober &prober, bool ascending, std::size_t b, std::size_t e)
    -> std::tuple<std::size_t, std::size_t> {
  if (e <= b + 1) {
    return {b, e};
  } else {
    bitonic_swap(prober, ascending, b, e);
    auto [lb, le] = bitonic_merge(prober, ascending, b, b + (e - b) / 2);
    auto [rb, re] = bitonic_merge(prober, ascending, b + (e - b) / 2, e);
    return {lb, re};
  }
}

auto bitonic_swap(Prober &prober, bool ascending, std::size_t b, std::size_t e)
    -> void {
  std::size_t d = (e - b) / 2;
  for (std::size_t i = 0; i < d; ++i) {
    if (prober.less(b + i + d, b + i) == ascending) {
      prober.swap(b + i + d, b + i);
    }
  }
}
