#include <vector>

namespace permite_unique
{

using std::vector;

class Solution {
public:
    vector<vector<int>> permuteUnique(const vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 1) {
            result.push_back(nums);
            return result;
        }

        for(auto currentPerm : permuteUnique(vector(nums.begin() + 1, nums.end()))) {
            currentPerm.push_back(nums.front());

            result.push_back(currentPerm);
            for (int i = currentPerm.size() - 1; i > 0; --i) {
                int k = i - 1;
                while(currentPerm[k] == currentPerm[i]) {
                    k--;
                }
                std::swap(currentPerm[i], currentPerm[k]);
                i = k + 1;
                result.push_back(currentPerm);
            }
        }

        return result;
    }
};

bool test()
{
    Solution().permuteUnique({1, 1, 2});

    return true;
}

}