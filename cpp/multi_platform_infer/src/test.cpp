#include <iostream>
#include <memory>
#include <string>
#include "infer_base.hpp"
using namespace std;

#if defined(INFER_IN_A)
#include "container_infer_a.hpp"
#elif defined(INFER_IN_B)
#include "container_infer_b.hpp"
#endif

int main(){
    shared_ptr<InferBase> infer = nullptr;
    string model_path = "test.model";
    string image_path = "test.png";
    #if defined(INFER_IN_A)
    infer.reset(new ContainerInferA(model_path));
    #elif defined(INFER_IN_B)
    infer.reset(new ContainerInferB(model_path));
    #endif
    infer->load_model();
    auto infer_result  = infer->doinference(image_path);
    return 0;
}