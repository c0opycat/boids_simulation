//
// Created by arthur on 30/11/2025.
//

#include "gtest/gtest.h"
#include "../src/containers/DynamicArray.hpp"

class DynamicArrayTest : public testing::Test {
protected:
    DynamicArray<int> array_int;
    DynamicArray<float> array_float;
};

TEST_F(DynamicArrayTest, DefaultConstructor) {
    const DynamicArray<int> arr;
    EXPECT_EQ(arr.size(), 0);
    EXPECT_EQ(arr.capacity(), 1);
}

TEST_F(DynamicArrayTest, PushBackIncreasesSize) {
    array_int.push_back(3);
    array_int.push_back(4);

    EXPECT_EQ(array_int.size(), 2);
    EXPECT_EQ(array_int[0], 3);
    EXPECT_EQ(array_int[1], 4);
}

TEST_F(DynamicArrayTest, CapacityDoublesWhenFull) {
    DynamicArray<int> arr;
    const size_t capacity = arr.capacity();
    for (int i = 0; i < capacity; i++) {
        arr.push_back(i);
    }

    arr.push_back(50);
    EXPECT_EQ(arr.capacity(), 2);
    EXPECT_EQ(arr[capacity], 50);
}

TEST_F(DynamicArrayTest, PopBackReducesSize) {
    DynamicArray<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    arr.pop_back();

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[1], 2);
}

TEST_F(DynamicArrayTest, PopBackOnEmptyDoesNothing) {
    DynamicArray<int> arr;
    EXPECT_NO_THROW(arr.pop_back());
    EXPECT_EQ(arr.size(), 0);
}

TEST_F(DynamicArrayTest, OperatorIndexReturnsCorrectValue) {
    DynamicArray<int> arr;
    arr.push_back(3);
    arr.push_back(7);

    EXPECT_EQ(arr[0], 3);
    EXPECT_EQ(arr[1], 7);
}

TEST_F(DynamicArrayTest, OperatorIndexThrowsOnOutOfRange) {
    DynamicArray<int> arr;
    arr.push_back(1);

    EXPECT_THROW(arr[1], std::out_of_range);
    EXPECT_THROW(arr[99], std::out_of_range);
}

TEST_F(DynamicArrayTest, CopyConstructorCopiesElements) {
    DynamicArray<int> arr;
    arr.push_back(5);
    arr.push_back(10);

    DynamicArray<int> copy(arr);

    EXPECT_EQ(copy.size(), 2);
    EXPECT_EQ(copy[0], 5);
    EXPECT_EQ(copy[1], 10);
}

TEST_F(DynamicArrayTest, CopyConstructorIsIndependent) {
    DynamicArray<int> arr;
    arr.push_back(5);

    DynamicArray<int> copy(arr);

    copy[0] = 100;

    EXPECT_NE(arr[0], copy[0]);
}

TEST_F(DynamicArrayTest, CopyAssignmentCopiesElements) {
    DynamicArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);

    DynamicArray<int> other;
    other.push_back(99);

    other = arr;

    EXPECT_EQ(other.size(), 2);
    EXPECT_EQ(other[0], 1);
    EXPECT_EQ(other[1], 2);
}

TEST_F(DynamicArrayTest, SelfCopyAssignmentDoesNothing) {
    DynamicArray<int> arr;
    arr.push_back(4);
    arr.push_back(8);

    EXPECT_NO_THROW(arr = arr);
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 4);
    EXPECT_EQ(arr[1], 8);
}

TEST_F(DynamicArrayTest, PushBackManyElements) {
    DynamicArray<int> arr;

    const int N = 5000;
    for (int i = 0; i < N; i++)
        arr.push_back(i);

    EXPECT_EQ(arr.size(), N);

    for (int i = 0; i < N; i++)
        EXPECT_EQ(arr[i], i);
}