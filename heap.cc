#include <cstdint>

#include "./probius.hh"

auto heap_sort(Probius &probius) -> void;
static auto sift_down(Probius &probius, std::size_t l, std::size_t r) -> void;
static auto heapify(Probius &probius) -> void;
static auto parent_index(std::size_t idx) -> std::size_t;
static auto lchild_index(std::size_t idx) -> std::size_t;
static auto rchild_index(std::size_t idx) -> std::size_t;

auto main(void) -> int {
  Probius probius(32, 32);

  heap_sort(probius);

  return 0;
}

static auto heapify(Probius &probius) -> void {
  std::size_t r = parent_index(probius.size() - 1);

  while (r-- > 0) {
    sift_down(probius, r, probius.size() - 1);
  }
}

static auto sift_down(Probius &probius, std::size_t l, std::size_t r) -> void {
  std::size_t root = l;

  while (lchild_index(root) <= r) {
    std::size_t candi = root;

    if (probius.less(candi, lchild_index(root))) {
      candi = lchild_index(root);
    }
    if (rchild_index(root) <= r && probius.less(candi, rchild_index(root))) {
      candi = rchild_index(root);
    }
    if (candi == root) {
      return;
    } else {
      probius.swap(root, candi);
      root = candi;
    }
  }
}

auto heap_sort(Probius &probius) -> void {
  if (probius.size() < 2) {
    return;
  }

  heapify(probius);

  std::size_t r = probius.size() - 1;
  while (r > 0) {
    probius.swap(r, 0);
    --r;
    sift_down(probius, 0, r);
  }
}

static auto parent_index(std::size_t idx) -> std::size_t {
  return (idx - 1) / 2;
}

static auto lchild_index(std::size_t idx) -> std::size_t { return 2 * idx + 1; }

static auto rchild_index(std::size_t idx) -> std::size_t { return 2 * idx + 2; }
