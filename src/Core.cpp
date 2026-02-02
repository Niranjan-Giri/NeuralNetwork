#include "Tensor.h"

int main()
{
    std::vector<std::vector<float>> data{{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    Tensor t(data);

    std::cout << t << std::endl;
}