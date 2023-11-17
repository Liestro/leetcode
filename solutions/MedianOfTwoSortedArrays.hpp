//
// Created by andre on 17.11.2023.
//

#ifndef LEETCODE_MEDIANOFTWOSORTEDARRAYS_HPP
#define LEETCODE_MEDIANOFTWOSORTEDARRAYS_HPP

#include <vector>

namespace median_of_two_sorted_arrays {
    using std::vector;

    class Solution {
    private:
        double median_of(vector<int>& vec, std::pair<unsigned, unsigned> vec_bounds) {
            size_t vec_size = vec_bounds.second - vec_bounds.first;
            if (vec_size % 2 == 1)
                return vec[vec_bounds.first + vec_size / 2];
            else
                return (vec[vec_bounds.first +  vec_size / 2] + vec[(vec_bounds.first +  vec_size - 1) / 2]) / 2.;
        }

        double findMedianRecurse(vector<int>& nums1,
                                 vector<int>& nums2,
                                 std::pair<unsigned, unsigned> nums1_bounds,
                                 std::pair<unsigned, unsigned> nums2_bounds)
        {
            unsigned nums1_size = nums1_bounds.second - nums1_bounds.first;
            unsigned nums2_size = nums2_bounds.second - nums2_bounds.first;

            double nums1_median = nums1_size == 0 ? 0 : median_of(nums1, nums1_bounds);
            double nums2_median = nums2_size == 0 ? 0 : median_of(nums2, nums2_bounds);

            if (nums1_size == 0) return nums2_median;
            if (nums2_size == 0) return nums1_median;

            if (nums2_size == 1 && nums1_size == 1)
                return (nums1_median + nums2_median) / 2.;

            if (nums1_median == nums2_median) return nums1_median;

            unsigned bounds_correction = std::max( std::min(nums1_size, nums2_size) / 2, unsigned(1));
            if (nums1_median < nums2_median) {
                nums1_bounds.first += bounds_correction;
                nums2_bounds.second -= bounds_correction;
            } else {
                nums2_bounds.first += bounds_correction;
                nums1_bounds.second -= bounds_correction;
            }

            return findMedianRecurse(nums1, nums2, nums1_bounds, nums2_bounds);
        }

    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            return findMedianRecurse(nums1,
                                     nums2,
                                     {0, nums1.size()},
                                     {0, nums2.size()});
        }
    };
}

#endif //LEETCODE_MEDIANOFTWOSORTEDARRAYS_HPP
