#pragma once
#include <string>
class InferBase
{
public:
    InferBase(const std::string& model_path){
        model_path_ = model_path;
    }
    virtual ~InferBase(){
        model_path_.clear();
    }

    virtual std::string forward (const std::string& image_path) = 0;
    virtual void load_model() = 0;

protected:
    std::string model_path_;
};

