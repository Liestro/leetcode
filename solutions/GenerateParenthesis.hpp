#pragma once
#include <vector>
#include <string>

namespace generate_parenthesis {
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        dfs(0, 0, "", n, res);
        return res;        
    }

private:
    void dfs(int openP, int closeP, std::string s, int n, std::vector<std::string>& res) {
        if (openP == closeP && openP + closeP == n * 2) {
            res.push_back(s);
            return;
        }

        if (openP < n) {
            dfs(openP + 1, closeP, s + "(", n, res);
        }

        if (closeP < openP) {
            dfs(openP, closeP + 1, s + ")", n, res);
        }
    }
};

bool test()
{
    Solution sol;
    for (int i = 2; i <= 8; ++i) {
        sol.generateParenthesis(i);
    }
    return true;
}

}