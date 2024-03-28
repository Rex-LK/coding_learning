#include "infer_base.hpp"
#include "original_infer_a.hpp"

class ContainerInferA : public InferBase{
  using InferBase::InferBase;
public:
  virtual void load_model() override{
    std::cout << "container_infer_a reset original_infer_a_" << std::endl;
    original_infer_a_.reset(new OriginalInferA(model_path_));
}

  virtual std::string forward(const std::string& image_path) override{
    std::cout << "container_infer_a call original_infer_a_->forward_a" << std::endl;
    return  original_infer_a_->forward_a(image_path);
}
  std::shared_ptr<OriginalInferA> original_infer_a_ = nullptr;
};