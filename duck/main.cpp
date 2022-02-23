#include "pch.h"
#include "batman_duck_builder.h"
#include "duck_director.h"
#include "spiderman_duck_builder.h"

auto main() -> int {
  duck_director director{};

  batman_duck_builder batman_builder;
  spiderman_duck_builder spider_builder;

  director.set_builder(batman_builder);
  const auto first_batman = director.build_duck();
  std::cout << "memory address: " << &*first_batman << "\n\n";

  const auto second_batman = director.build_duck();
  std::cout << "memory address: " << &*second_batman << "\n\n";

  director.set_builder(spider_builder);
  const auto first_spiderman = director.build_duck();
  std::cout << "memory address: " << &*first_spiderman << "\n\n";

  const auto second_spiderman = director.build_duck();
  std::cout << "memory address: " << &*second_spiderman << "\n\n";

  director.set_builder(batman_builder);
  const auto new_batman = director.build_duck();
  std::cout << "memory address: " << &*new_batman << "\n\n";

  return 0;
}
