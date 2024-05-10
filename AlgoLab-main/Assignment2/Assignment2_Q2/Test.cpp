#include "gtest/gtest.h"
#include "main.cpp"

TEST(normalbinarySearch, Checks) {
    int arr1[] = {2, 3, 4, 5};
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 2).normalBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 0);
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 3).normalBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 1);
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 4).normalBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 2);
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 5).normalBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 3);

    int arr2[] = {2, 3, 4, 5,6};
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 2).normalBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 0);
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 3).normalBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 1);
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 4).normalBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 2);
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 5).normalBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 3);
    
}

TEST(alphabinarySearch, checks) {
    int arr1[] = {2, 3, 4, 5};
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 2).alphaBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 0);
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 3).alphaBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 1);
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 4).alphaBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 2);
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 5).alphaBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 3);

    int arr2[] = {2, 3, 4, 5,6};
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 2).alphaBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 0);
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 3).alphaBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 1);
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 4).alphaBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 2);
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 5).alphaBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 3);
}



TEST(betabinarySearch, checks) {
    int arr1[] = {2, 3, 4, 5};
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 2).betaBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 0);
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 3).betaBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 1);
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 4).betaBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 2);
    ASSERT_EQ(BinarySearch(arr1, sizeof(arr1)/sizeof(int), 5).betaBinarySearch(0, sizeof(arr1)/sizeof(int) - 1), 3);

    int arr2[] = {2, 3, 4, 5,6};
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 2).betaBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 0);
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 3).betaBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 1);
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 4).betaBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 2);
    ASSERT_EQ(BinarySearch(arr2, sizeof(arr2)/sizeof(int), 5).betaBinarySearch(0, sizeof(arr2)/sizeof(int) - 1), 3);
}
