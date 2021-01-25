//
// Created by Михаил Степанов on 1/23/21.
//

#include <vector>
#include <iostream>

using namespace std;

void move_zeros(vector<int> &vec)
{
    int leftPrt = 0, rightPtr;

    for (rightPtr = leftPrt; rightPtr < vec.size(); rightPtr++) {
        if (vec[rightPtr] != 0) {
            vec[leftPrt++] = vec[rightPtr];
        }
    }
    for (int i = leftPrt; i < vec.size(); i++) {
        vec[i] = 0;
    }
}

using Board = vector<vector<int>>;


void candyCrush(Board &board)
// FIXME: Broken
{
    int height = board.size();
    int width = board[0].size();
    bool something_has_changed = false;
    for (int i = 0; i < height; i++) {
        vector<int> row = board[i];
        for (int j = 2; j < width; j++) {
            if (row[i - 2] == row[i - 1] == row[i - 0]) {
                something_has_changed = true;
                for (int k = 0; k < 3; k++) {
                    if (row[i - k] > 0) {
                        row[i - k] *= -1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < width; i++) {
        for (int j = 2; j < height; j++) {
            if (board[j - 2][i] == board[j - 1][i] == board[j][i]) {
                something_has_changed = true;
                for (int k = 0; k < 3; k++) {
                    if (board[j - k][i] > 0) {
                        board[j - k][i] *= -1;
                    }
                }
            }
        }
    }

    if (!something_has_changed) {
        return;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] < 0) {
                board[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < width; j++) {
        int ptr = height - 1;
        for (int i = ptr; i >= 0; i--) {
            if (board[i][j] != 0) { board[ptr--][j] = board[i][j]; }
        }
        for (int k = ptr; k >= 0; k--) {
            board[k][j] = 0;
        }
    }

    candyCrush(board);
}


template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    bool first = true;
    os << '[';
    for (const auto &val: vec) {
        if (first) {
            os << val;
            first = false;
            continue;
        }
        os << ", ";
        os << val;
    }
    os << ']';
    return os;
}

int main()
{
    vector<int> values{1, 2, 3, 0, 0, 4, 5, 0, 0, 7, 8, 9, 0, 0};
    move_zeros(values);
    cout << values << endl;


    Board board{{1, 1, 1},
                {1, 1, 1,},
                {1, 1, 1}};
    candyCrush(board);
    cout << board << endl;
    board = {{4, 5, 6},
             {1, 1, 1,},
             {1, 1, 1}};
    candyCrush(board);
    cout << board << endl;
}
