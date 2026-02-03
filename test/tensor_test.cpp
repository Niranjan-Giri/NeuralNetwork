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

TEST(TensorTest, Addition)
{
    //scalar+scalar
    std::shared_ptr<Tensor> t1 = std::make_shared<Tensor>(1.0);
    std::shared_ptr<Tensor> t2 = std::make_shared<Tensor>(3.0);
    std::shared_ptr<Tensor> t3 = (*t1) + t2;
    EXPECT_EQ(t3->Item(), 4.0);

    //scalar+1d
    std::shared_ptr<Tensor> t4 = std::make_shared<Tensor>(1.0);
    std::shared_ptr<Tensor> t5 = std::make_shared<Tensor>(std::vector<float>({1.0, 3.0}));
    std::shared_ptr<Tensor> t6 = (*t4) + t5;
    EXPECT_EQ((*t6)(0), 2.0);
    EXPECT_EQ((*t6)(1), 4.0);

    //1d+scalar
    std::shared_ptr<Tensor> t7 = std::make_shared<Tensor>(std::vector<float>({1.0, 3.0}));
    std::shared_ptr<Tensor> t8 = std::make_shared<Tensor>(1.0);
    std::shared_ptr<Tensor> t9 = (*t7) + t8;
    EXPECT_EQ((*t9)(0), 2.0);
    EXPECT_EQ((*t9)(1), 4.0);

    //scalar+2d
    std::shared_ptr<Tensor> t10 = std::make_shared<Tensor>(1.0);
    std::shared_ptr<Tensor> t11 = std::make_shared<Tensor>(std::vector<std::vector<float>>({{1.0, 3.0}, {3.0, 4.0}}));
    std::shared_ptr<Tensor> t12 = (*t10) + t11;
    EXPECT_EQ((*t12)(0, 0), 2.0);
    EXPECT_EQ((*t12)(0, 1), 4.0);
    EXPECT_EQ((*t12)(1, 0), 4.0);
    EXPECT_EQ((*t12)(1, 1), 5.0);

    //2d+scalar
    std::shared_ptr<Tensor> t13 = std::make_shared<Tensor>(std::vector<std::vector<float>>({{1.0, 3.0}, {3.0, 4.0}}));
    std::shared_ptr<Tensor> t14 = std::make_shared<Tensor>(1.0);
    std::shared_ptr<Tensor> t15 = (*t13) + t14;
    EXPECT_EQ((*t15)(0, 0), 2.0);
    EXPECT_EQ((*t15)(0, 1), 4.0);
    EXPECT_EQ((*t15)(1, 0), 4.0);
    EXPECT_EQ((*t15)(1, 1), 5.0);

    //1d+1d
    std::shared_ptr<Tensor> t16 = std::make_shared<Tensor>(std::vector<float>({1.0, 3.0}));
    std::shared_ptr<Tensor> t17 = std::make_shared<Tensor>(std::vector<float>({1.0, 3.0}));
    std::shared_ptr<Tensor> t18 = (*t16) + t17;
    EXPECT_EQ((*t18)(0), 2.0);
    EXPECT_EQ((*t18)(1), 6.0);

    //2d+2d
    std::shared_ptr<Tensor> t19 = std::make_shared<Tensor>(std::vector<std::vector<float>>({{1.0, 3.0}, {3.0, 4.0}}));
    std::shared_ptr<Tensor> t20 = std::make_shared<Tensor>(std::vector<std::vector<float>>({{1.0, 3.0}, {3.0, 4.0}}));
    std::shared_ptr<Tensor> t21 = (*t19) + t20;
    EXPECT_EQ((*t21)(0, 0), 2.0);
    EXPECT_EQ((*t21)(0, 1), 6.0);
    EXPECT_EQ((*t21)(1, 0), 6.0);
    EXPECT_EQ((*t21)(1, 1), 8.0);
}

TEST(TensorTest, Multiplication)
{
    std::shared_ptr<Tensor> t1 = std::make_shared<Tensor>(1.0);
    std::shared_ptr<Tensor> t2 = std::make_shared<Tensor>(2.0);
    EXPECT_THROW((*t1) * t2, std::invalid_argument);

    std::shared_ptr<Tensor> t3 = std::make_shared<Tensor>(1.0);
    std::shared_ptr<Tensor> t4 = std::make_shared<Tensor>(std::vector<float>({1.0, 2.0}));
    EXPECT_THROW((*t3) * t4, std::invalid_argument);

    //1d*1d
    std::shared_ptr<Tensor> t5 = std::make_shared<Tensor>(std::vector<float>({1.0, 2.0}));
    std::shared_ptr<Tensor> t6 = std::make_shared<Tensor>(std::vector<float>({1.0, 2.0}));
    std::shared_ptr<Tensor> t7 = (*t5) * t6;
    EXPECT_EQ(t7->Item(), 5.0);
}