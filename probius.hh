#pragma once

#include <cstdint>
#include <initializer_list>
#include <vector>

#include "./terminal.hh"

using u16 = unsigned short int;

class Probius {
public:
  explicit Probius(std::size_t width, std::size_t height);
  ~Probius();
  Probius(Probius const &other) = delete;
  Probius(Probius &&other) noexcept = delete;
  auto operator=(Probius const &other) -> Probius & = delete;
  auto operator=(Probius &&other) noexcept -> Probius & = delete;

  auto swap(std::size_t lhs, std::size_t rhs) -> void;
  auto less(std::size_t lhs, std::size_t rhs) const -> bool;
  auto size() const -> std::size_t;
  auto read(std::size_t idx) const -> u16;
  auto write(std::size_t idx, u16 val) -> void;

private:
  std::size_t width;
  std::size_t height;
  std::vector<u16> vector;

  auto display(char const *c = background::clear,
               std::initializer_list<std::size_t> lst = {}) const -> void;
};
