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
        double median_of(vector<int>& vec) {
            return (vec[vec.size() / 2] + vec[(vec.size() - 1) / 2]) / 2.;
        }

    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            if (nums1.empty()) return median_of(nums2);
            if (nums2.empty()) return median_of(nums1);

            unsigned overall_median_index = (nums1.size() + nums2.size() - 1) / 2;
            std::pair<unsigned, unsigned> nums1_bounds(0, nums1.size());
            std::pair<unsigned, unsigned> nums2_bounds(0, nums2.size());

            unsigned nums1_pos = (nums1.size() - 1) / 2;
            unsigned nums2_pos = (std::lower_bound(nums2.begin(), nums2.end(), median_of(nums1))
                                   - nums2.begin());
            unsigned pos = nums1_pos + nums2_pos + 1;

            if (pos == overall_median_index) {
                double first_median_element = nums1[nums1_pos] < nums2[nums2_pos]
                                              ? std::min(nums1[nums1_pos + 1], nums2[nums2_pos])
                                              : std::min(nums1[nums1_pos], nums2[nums2_pos + 1]);

                if ((nums1.size() + nums2.size() - 1) % 2 == 0)
                    return first_median_element;
            }

            return 0;
        }
    };
}

#endif //LEETCODE_MEDIANOFTWOSORTEDARRAYS_HPP
