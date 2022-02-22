#pragma once
#include "pch.h"
#include "duck.h"

class builder {
public:
  virtual ~builder() = default;

  builder() = default;
  builder(const builder&) = delete;
  auto operator=(const builder&) -> builder& = delete;
  builder(builder&&) = delete;
  auto operator=(builder&&) -> builder& = delete;

  virtual auto build_head() -> builder* = 0;
  virtual auto build_body() -> builder* = 0;
  virtual auto build_wings() -> builder* = 0;
  virtual auto build_suit() -> builder* = 0;
  virtual std::shared_ptr<duck> duck() const = 0;
};
