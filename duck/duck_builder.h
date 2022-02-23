#pragma once
#include "duck.h"
#include "pch.h"

class duck_builder {
public:
  virtual ~duck_builder() = default;

  duck_builder() = default;
  duck_builder(const duck_builder&) = delete;
  auto operator=(const duck_builder&) -> duck_builder& = delete;
  duck_builder(duck_builder&&) = delete;
  auto operator=(duck_builder&&) -> duck_builder& = delete;

  virtual auto name() -> std::string = 0;
  virtual auto build_head() -> duck_builder* = 0;
  virtual auto build_body() -> duck_builder* = 0;
  virtual auto build_wings() -> duck_builder* = 0;
  virtual auto build_suit() -> duck_builder* = 0;
  virtual std::shared_ptr<duck> duck() const = 0;
};
