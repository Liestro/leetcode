//
// Created by andre on 15.11.2023.
//

#ifndef LEETCODE_TWOSUM_HPP
#define LEETCODE_TWOSUM_HPP

#include <vector>
#include <unordered_map>

namespace two_sum {
    using std::vector;
    using std::unordered_map;

    class Solution {
    public:
        vector<int> twoSumSimple(vector<int>& nums, int target) {
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    if (nums[i] + nums[j] == target) {
                        return {i, j};
                    }
                }
            }

            return {-1, -1};
        }

        vector<int> twoSumHashTable(vector<int>& nums, int target) {
            unordered_map<int, int> indexesHashTable;

            for (int i = 0; i < nums.size(); ++i) {
                int complement = target - nums[i];
                if (indexesHashTable.contains(complement))
                    return {indexesHashTable.at(complement), i};

                indexesHashTable[nums[i]] = i;
            }

            return {};
        }
    };
}

#endif //LEETCODE_TWOSUM_HPP
