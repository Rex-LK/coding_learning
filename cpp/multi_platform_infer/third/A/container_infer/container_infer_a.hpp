#include "infer_base.hpp"
#include "original_infer_a.hpp"

class ContainerInferA : public InferBase{
  using InferBase::InferBase;
public:
  virtual void load_model() override{
    cout << "ContainerInferA reset OriginalInferA" << endl;
    original_infer_a_.reset(new OriginalInferA(model_path_));
}

  virtual std::string doinference(const std::string& image_path) override{
    cout << "ContainerInferA call original_infer_a_->DoinferecneA" << endl;
    return  original_infer_a_->DoinferecneA(image_path);
}
  std::shared_ptr<OriginalInferA> original_infer_a_ = nullptr;
};