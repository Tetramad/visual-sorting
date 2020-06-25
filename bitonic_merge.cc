#include <functional>
#include <mutex>
#include <thread>
#include <tuple>

#include <cstdint>

#include "./probius.hh"

auto bitonic_sort(Probius &probius, bool ascending, std::size_t b,
                  std::size_t e, std::size_t &bb, std::size_t &ee) -> void;
auto bitonic_merge(Probius &probius, bool ascending, std::size_t b,
                   std::size_t e, std::size_t &bb, std::size_t &ee) -> void;
auto bitonic_swap(Probius &probius, bool ascending, std::size_t b,
                  std::size_t e) -> void;

std::mutex probius_mutex;

auto main(void) -> int {
  Probius probius;
  std::size_t b;
  std::size_t e;

  bitonic_sort(probius, true, 0, probius.size(), b, e);

  return 0;
}

auto bitonic_sort(Probius &probius, bool ascending, std::size_t b,
                  std::size_t e, std::size_t &bb, std::size_t &ee) -> void {
  if (e <= b + 1) {
    bb = b;
    ee = e;
    return;
  } else {
    std::size_t lb;
    std::size_t le;
    std::size_t rb;
    std::size_t re;
    std::thread tl(bitonic_sort, std::ref(probius), true, b, b + (e - b) / 2,
                   std::ref(lb), std::ref(le));
    std::thread tr(bitonic_sort, std::ref(probius), false, b + (e - b) / 2, e,
                   std::ref(rb), std::ref(re));
    tl.join();
    tr.join();
    bitonic_merge(probius, ascending, lb, re, bb, ee);
    bb = lb;
    ee = re;
  }
}

auto bitonic_merge(Probius &probius, bool ascending, std::size_t b,
                   std::size_t e, std::size_t &bb, std::size_t &ee) -> void {
  if (e <= b + 1) {
    bb = b;
    ee = e;
    return;
  } else {
    bitonic_swap(probius, ascending, b, e);
    std::size_t lb;
    std::size_t le;
    std::size_t rb;
    std::size_t re;
    std::thread tl(bitonic_merge, std::ref(probius), ascending, b,
                   b + (e - b) / 2, std::ref(lb), std::ref(le));
    std::thread tr(bitonic_merge, std::ref(probius), ascending, b + (e - b) / 2,
                   e, std::ref(rb), std::ref(re));
    tl.join();
    tr.join();
    bb = lb;
    ee = re;
  }
}

auto bitonic_swap(Probius &probius, bool ascending, std::size_t b,
                  std::size_t e) -> void {
  std::size_t d = (e - b) / 2;
  for (std::size_t i = 0; i < d; ++i) {
    std::lock_guard<std::mutex> lock(probius_mutex);
    if (probius.less(b + i + d, b + i) == ascending) {
      probius.swap(b + i + d, b + i);
    }
  }
}
