#pragma once

#include <vector>

#include <cstdint>

using u16 = unsigned short int;

class Prober {
public:
  explicit Prober(std::size_t n);
  ~Prober();
  Prober(Prober const &other) = delete;
  Prober(Prober &&other) noexcept = delete;
  auto operator=(Prober const &other) -> Prober & = delete;
  auto operator=(Prober &&other) noexcept -> Prober & = delete;

  auto swap(std::size_t lhs, std::size_t rhs) -> void;
  auto less(std::size_t lhs, std::size_t rhs) const -> bool;
  auto size(void) const -> std::size_t;
  auto read(std::size_t idx) const -> u16;
  auto write(std::size_t idx, u16 val) -> void;

private:
  std::vector<u16> vector;
};
