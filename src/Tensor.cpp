#include "Tensor.h"

std::ostream& operator<<(std::ostream& os, const Tensor& t)
{
    std::string Output = "[";
    if (t.GetShape().size() == 0)
    {
        os << t.Item();
        return os;
    }

    else if (t.GetShape().size() == 1)
    {
        for (std::size_t i = 0; i < t.GetShape()[0]; i++)
        {
            Output += std::to_string(t(i));
            if (i != t.GetShape()[0] - 1)
            {
                Output += ", ";
            }
        }
        Output += "]";
    }

    else
    {
        for (std::size_t i = 0; i < t.GetShape()[0]; i++)
        {
            Output += "[";
            for (std::size_t j = 0; j < t.GetShape()[1]; j++)
            {
                Output += std::to_string(t(i, j));
                if (j != t.GetShape()[1] - 1)
                {
                    Output += ", ";
                }
            }
            Output += "]";
            if (i != t.GetShape()[0] - 1)
            {
                Output += ", ";
            }
        }
        Output += "]";
    }

    os << Output;
    return os;
}

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
            throw std::invalid_argument("Dimensions must be same!");
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
        throw std::runtime_error("Item() can only be called with single element");
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
        throw std::runtime_error("Item() can only be called with single element");
    }
}

const float& Tensor::operator()(std::size_t i) const
{
    if (m_Shape.size() == 0)
    {
      
        throw std::invalid_argument("Cannot index into a scalar. Use Item()");
    }

    if (m_Shape.size() == 1)
    {
        if (i >= m_Shape[0])
        {
            throw std::invalid_argument(
                "Index " + std::to_string(i) + " is out range for array of size " + std::to_string(m_Shape[0])
            );  
        }
        return m_Data[i];
    }
    throw std::invalid_argument("Use 2d indices.");    
}

float& Tensor::operator()(std::size_t i)
{
    if (m_Shape.size() == 0)
    {
      
        throw std::invalid_argument("Cannot index into a scalar. Use Item()");
    }

    if (m_Shape.size() == 1)
    {
        if (i >= m_Shape[0])
        {
            throw std::invalid_argument(
                "Index " + std::to_string(i) + " is out range for array of size " + std::to_string(m_Shape[0])
            );  
        }
        return m_Data[i];
    }
    throw std::invalid_argument("Use 2d indices.");
}

const float& Tensor::operator()(std::size_t i, std::size_t j) const
{
    if (m_Shape.size() == 2)
    {
        if (i >= m_Shape[0])
        {
            throw std::invalid_argument(
                "Row index " + std::to_string(i) + " is out of bounds for array having " + std::to_string(m_Shape[0]) + " rows."
            );
        }
        if (j >= m_Shape[1])
        {
            throw std::invalid_argument(
                "Column index " + std::to_string(j) + " is out of bounds for array having " + std::to_string(m_Shape[1]) + " columns."
            );
        }

        return m_Data[i * m_Stride[0] + j * m_Stride[1]];   
    }
    throw std::invalid_argument("Can only index to 2d tensors!");
}

float& Tensor::operator()(std::size_t i, std::size_t j)
{
    if (m_Shape.size() == 2)
    {
        if (i >= m_Shape[0])
        {
            throw std::invalid_argument(
                "Row index " + std::to_string(i) + " is out of bounds for array having " + std::to_string(m_Shape[0]) + " rows."
            );
        }
        if (j >= m_Shape[1])
        {
            throw std::invalid_argument(
                "Column index " + std::to_string(j) + " is out of bounds for array having " + std::to_string(m_Shape[1]) + " columns."
            );
        }

        return m_Data[i * m_Stride[0] + j * m_Stride[1]];   
    }
    throw std::invalid_argument("Can only index to 2d tensors!");
}