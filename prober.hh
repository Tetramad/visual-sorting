#pragma once

#include <vector>

#include <cstdint>

using u16 = short int;

class Prober {
public:
  explicit Prober(std::size_t n);
  ~Prober();
  Prober(Prober const &other) = delete;
  Prober(Prober &&other) noexcept = delete;
  auto operator=(Prober const &other) -> Prober & = delete;
  auto operator=(Prober &&other) noexcept -> Prober & = delete;

  auto swap(std::size_t lhs, std::size_t rhs) -> void;
  auto less(std::size_t lhs, std::size_t rhs) -> bool;
  auto size(void) const -> std::size_t;

private:
  std::vector<u16> vector;
};
