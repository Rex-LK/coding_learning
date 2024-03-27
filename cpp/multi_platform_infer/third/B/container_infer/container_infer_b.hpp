#include "infer_base.hpp"
#include "original_infer_b.hpp"

class ContainerInferB : public InferBase{
  using InferBase::InferBase;
public:
  virtual void load_model() override{
    cout << "ContainerInferB reset OriginalInferB" << endl;
    original_infer_b_.reset(new OriginalInferB(model_path_));
}

  virtual std::string doinference(const std::string& image_path) override{
    cout << "ContainerInferB call original_infer_b_->DoinferecneB" << endl;
    return  original_infer_b_->DoinferecneB(image_path);
}
  std::shared_ptr<OriginalInferB> original_infer_b_ = nullptr;
};