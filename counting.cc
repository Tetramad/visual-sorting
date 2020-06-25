#include <climits>
#include <cstdint>

#include "./probius.hh"

auto counting_sort(Probius &probius) -> void;
static auto key(u16 val) -> std::size_t;

auto main(void) -> int {
  Probius probius;

  counting_sort(probius);

  return 0;
}

auto counting_sort(Probius &probius) -> void {
  std::size_t count[USHRT_MAX + 1] = {
      0,
  };

  for (std::size_t i = 0; i < probius.size(); ++i) {
    ++count[key(probius.read(i))];
  }

  std::size_t total = 0;
  for (std::size_t i = 0; i < USHRT_MAX + 1; ++i) {
    std::size_t tmp = total;
    total += count[i];
    count[i] = tmp;
  }

  std::vector<u16> aux(probius.size());
  for (std::size_t i = 0; i < probius.size(); ++i) {
    u16 const val = probius.read(i);
    aux[count[key(val)]] = val;
    ++count[key(val)];
  }

  for (std::size_t i = 0; i < probius.size(); ++i) {
    probius.write(i, aux[i]);
  }
}

static auto key(u16 val) -> std::size_t {
  return static_cast<std::size_t>(val);
}
