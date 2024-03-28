#pragma once
#include <iostream>
#include <memory>
#include <string>

#include "infer_base.hpp"

class OriginalInferB {
 public:
  OriginalInferB(const std::string& model_path) : model_path_(model_path) {
    std::cout << "original_infer_b load model: " << model_path << std::endl;
  }
  ~OriginalInferB() { model_path_.clear(); }
  
  std::string forward_b(const std::string& image_path) {
    std::cout << "original_infer_b forward:" + image_path << std::endl;
    return "original forward_b:" + image_path + "_result";
  }

 private:
  std::string model_path_;
};
