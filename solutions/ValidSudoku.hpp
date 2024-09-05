#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>

namespace valid_sudoku 
{

using std::vector;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<char, std::vector<std::pair<int, int>>> storage;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                
                auto & positions = storage[board[i][j]];

                auto it = std::find_if(positions.begin(), positions.end(), [i, j](std::pair<int, int> ip){
                    return ip.first == i 
                            || ip.second == j 
                            || i / 3 == ip.first / 3 && j / 3 == ip.second / 3;
                });

                if (it != positions.end()) {
                    return false;
                } else {
                    positions.push_back({i, j});
                }
            } 
        }

        return true;
    }
};

bool test()
{
    Solution sol;

    vector<vector<char>> input;
    input.push_back(vector({'5','3','.','.','7','.','.','.','.'}));
    input.push_back(vector({'6','.','.','1','9','5','.','.','.'}));
    input.push_back(vector({'.','9','8','.','.','.','.','6','.'}));
    input.push_back(vector({'8','.','.','.','6','.','.','.','3'}));
    input.push_back(vector({'4','.','.','8','.','3','.','.','1'}));
    input.push_back(vector({'7','.','.','.','2','.','.','.','6'}));
    input.push_back(vector({'.','6','.','.','.','.','2','8','.'}));
    input.push_back(vector({'.','.','.','4','1','9','.','.','5'}));
    input.push_back(vector({'.','.','.','.','8','.','.','7','9'}));

    sol.isValidSudoku(input);

    return true;
}

}