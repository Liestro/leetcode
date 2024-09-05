#pragma once

#include <algorithm>
#include <string>

namespace multiply_strings
{

using std::string;
using std::to_string;

class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), '0');

        int carry = 0;
        for (int i = 0; i < result.size() - 1; ++i) {
            result[result.size() - 1 - i] += carry % 10;
            result[result.size() - 2 - i] += carry / 10;
            carry = 0;

            for (int j = 0; j < num1.size(); ++j) {
                if (i - j > num2.size() - 1) continue;
                string multRes = to_string(
                    (num1[num1.size() - 1 - j] - 48) * 
                    (num2[num2.size() - 1 - i + j] - 48) + 
                    result[result.size() - i - 1] - 48);
                result[result.size() - 1 - i] = multRes.back();
                if (multRes.size() == 2)
                    carry += multRes.front() - 48;
            }
        }

        result[0] += carry;

        while (result.size() != 1 && result.front() == '0') {
            result.erase(0, 1);
        }

        //std::reverse(result.begin(), result.end());

        return result;
    }
};

bool test()
{
    return Solution().multiply("999", "999") == "998001";
}

}