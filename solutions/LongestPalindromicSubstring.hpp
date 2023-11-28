//
// Created by andre on 28.11.2023.
//

#ifndef LEETCODE_LONGESTPALINDROMICSUBSTRING_HPP
#define LEETCODE_LONGESTPALINDROMICSUBSTRING_HPP

#include <string>

namespace longest_palindromic_substring {
using std::string;

class Solution {
private:
    bool is_substring_polindromic(int start, int finish, const string& s) {
        for (int i = start; i < finish; ++i) {
            if (s[i] != s[finish - i + start])
                return false;
        }

        return true;
    }

public:
    string longestPalindrome(string s) {
        string result({s[0]});

        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + result.size(); j < s.size(); ++j) {
                if (is_substring_polindromic(i, j, s))
                    result = s.substr(i, j - i + 1);
            }
        }

        return result;
    }
};
}

#endif //LEETCODE_LONGESTPALINDROMICSUBSTRING_HPP
