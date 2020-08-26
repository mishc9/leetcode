//
// Created by Михаил Степанов on 09.08.2020.
//

#include <vector>
#include <iostream>
#include <queue>


using namespace std;

using Grid = vector<vector<int>>;

enum States {
    empty = 0, fresh = 1, rotten = 2
};

struct Point {
    int x;
    int y;
};


class Solution {

public:
    int orangesRotting(Grid &grid) {
        int freshCount = 0;
        if (grid.empty()) { return 0; }
        int minutesPassed = 0;
        // Count fresh oranges
        for (const vector<int> &row : grid) {
            for (auto val : row) {
                if (val == fresh) { freshCount++; }
            }
        }
        queue<Point> rottenPoints;
        int max_y = grid.size();
        int max_x = grid[0].size();

        // Push rotten oranges into the queue
        for (int y = 0; y < max_y; y++) {
            for (int x = 0; x < max_x; x++) {
                if (grid[y][x] == rotten) { rottenPoints.push({x, y}); }
            }
        }
        // Count a size of queue on n-th minute;
        // If there are no oranges have been rotten during previous minute or were rotten initially, break.
        int rottenCount = rottenPoints.size();
        while (rottenCount) {
            // For all rotten during previous step, find their fresh neighbours, 'rot' them and add newly-rotten
            // to the queue.
            for (int i = 0; i < rottenCount; i++) {
                auto[x, y] = rottenPoints.front();
                rottenPoints.pop();
                // Find fresh neighbours
                for (auto[dx, dy] : dxdy) {
                    // Boundary check
                    if (x + dx >= 0 && x + dx < max_x && y + dy >= 0 && y + dy < max_y) {
                        if (grid[y + dy][x + dx] == fresh) {
                            rottenPoints.push({x + dx, y + dy});
                            grid[y + dy][x + dx] = rotten;
                            // Decrease fresh count. If fresh count > 0 after the end of the while loop, there are
                            // exists "unreachable" fresh oranges; hence, return -1
                            freshCount--;
                        }
                    }
                }
            }
            // Count newly-rotten during n-th minute
            rottenCount = rottenPoints.size();
            if (rottenCount) { minutesPassed++; } // if there's no newly rotten, don't count this minute
        }
        return freshCount == 0 ? minutesPassed : -1; // Check if there are still any fresh oranges
    }

private:
    vector<Point> dxdy = {{-1, 0},
                          {1,  0},
                          {0,  -1},
                          {0,  1}};
};


int main() {
    Solution solution;
    Grid gridSmall{{1, 2}};
    cout << solution.orangesRotting(gridSmall) << endl;
    Grid grid{{2, 1, 1},
              {1, 1, 0},
              {0, 1, 1}};
    cout << solution.orangesRotting(grid) << endl;
    Grid gridEmpty{};
    cout << solution.orangesRotting(gridEmpty) << endl;
    return 0;
}
