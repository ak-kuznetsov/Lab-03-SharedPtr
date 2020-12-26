// Copyright 2020 ak-kuznetsov <a.kuznetsov2701@mail.ru>

#include <gtest/gtest.h>

#include <SharedPtr.hpp>
TEST(Example, EmptyTest) { EXPECT_TRUE(true); }

TEST(SharedPtr_Test, Constructor_Test) {
  int a{5};
  SharedPtr<int> b{&a};
  ASSERT_EQ(*b, a);
}

TEST(SharedPtr_Test, Lvalue_Test) {
  int a{8};
  SharedPtr b(&a);
  SharedPtr lvalue(b);
  ASSERT_EQ(b.use_count(), 2);
}

TEST(SharedPtr_Test, Rvalue_Test) {
  int a{9};
  SharedPtr b(&a);
  SharedPtr rvalue(std::move(b));
  ASSERT_EQ(b.use_count(), 2);
}

TEST(SharedPtr_Test, is_move_constructible){
  ASSERT_EQ(std::is_move_constructible<SharedPtr<int>>::value,true);
}

TEST(SharedPtr_Test, is_move_assignable){
  ASSERT_EQ(std::is_move_assignable<SharedPtr<int>>::value,true);
}

TEST(SharedPtr_Test, Swap_Test){
  int a{1};
  int b{2};
  SharedPtr<int> A(&a);
  SharedPtr<int> B(&b);
  B.swap(A);
  ASSERT_EQ(*B, 1);
}
