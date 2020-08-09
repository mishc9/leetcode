//
// Created by Михаил Степанов on 09.08.2020.
//

#include <unordered_set>
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
        int turns = 0;
        for (const vector<int> &row : grid) { for (auto val : row) { if (val == fresh) { freshCount++; }}}
        queue<Point> rottenPoints;
        int max_y = grid.size();
        int max_x = grid[0].size();

        for (int y = 0; y < max_y; y++) {
            for (int x = 0; x < max_x; x++) {
                if (grid[y][x] == rotten) { rottenPoints.push({x, y}); }
            }
        }
        int rottenCount = rottenPoints.size();

        while (rottenCount) {
            for (int i = 0; i < rottenCount; i++) {
                Point point = rottenPoints.front();
                rottenPoints.pop();
                for (auto point: makeItRotten(grid, point, max_x, max_y)) {
                    rottenPoints.push(point);
                    freshCount--;
                }
            }
            rottenCount = rottenPoints.size();
            if (rottenCount) { turns++; }
        }
        return freshCount == 0 ? turns : -1;
    }

private:
    vector<Point> makeItRotten(Grid &grid, Point &point, int max_x, int max_y) {
        vector<Point> result;
        auto[x, y] = point;
        vector<Point> shifts = {{-1, 0},
                                {1,  0},
                                {0,  -1},
                                {0,  1}};
        for (auto[dx, dy] : shifts) {
            if (x + dx >= 0 && x + dx < max_x && y + dy >= 0 && y + dy < max_y) {
                if (grid[y + dy][x + dx] == fresh) {
                    Point thisPoint = {x + dx, y + dy};
                    result.emplace_back(thisPoint);
                    grid[y + dy][x + dx] = rotten;
                }
            }
        }
        return result;
    }
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
