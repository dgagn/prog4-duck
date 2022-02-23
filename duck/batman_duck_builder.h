#pragma once
#include "duck_builder.h"
#include "pch.h"

class batman_duck_builder final : public duck_builder {
  std::shared_ptr<::duck> duck_ = std::make_shared<::duck>();
public:
  duck_builder* build_head() override {
    duck_->set_head("batman head");
    return this;
  }

  duck_builder* build_body() override {
    duck_->set_body("batman body");
    return this;
  }

  duck_builder* build_wings() override {
    duck_->set_wings("batman wings");
    return this;
  }

  duck_builder* build_suit() override {
    duck_->set_suit("batman suit");
    return this;
  }

  auto duck() const noexcept -> std::shared_ptr<::duck> override { return this->duck_; }

  auto name() -> std::string override { return "batman"; }
};
