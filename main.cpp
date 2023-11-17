//
// Created by andre on 15.11.2023.
//

#include <iostream>

#include "solutions/MedianOfTwoSortedArrays.hpp"

int main()
{
    std::vector<int> nums1({1, 2});
    std::vector<int> nums2({-1, 3});
    std::cout <<
    median_of_two_sorted_arrays::Solution().findMedianSortedArrays(nums1, nums2)
    << std::endl;

    return 0;
}