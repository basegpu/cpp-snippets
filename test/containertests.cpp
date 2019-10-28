#include <gtest/gtest.h>
#include "variant.hpp"
#include "container.hpp"
#include <stdexcept>
#include <string>

using namespace container;

TEST(ContainerTests, ConstructInt)
{
    auto v = Variant::Create<int>(1, 1);
    ASSERT_EQ(1, v->Get<int>()->n_cols);
    ASSERT_EQ(1, v->Get<int>()->n_rows);
    ASSERT_THROW(v->Get<double>(), std::invalid_argument);
    delete v;
}

TEST(ContainerTests, ConstructFloat)
{
    auto v = Variant::Create<double>(1, 1);
    ASSERT_EQ(1, v->Get<double>()->n_cols);
    ASSERT_EQ(1, v->Get<double>()->n_rows);
    ASSERT_THROW(v->Get<int>(), std::invalid_argument);
    delete v;
}

TEST(ContainerTests, EmptyContainer)
{
    Container<int> c;
    ASSERT_EQ(0, c.GetSize());
}

TEST(ContainerTests, HeteroContainer)
{
    Container<std::string> c;
    c.AddItem<int>("label1", 1, 2);
    c.AddItem<double>("label2", 3, 4);
    ASSERT_EQ(2, c.GetSize());
    ASSERT_EQ(2, c.GetItem("label1")->Get<int>()->n_elem);
    ASSERT_EQ(12, c.GetItem("label2")->Get<double>()->n_elem);
}

TEST(ContainerTests, HeteroContainerData)
{
    Container<std::string> c;
    c.AddItem<int>("label1", 1, 2);
    c.AddItem<double>("label2", 3, 4);
    ASSERT_EQ(2, c.GetDataFrom<int>("label1")->n_elem);
    ASSERT_EQ(12, c.GetDataFrom<double>("label2")->n_elem);
}

TEST(ContainerTests, HeteroContainerError)
{
    Container<std::string> c;
    c.AddItem<int>("label1", 1, 2);
    ASSERT_THROW(c.GetItem("label2"), std::out_of_range);
    ASSERT_THROW(c.GetDataFrom<double>("label1"), std::invalid_argument);
}

TEST(ContainerTests, EnumKey)
{
    enum class Keys : unsigned char
    {
        Key1,
        Key2,
        Key3,
        Key4,
        Key5
    };
    Container<Keys> c;
    c.AddItem<int>(Keys::Key1, 1, 1);
    c.AddItem<int>(Keys::Key2, 1, 1);
    c.AddItem<int>(Keys::Key3, 1, 1);
    c.AddItem<int>(Keys::Key4, 1, 1);
    c.AddItem<int>(Keys::Key5, 1, 1);
    const int nAccess = 10000000;
    for (int ii = 0; ii < nAccess; ii++)
    {
        auto d = c.GetDataFrom<int>(Keys::Key1);
    }
}

TEST(ContainerTests, Performance)
{
    Container<int> c;
    const int nLabels = 5;
    int ll;
    for (ll = 0; ll < nLabels; ll++)
    {
        c.AddItem<int>(ll, 1, 1);
    }
    const int nAccess = 10000000;
    const int label = ll - 1;
    for (int ii = 0; ii < nAccess; ii++)
    {
        auto d = c.GetDataFrom<int>(label);
    }
}
