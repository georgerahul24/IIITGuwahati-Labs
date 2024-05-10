#include "gtest/gtest.h"
#include "main.cpp"

TEST(divideAndConquer, blahblahblah) {
    int arr1[] = {1, 100, 4, 30, 9, 76};
    ASSERT_EQ(Q1(arr1, sizeof(arr1) / sizeof(int)).find_max(0, sizeof(arr1) / sizeof(int) - 1), 100);
    Max_Min *s1 = Q1(arr1, sizeof(arr1) / sizeof(int)).findMaxMin(0, sizeof(arr1) / sizeof(int) - 1);
    ASSERT_EQ(s1->max, 100);
    ASSERT_EQ(s1->min, 1);
    Max_Min *s1_1 = Q1(arr1, sizeof(arr1) / sizeof(int)).findMaxAndSecondMax(0, sizeof(arr1) / sizeof(int) - 1);
    ASSERT_EQ(s1_1->max, 100);
    ASSERT_EQ(s1_1->min, 76);
    
    
    int arr2[] = {34, 268, -2, 11, 1000};
    ASSERT_EQ(Q1(arr2, sizeof(arr2) / sizeof(int)).find_max(0, sizeof(arr2) / sizeof(int) - 1), 1000);
    Max_Min *s2 = Q1(arr2, sizeof(arr2) / sizeof(int)).findMaxMin(0, sizeof(arr2) / sizeof(int) - 1);
    ASSERT_EQ(s2->max, 1000);
    ASSERT_EQ(s2->min, -2);
    Max_Min *s2_1 = Q1(arr2, sizeof(arr2) / sizeof(int)).findMaxAndSecondMax(0, sizeof(arr2) / sizeof(int) - 1);
    ASSERT_EQ(s2_1->max, 1000);
    ASSERT_EQ(s2_1->min, 268);


    int arr3[] = {288, 4, 29, 90, 80, 27};
    ASSERT_EQ(Q1(arr3, sizeof(arr3) / sizeof(int)).find_max(0, sizeof(arr3) / sizeof(int) - 1), 288);
    Max_Min *s3 = Q1(arr3, sizeof(arr3) / sizeof(int)).findMaxMin(0, sizeof(arr3) / sizeof(int) - 1);
    ASSERT_EQ(s3->max, 288);
    ASSERT_EQ(s3->min, 4);
    Max_Min *s3_1 = Q1(arr3, sizeof(arr3) / sizeof(int)).findMaxAndSecondMax(0, sizeof(arr3) / sizeof(int) - 1);
    ASSERT_EQ(s3_1->max, 288);
    ASSERT_EQ(s3_1->min, 90);


    int arr4[] = {288, 4, 29, 900, 80, 27};
    ASSERT_EQ(Q1(arr4, sizeof(arr4) / sizeof(int)).find_max(0, sizeof(arr4) / sizeof(int) - 1), 900);
    Max_Min *s4 = Q1(arr4, sizeof(arr4) / sizeof(int)).findMaxMin(0, sizeof(arr4) / sizeof(int) - 1);
    ASSERT_EQ(s4->max, 900);
    ASSERT_EQ(s4->min, 4);
    Max_Min *s4_1 = Q1(arr4, sizeof(arr4) / sizeof(int)).findMaxAndSecondMax(0, sizeof(arr4) / sizeof(int) - 1);
    ASSERT_EQ(s4_1->max, 900);
    ASSERT_EQ(s4_1->min, 288);

}