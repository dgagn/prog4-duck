#pragma once
#include "pch.h"

class cache {
  std::unordered_map<std::string, std::shared_ptr<duck>> cache_map_;
public:
  static auto get_instance() noexcept -> cache& {
    static cache instance;
    return instance;
  }

  void add_cache(const std::string& key, const std::shared_ptr<duck>& d) { cache_map_[key] = d; }

  std::shared_ptr<duck> get_from_cache(const std::string& key) { return cache_map_[key]; }

  auto size() const noexcept -> size_t { return cache_map_.size(); }

  cache(const cache&) = delete;
  auto operator=(const cache&) -> cache& = delete;
  cache(cache&&) = delete;
  auto operator=(cache&&) -> cache& = delete;
private:
  cache() noexcept {}
};
