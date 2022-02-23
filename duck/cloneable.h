#pragma once
#include "pch.h"

template <typename Derived>
class cloneable {
public:
  virtual std::unique_ptr<Derived> clone() const = 0;

  cloneable() = default;
  virtual ~cloneable() = default;
  cloneable(const cloneable&) = default;
  cloneable& operator=(const cloneable&) = delete;
  cloneable(cloneable&&) = delete;
  cloneable& operator=(cloneable&&) = delete;
};
