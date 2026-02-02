#include "Tensor.h"

Tensor::Tensor(float data) 
    : m_Data{data}, m_Shape{}, m_Stride{} {}

Tensor::Tensor(std::vector<float> data)
    : m_Data(data), m_Shape{data.size()}, m_Stride{1} {}

Tensor::Tensor(std::vector<std::vector<float>> data) 
    : m_Shape{data.size(), data[0].size()}, m_Stride{data[0].size(), 1}
{
    for (std::size_t i = 0; i < data.size(); i++)
    {
        if (data[i].size() != data[0].size())
        {
            #if (defined __GNUC__ || defined __clang__)
                std::__throw_invalid_argument("Dimensions must be same!");
            #else
                throw std::invalig_argument("Dimensions must be same!");
            #endif
        }
    }

    for (std::size_t i = 0; i < data.size(); i++)
    {
        for (std::size_t j = 0; j < data[i].size(); j++)
        {
            m_Data.push_back(data[i][j]);
        }
    }
}

const float& Tensor::Item() const
{
    if (m_Data.size() == 1)
    {
        return m_Data[0];
    }
    else
    {
        #if (defined __GNUC__ || defined __clang__)
            std::__throw_runtime_error("Item() can only be called with single element");
        #else
            throw std::runtime_error("Item() can only be called with single element");
        #endif
    }
}

float& Tensor::Item()
{
    if (m_Data.size() == 1)
    {
        return m_Data[0];
    }
    else
    {
        #if (defined __GNUC__ || defined __clang__)
            std::__throw_runtime_error("Item() can only be called with single element");
        #else
            throw std::runtime_error("Item() can only be called with single element");
        #endif
    }
}