#pragma once

#include <string>

namespace count_and_say
{

using std::string;

class Solution {
public:
    string rle(const string& in) {
        string result = "";
        char number = in.front();
        int repeating = 1;

        for (auto it = in.begin() + 1; it != in.end(); ++it) {
            if (*it == number) {
                repeating++;
            } else {
                result += std::to_string(repeating);
                result += number;
                number = *it;
                repeating = 1;
            }
        }

        result += std::to_string(repeating);
        result += number;

        return result;
    }

    string countAndSay(int n) {
        if (n == 1) return "1";

        return rle(countAndSay(n - 1));
    }
};

bool test()
{
    return Solution().countAndSay(4) == "1211";

    return true;
}

}