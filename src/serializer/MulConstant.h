#pragma once
#include "../nn/MulConstant.h"


namespace serializer
{
    template<class TTensor>
    class MulConstant : public nn::MulConstant<TTensor>
    {
    public:
        void unserialize(const object_torch *obj, model_builder<TTensor> *mb)
        {
            const object_table *obj_tbl = obj->data_->to_table();
            this->inplace_ = *obj_tbl->get("inplace");
            this->constant_scalar_ = *obj_tbl->get("constant_scalar");
            assert(this->inplace_ == false && "change input inplace is dangerous");
        }
    };
}