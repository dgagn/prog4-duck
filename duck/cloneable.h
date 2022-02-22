#pragma once
#include "pch.h"

template <typename Derived>
class cloneable {
public:
  virtual auto clone() const -> std::unique_ptr<Derived> = 0;

  // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-five
  cloneable() = default;
  virtual ~cloneable() = default;
  cloneable(const cloneable&) = default;
  auto operator=(const cloneable&) -> cloneable& = delete;
  cloneable(cloneable&&) = delete;
  auto operator=(cloneable&&) -> cloneable& = delete;
};
