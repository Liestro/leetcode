#include <algorithm>
#include <vector>
#include <iostream>

namespace next_permutation{

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        auto it = nums.rbegin();
        for (;it != nums.rend(); ++it) {
            //auto lb = nums.rbegin();
            //for (; lb != it && *lb <= *it; ++lb);
            auto lb = std::upper_bound(it.base(), nums.end(), *it);

            if (lb != nums.end()) {
                std::swap(*lb, *it);
                break;
            }
        }

        std::reverse(nums.rbegin(), it);
    }
};

bool test()
{
    Solution sol;

    std::vector<int> sample({4,2,0,2,3,2,0});
    sol.nextPermutation({sample});

    return true;
}

}