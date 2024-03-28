#pragma once
#include <iostream>
#include <memory>
#include <string>

#include "infer_base.hpp"

class OriginalInferA {
 public:
  OriginalInferA(const std::string& model_path) : model_path_(model_path) {
    std::cout << "original_infer_a load model: " << model_path << std::endl;
  }
  ~OriginalInferA() { model_path_.clear(); }
  
  std::string forward_a(const std::string& image_path) {
    std::cout << "original_infer_a forward_a:" + image_path << std::endl;
    return "original_infer_a forward_a:" + image_path + "_result";
  }

 private:
  std::string model_path_;
};
