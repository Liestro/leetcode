//
// Created by andre on 28.11.2023.
//

#ifndef LEETCODE_ZIGZAGCONVERSION_HPP
#define LEETCODE_ZIGZAGCONVERSION_HPP

#include <string>
#include <algorithm>

namespace zigzag_conversion
{
    using std::string;

    class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1)
                return s;

            int numColumns = (s.size() + 1) / 2;
            int clusterSize = 2 * (numRows - 1);
            string result(numColumns * numRows, ' ');

            for (int i = 0; i < s.size(); ++i) {
                int inClusterCount = i % clusterSize;
                int rowAdding = inClusterCount / numRows * (inClusterCount % numRows + 1) * 2;
                int colAdding = inClusterCount / numRows * (inClusterCount % numRows + 1);
                int resultRow = inClusterCount - rowAdding;
                int resultColumn = (i / clusterSize) * (numRows - 1) + colAdding;

                int resultPos = resultRow * numColumns + resultColumn;
                result[resultPos] = s[i];
            }

            result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
            return result;
        }
    };
}

#endif //LEETCODE_ZIGZAGCONVERSION_HPP
