#pragma once
#include <iostream>
#include <memory>
#include <string>

#include "infer_base.hpp"

class OriginalInferB {
 public:
  OriginalInferB(const std::string& model_path) : model_path_(model_path) {
    std::cout << "original_infer_a load model: " << model_path << std::endl;
  }
  ~OriginalInferB() { model_path_.clear(); }
  
  std::string DoinferecneB(const std::string& image_path) {
    std::string result = "original_infer_a do inference:" + image_path;
    std::cout << result << std::endl;
    return result;
  }

 private:
  std::string model_path_;
};
