#include "Tensor.h"

#include <gtest/gtest.h>

TEST(TensorTest, Creation)
{
    Tensor t = Tensor(5.0);
    EXPECT_EQ(t.GetShape(), std::vector<std::size_t>({}));
    EXPECT_THROW(t(0), std::invalid_argument);
    EXPECT_EQ(t.Item(), 5.0);

    Tensor t1d = Tensor({1.0, 2.0, 3.0});
    EXPECT_EQ(t1d.GetShape(), std::vector<std::size_t>({3}));
    EXPECT_EQ(t1d(0), 1.0);
    EXPECT_EQ(t1d(1), 2.0);
    EXPECT_EQ(t1d(2), 3.0);
    EXPECT_THROW(t1d(3), std::invalid_argument);
    EXPECT_THROW(t1d.Item(), std::runtime_error);

    Tensor t2d = Tensor({{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}});
    EXPECT_EQ(t2d.GetShape(), std::vector<std::size_t>({2, 3}));
    EXPECT_EQ(t2d.GetStride(), std::vector<std::size_t>({3, 1}));
    EXPECT_EQ(t2d(0, 0), 1.0);
    EXPECT_EQ(t2d(0, 1), 2.0);
    EXPECT_EQ(t2d(0, 2), 3.0);
    EXPECT_THROW(t2d(2, 0), std::invalid_argument);
    EXPECT_THROW(t2d(0, 3), std::invalid_argument);
    EXPECT_THROW(t2d.Item(), std::runtime_error);
}