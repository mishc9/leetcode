//
// Created by Михаил Степанов on 1/16/21.
//

#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;
using Board = vector<vector<int>>;

class Solution
{
public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board)
    {
        vector<vector<pair<int, int>>> cache;
        while (findCrushPos(board, cache)) { update(board, cache); }
        return board;
    }

private:
    Board directions = {{0, 1},
                        {1, 0}}; // right, down

    bool findCrushPos(Board &board, vector<vector<pair<int, int>>> &cache)
    {
        int num_rows = board.size();
        int num_cols = board[0].size();
        for (int row = 0; row < num_rows; ++row) {
            for (int col = 0; col < num_cols; ++col) {
                if (board[row][col] == 0) {
                    continue;
                } else {
                    for (vector<int> direction : directions) {
                        // I am sure redundancy happens here
                        vector<pair<int, int>> temp;
                        int cur_row = row, cur_col = col;
                        while (cur_row < num_rows && cur_col < num_cols && board[cur_row][cur_col] == board[row][col]) {
                            temp.push_back(make_pair(cur_row, cur_col));
                            cur_row += direction[0];
                            cur_col += direction[1];
                        }
                        if (temp.size() >= 3) {
                            cache.push_back(temp);
                        }
                    }
                }
            }
        }
        return cache.size() > 0;
    }

    void update(Board &board, vector<vector<pair<int, int>>> &cache)
    {
        // set all crush pos to -1
        for (vector<pair<int, int>> temp : cache) {
            for (pair<int, int> p : temp) {
                board[p.first][p.second] = -1;
            }
        }
        int num_rows = board.size(), num_cols = board[0].size();

        // move all -1 and fill the rest with 0
        // similar to question 283 move all zeros
        for (int col = 0; col < num_cols; ++col) {
            int down = num_rows - 1;
            for (int top = down; top >= 0; --top) {
                if (board[top][col] != -1) {
                    board[down--][col] = board[top][col];
                }
            }
            for (int i = down; i >= 0; --i) {
                board[i][col] = 0;
            }
        }

        // clean the cache which take O(N), redundancy
        cache.clear();
    }
};
