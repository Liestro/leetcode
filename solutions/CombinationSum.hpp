#pragma once
#include <vector>

namespace combination_sum
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
                combinationSum(it, last, target - *it, result);
                currentCombination.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        combinationSum(candidates.begin(), candidates.end(), target, result);

        return result;
    }
};

bool test()
{
    vector<int> input = {2, 3, 6, 7};
    Solution().combinationSum(input, 7);

    return true;
}

}