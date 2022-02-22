#include "pch.h"
#include "duck_builder.h"

auto main() -> int {
  std::cout << "Hello World!\n";

  duck d;

  duck_builder builder;

  const auto shared = builder.build_body()->build_head()->build_suit()->build_wings()->duck();
  {
    const auto second = shared->clone();
    shared->generate();
    std::cout << shared->model() << std::endl;
    std::cout << second->model() << std::endl;
  }

  const auto second = shared->clone();

  std::cout << shared->model() << std::endl;
  std::cout << second->model() << std::endl;

  return 0;
}
