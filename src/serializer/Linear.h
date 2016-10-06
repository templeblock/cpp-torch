#pragma once
#include "../nn/Linear.h"


namespace serializer
{
    template<class TTensor>
    class Linear : public nn::Linear<TTensor>
    {
    public:
        void unserialize(const object_torch *obj, model_builder<TTensor> *mb)
        {
            const object_table *obj_tbl = obj->data_->to_table();
            this->weight_ = mb->build_tensor(obj_tbl->get("weight"));
            this->bias_ = mb->build_tensor(obj_tbl->get("bias"));
        }
    };
}