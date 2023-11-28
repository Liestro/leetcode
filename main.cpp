//
// Created by andre on 15.11.2023.
//

#include <iostream>

#include "solutions/MedianOfTwoSortedArrays.hpp"
#include "solutions/LongestPalindromicSubstring.hpp"
#include "solutions/ZigzagConversion.hpp"

int main()
{
    std::string inString("PAYPALISHIRING");
    std::string inString2("A");

    std::cout <<
    zigzag_conversion::Solution().convert(inString2, 2)
    << std::endl;

    return 0;
}