#pragma once

#include <vector>
#include <algorithm>

namespace combination_sum_2
{

using std::vector;

class Solution {
public:
    template<class InputIt>
    void combinationSum(InputIt first, InputIt last, int target, vector<vector<int>>& result) {
        static vector<int> currentCombination;
        for (auto it = first; it != last; ++it) {
            if (*it == target) {
                result.push_back(currentCombination);
                result.back().push_back(target);
            }

            if (*it < target) {
                currentCombination.push_back(*it);
                combinationSum(it + 1, last, target - *it, result);
                currentCombination.pop_back();
            }

            while(it != last - 1 && *it == *(it + 1)) {
                ++it;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        std::sort(candidates.begin(), candidates.end());

        combinationSum(candidates.begin(), candidates.end(), target, result);

        return result;
    }
};

bool test()
{
    vector<int> input = {10,1,2,7,6,1,5};
    Solution().combinationSum2(input, 8);

    return true;
}

}