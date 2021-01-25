//
// Created by Михаил Степанов on 25.01.2021.
//

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    bool first_it = true;
    os << '[';
    for (const auto &val: vec) {
        if (first_it) {
            first_it = false;
            os << val;
            continue;
        }
        os << ", " << val;
    }
    os << ']';
    return os;
}


using Board = vector<vector<int>>;

void candyCrush(Board &board)
{
    if (board.empty()) { return; }
    int C = board[0].size();
    int R = board.size();

    bool no_crushes = true;

    // Check rows
    for (int c = 0; c < C; c++) {
        for (int r = 0; r < R - 2; r++) {
            int val = board[r + 2][c];
            if (val > 0 && abs(board[r][c]) == abs(board[r + 1][c]) == abs(val)) {
                no_crushes = false;
                board[r][c] = -abs(val);
                board[r + 1][c] = -abs(val);
                board[r + 2][c] = -abs(val);
            }
        }
    }

    // Check columns
    for (int c = 0; c < C - 2; c++) {
        for (int r = 0; r < R; r++) {
            int val = board[r][c + 2];
            if (val > 0 && abs(board[r][c]) == abs(board[r][c + 1]) == abs(val)) {
                no_crushes = false;
                board[r][c] = -abs(val);
                board[r][c + 1] = -abs(val);
                board[r][c + 2] = -abs(val);
            }
        }
    }

    // Drop
    for (int c = 0; c < C; c++) {
        int ptr = R - 1;
        for (int r = ptr; r >= 0; r--) {
            if (board[r][c] > 0) { board[ptr--][c] = board[r][c]; }
        }
        for (int i = ptr; i >= 0; i--) {
            board[i][c] = 0;
        }
    }

    if (no_crushes) { return; }

    return candyCrush(board);
}


int main()
{
    Board board{{1, 1, 1},
                {1, 1, 1},
                {1, 1, 1}};
    cout << board << endl;
    candyCrush(board);
    cout << board << endl;

    board = {{2, 3, 4},
             {1, 1, 1},
             {1, 1, 1}};
    cout << board << endl;
    candyCrush(board);
    cout << board << endl;

    board = {{1, 3, 4},
             {1, 5, 6},
             {1, 1, 1}};
    cout << board << endl;
    candyCrush(board);
    cout << board << endl;
}