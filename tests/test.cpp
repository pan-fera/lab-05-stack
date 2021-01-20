// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include <Stack.hpp>
TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}
template <typename T>
struct Struct
{
  T data1;
  T data2;
  T data3;
};

TEST(Stack, Push_rvalue) {
  Stack<double> a;
  EXPECT_THROW(a.head(), std::runtime_error);

  a.push(5.7);
  EXPECT_EQ(a.head(), 5.7);

  a.push(10.3);
  EXPECT_EQ(a.head(), 10.3);

  double val = 9;
  a.push(std::move(val));
  EXPECT_EQ(a.head(), 9.0);

  Stack<Struct<std::string>> b;
  Struct<std::string> test_struct {"one", "two", "three"};
  b.push(std::move(test_struct));
  EXPECT_EQ(b.head().data1, test_struct.data1);
  EXPECT_EQ(b.head().data2, test_struct.data2);
  EXPECT_EQ(b.head().data3, test_struct.data3);
}

TEST(Stack, Push_lvalue) {
  Stack<double> a;
  EXPECT_THROW(a.head(), std::runtime_error);

  double val1 = 5.7;
  double val2 = 10.3;

  a.push(val1);
  EXPECT_EQ(a.head(), val1);

  a.push(val2);
  EXPECT_EQ(a.head(), val2);

  Stack<Struct<std::string>> b;
  Struct<std::string> test_struct {"one", "two", "three"};
  b.push(test_struct);
  EXPECT_EQ(b.head().data1, test_struct.data1);
  EXPECT_EQ(b.head().data2, test_struct.data2);
  EXPECT_EQ(b.head().data3, test_struct.data3);
}

TEST(Stack, Pop) {
  Stack<double> a;
  EXPECT_THROW(a.head(), std::runtime_error);

  double val1 = 5.7;
  double val2 = 10.3;
  double val3 = 9;

  a.push(val1);
  a.push(val2);
  a.push(val3);
  a.pop();
  EXPECT_EQ(a.head(), val2);
  a.pop();
  EXPECT_EQ(a.head(), val1);
  a.pop();
  EXPECT_THROW(a.head(), std::runtime_error);
}

TEST(Stack, Head) {
  Stack<int> a;
  EXPECT_THROW(a.head(), std::runtime_error);
  a.push(5);
  EXPECT_EQ(a.head(), 5);
  a.push(10);
  EXPECT_EQ(a.head(), 10);
  a.pop();
  EXPECT_EQ(a.head(), 5);
}

TEST(Stack, Is_Move) {
  EXPECT_TRUE(std::is_move_constructible<Stack<int>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack<int>>::value);

  EXPECT_TRUE(std::is_move_constructible<Stack<Struct<std::string>>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack<Struct<std::string>>>::value);

  EXPECT_TRUE(std::is_move_constructible<Stack<Struct<double>>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack<Struct<double>>>::value);
}

TEST(Stack, Is_Copy) {
  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);

  EXPECT_FALSE(std::is_copy_constructible<Stack<Struct<std::string>>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<Struct<std::string>>>::value);

  EXPECT_FALSE(std::is_copy_constructible<Stack<Struct<double>>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<Struct<double>>>::value);
}