#pragma once

#include <vector>

class Tensor
{
public:
    Tensor(float data);
    Tensor(std::vector<float> data);
    Tensor(std::vector<std::vector<float>> data);

    const float& Item() const;
    float& Item();

private:
    //Any type of data will be stored in row major order
    std::vector<float> m_Data;

    //Shape is the size of data, If 1d, then total size
    //If 2d, then total size as well as size of first vector elements
    std::vector<std::size_t> m_Shape;

    //Stride is how far we need to go to get the next data
    std::vector<std::size_t> m_Stride;
};