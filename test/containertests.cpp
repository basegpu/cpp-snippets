#include <gtest/gtest.h>
#include "variant.hpp"
#include "container.hpp"
#include <stdexcept>

using namespace container;

TEST(ContainerTests, ConstructInt)
{
    auto v = Variant::Create<int>(1, 1);
    ASSERT_EQ(1, v->Get<int>()->n_cols);
    ASSERT_EQ(1, v->Get<int>()->n_rows);
    ASSERT_EQ(nullptr, v->Get<double>());
    delete v;
}

TEST(ContainerTests, ConstructFloat)
{
    auto v = Variant::Create<double>(1, 1);
    ASSERT_EQ(1, v->Get<double>()->n_cols);
    ASSERT_EQ(1, v->Get<double>()->n_rows);
    ASSERT_EQ(nullptr, v->Get<int>());
    delete v;
}

TEST(ContainerTests, EmptyContainer)
{
    Container c;
    ASSERT_EQ(0, c.GetSize());
}

TEST(ContainerTests, HeteroContainer)
{
    Container c;
    c.AddItem<int>("label1", 1, 2);
    c.AddItem<double>("label2", 3, 4);
    ASSERT_EQ(2, c.GetSize());
    ASSERT_EQ(2, c.GetItem("label1")->Get<int>()->n_elem);
    ASSERT_EQ(12, c.GetItem("label2")->Get<double>()->n_elem);
    ASSERT_THROW(c.GetItem("dummy"), std::out_of_range);
}
