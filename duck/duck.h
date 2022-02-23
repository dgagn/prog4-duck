#pragma once
#include "cloneable.h"
#include "pch.h"

class duck final : public cloneable<duck> {
public:
  void set_head(const std::string& head) { head_ = head; }
  void set_body(const std::string& body) { body_ = body; }
  void set_wings(const std::string& wings) { wings_ = wings; }
  void set_suit(const std::string& suit) { suit_ = suit; }

  void generate() {
    constexpr int wait_time = 1000;
    printf("--- Starting the generation of the 3D model ... ---\n");
    std::stringstream ss;
    printf("Generation of the head ...\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    ss << head_ + '\n';
    printf("Generation of the body ...\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    ss << body_ + '\n';
    printf("Generation of the wings ...\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    ss << wings_ + '\n';
    printf("Generation of the suit ...\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    ss << suit_ + '\n';
    this->model_ = ss.str();
    printf("--- 3D model generated successfully ! ---\n");
  }

  std::unique_ptr<duck> clone() const override { return std::make_unique<duck>(*this); }

  std::string model() const { return model_; }
private:
  std::string head_;
  std::string body_;
  std::string wings_;
  std::string suit_;
  std::string model_;
};
