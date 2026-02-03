#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <string>

class Tensor
{
    friend std::ostream& operator<<(std::ostream& os, const Tensor& t);
public:
    Tensor(float data);
    Tensor(std::vector<float> data);
    Tensor(std::vector<std::vector<float>> data);

    const float& Item() const;
    float& Item();

    //Overloading () operator
    const float& operator()(std::size_t i) const;
    float& operator()(std::size_t i);
    const float& operator()(std::size_t i, std::size_t j) const;
    float& operator()(std::size_t i, std::size_t j);

    //Overloading + operator
    std::shared_ptr<Tensor> operator+(std::shared_ptr<Tensor> other);

    //Getters
    inline const std::vector<std::size_t>& GetShape() const { return m_Shape; }
    inline const std::vector<std::size_t>& GetStride() const { return m_Stride; }

private:
    //Any type of data will be stored in row major order
    std::vector<float> m_Data;

    //Shape is the size of data, If 1d, then total size
    //If 2d, then total size as well as size of first vector elements
    std::vector<std::size_t> m_Shape;

    //Stride is how far we need to go to get the next data
    std::vector<std::size_t> m_Stride;
};