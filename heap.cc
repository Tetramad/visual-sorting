#include <cstdint>

#include "./prober.hh"

auto heap_sort(Prober &prober) -> void;
static auto sift_down(Prober &prober, std::size_t l, std::size_t r) -> void;
static auto heapify(Prober &prober) -> void;
static auto parent_index(std::size_t idx) -> std::size_t;
static auto lchild_index(std::size_t idx) -> std::size_t;
static auto rchild_index(std::size_t idx) -> std::size_t;

auto main(void) -> int {
  Prober prober(10);

  heap_sort(prober);

  return 0;
}

static auto heapify(Prober &prober) -> void {
  std::size_t r = parent_index(prober.size() - 1);

  while (r-- > 0) {
    sift_down(prober, r, prober.size() - 1);
  }
}

static auto sift_down(Prober &prober, std::size_t l, std::size_t r) -> void {
  std::size_t root = l;

  while (lchild_index(root) <= r) {
    std::size_t candi = root;

    if (prober.less(candi, lchild_index(root))) {
      candi = lchild_index(root);
    }
    if (rchild_index(root) <= r && prober.less(candi, rchild_index(root))) {
      candi = rchild_index(root);
    }
    if (candi == root) {
      return;
    } else {
      prober.swap(root, candi);
      root = candi;
    }
  }
}

auto heap_sort(Prober &prober) -> void {
  if (prober.size() < 2) {
    return;
  }

  heapify(prober);

  std::size_t r = prober.size() - 1;
  while (r > 0) {
    prober.swap(r, 0);
    --r;
    sift_down(prober, 0, r);
  }
}

static auto parent_index(std::size_t idx) -> std::size_t {
  return (idx - 1) / 2;
}

static auto lchild_index(std::size_t idx) -> std::size_t { return 2 * idx + 1; }

static auto rchild_index(std::size_t idx) -> std::size_t { return 2 * idx + 2; }
