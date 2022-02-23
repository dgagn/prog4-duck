#pragma once
#include "duck_builder.h"

class spiderman_duck_builder final : public duck_builder {
  std::shared_ptr<::duck> duck_ = std::make_shared<::duck>();
public:
  duck_builder* build_head() override {
    duck_->set_head("spiderman head");
    return this;
  }

  duck_builder* build_body() override {
    duck_->set_body("spiderman body");
    return this;
  }

  duck_builder* build_wings() override {
    duck_->set_wings("spiderman wings");
    return this;
  }

  duck_builder* build_suit() override {
    duck_->set_suit("spiderman suit");
    return this;
  }

  std::shared_ptr<::duck> duck() const noexcept override { return this->duck_; }

  auto name() -> std::string override { return "spiderman"; }
};
