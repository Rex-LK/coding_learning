#include "infer_base.hpp"
#include "original_infer_b.hpp"

class ContainerInferB : public InferBase{
  using InferBase::InferBase;
public:
  virtual void load_model() override{
    std::cout << "container_infer_b reset original_infer_b" << std::endl;
    original_infer_b_.reset(new OriginalInferB(model_path_));
}

  virtual std::string forward(const std::string& image_path) override{
    std::cout << "container_infer_b call original_infer_b->forward_b" << std::endl;
    return  original_infer_b_->forward_b(image_path);
}
  std::shared_ptr<OriginalInferB> original_infer_b_ = nullptr;
};