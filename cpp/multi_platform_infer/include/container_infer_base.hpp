#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "infer_base.hpp"
#if defined(INFER_IN_A)
#include "container_infer_a.hpp"
#elif defined(INFER_IN_B)
#include "container_infer_b.hpp"
#endif

class ContainerInferBase
{
public:
    ContainerInferBase(const std::string& model_path){
        #if defined(INFER_IN_A)
        std::cout << "ContainerInferBase reset ContainerInferA" << std::endl;
        infer_base_.reset(new ContainerInferA(model_path));
        #elif defined(INFER_IN_B)
        std::cout << "ContainerInferBase reset ContainerInferB" << std::endl;
        infer_base_.reset(new ContainerInferB(model_path));
        #endif
    }
    ~ContainerInferBase(){
    }

    std::string forward(const std::string& image_path){
        std::cout << "ContainerInferBase call InferBase forward" << std::endl;
        return infer_base_->forward(image_path);
    }

private:
    std::shared_ptr<InferBase> infer_base_ = nullptr;
};