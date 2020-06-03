#include <climits>
#include <cstdint>

#include "./prober.hh"

auto counting_sort(Prober &prober) -> void;
static auto key(u16 val) -> std::size_t;

auto main(void) -> int {
  Prober prober(10);

  counting_sort(prober);

  return 0;
}

auto counting_sort(Prober &prober) -> void {
  std::size_t count[USHRT_MAX + 1] = {
      0,
  };

  for (std::size_t i = 0; i < prober.size(); ++i) {
    ++count[key(prober.read(i))];
  }

  std::size_t total = 0;
  for (std::size_t i = 0; i < USHRT_MAX + 1; ++i) {
    std::size_t tmp = total;
    total += count[i];
    count[i] = tmp;
  }

  std::vector<u16> aux(prober.size());
  for (std::size_t i = 0; i < prober.size(); ++i) {
    u16 const val = prober.read(i);
    aux[count[key(val)]] = val;
    ++count[key(val)];
  }

  for (std::size_t i = 0; i < prober.size(); ++i) {
    prober.write(i, aux[i]);
  }
}

static auto key(u16 val) -> std::size_t {
  return static_cast<std::size_t>(val);
}
