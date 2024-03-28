#include <iostream>
#include <memory>
#include <string>
#include "container_infer_base.hpp"
using namespace std;


int main(){
    shared_ptr<ContainerInferBase> infer = nullptr;
    string model_path = "test.model";
    string image_path = "test.png";
    infer.reset(new ContainerInferBase(model_path));
    infer->forward(image_path);
    return 0;
}