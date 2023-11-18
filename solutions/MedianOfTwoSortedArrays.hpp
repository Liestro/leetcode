//
// Created by andre on 17.11.2023.
//

#ifndef LEETCODE_MEDIANOFTWOSORTEDARRAYS_HPP
#define LEETCODE_MEDIANOFTWOSORTEDARRAYS_HPP

#include <vector>

namespace median_of_two_sorted_arrays {
    using std::vector;

    class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            if (nums1.size() > nums2.size())
                return findMedianSortedArrays(nums2, nums1);

            if (nums1.empty()) {
                if (nums2.size() % 2 == 1) {
                    return nums2[nums2.size() / 2];
                } else {
                    return (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2.;
                }
            }

            int overall_left_elements = (nums1.size() + nums2.size() + 1) / 2;
            std::pair<int, int> nums1_borders(0, nums1.size());

            do {
                int nums1_left_elements = (nums1_borders.second + nums1_borders.first + 1) / 2;
                int nums2_left_elements = overall_left_elements - nums1_left_elements;

                int nums1_left_max =
                        (nums1_left_elements - 1) >= 0 ? nums1[nums1_left_elements - 1] : INT_MIN;
                int nums1_right_min = nums1_left_elements < nums1.size() ? nums1[nums1_left_elements] : INT_MAX;

                int nums2_left_max = nums2_left_elements - 1 >= 0 ? nums2[nums2_left_elements - 1] : INT_MIN;
                int nums2_right_min = nums2_left_elements < nums2.size() ? nums2[nums2_left_elements] : INT_MAX;

                if (nums1_left_max <= nums2_right_min && nums2_left_max <= nums1_right_min) {
                    if ((nums1.size() + nums2.size()) % 2 == 1) {
                        return std::max(nums1_left_max, nums2_left_max);
                    } else {
                        return (std::min(nums1_right_min, nums2_right_min) +
                                std::max(nums1_left_max, nums2_left_max)) / 2.;
                    }
                } else if (nums1_left_max > nums2_right_min) {
                    nums1_borders.second = (nums1_borders.second + nums1_borders.first) / 2;
                } else {
                    nums1_borders.first = nums1_left_elements;
                }
            }
            while (nums1_borders.second >= nums1_borders.first);

            return 0;
        }
    };
}

#endif //LEETCODE_MEDIANOFTWOSORTEDARRAYS_HPP
