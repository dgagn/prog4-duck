#pragma once
#include "cache.h"
#include "duck_builder.h"

class duck_director {
  duck_builder* builder_;
public:
  void set_builder(duck_builder& builder) noexcept { builder_ = &builder; }

  duck_director() = default;

  std::shared_ptr<duck> build_duck() const {
    const std::string name_of_duck = builder_->name();

    printf("Building a %s duck\n", name_of_duck.c_str());
    printf("%llu duck(s) in cache\n", cache::get_instance().size());
    const auto cache_duck = cache::get_instance().get_from_cache(name_of_duck);
    if (!cache_duck)
    {
      printf("The %s duck doesn't exist in cache\n", name_of_duck.c_str());
      auto duck = builder_->build_head()->build_body()->build_wings()->build_suit()->duck();
      duck->generate();
      printf("The %s duck has been added to the cache\n", builder_->name().c_str());
      cache::get_instance().add_cache(name_of_duck, duck);
      return duck;
    }
    printf("A fresh %s duck from the cache has been found\n", name_of_duck.c_str());

    return cache_duck->clone();
  }
};
