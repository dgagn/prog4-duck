#pragma once
#include "pch.h"
#include "builder.h"

class duck_builder final : public builder {
  std::shared_ptr<::duck> duck_ = std::make_shared<::duck>();
public:
  auto build_head() -> builder* override {
    duck_->set_head("batman head");
    return this;
  }

  auto build_body() -> builder* override {
    duck_->set_body("batman body");
    return this;
  }

  auto build_wings() -> builder* override {
    duck_->set_wings("batman wings");
    return this;
  }

  auto build_suit() -> builder* override {
    duck_->set_suit("batman suit");
    return this;
  }

  std::shared_ptr<::duck> duck() const noexcept override { return this->duck_; }
};
