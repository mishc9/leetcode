//
// Created by Михаил Степанов on 07.07.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                if (j == 0 || grid[i][j - 1] == 0) ++res;
                if (i == 0 || grid[i - 1][j] == 0) ++res;
                if (j == n - 1 || grid[i][j + 1] == 0) ++res;
                if (i == m - 1 || grid[i + 1][j] == 0) ++res;
            }
        }
        return res;
    }

    int slowMessyIslandPerimeter(vector<vector<int>> &grid) {
        // but my own
        visited.clear();
        neighbours.clear();
        int x_start, y_start;
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            if (!neighbours.empty()) {
                break;
            }
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    neighbours.emplace_back(pair(i, j));
                }
            }
        }
        while (!neighbours.empty()) {
            pair nextPoint = neighbours.back();
            neighbours.pop_back();
            if (isVisited(nextPoint)) {
                continue;
            }
            int n_neighbours = visit(nextPoint, grid);
            perimeter += (4 - n_neighbours);
            visited.emplace_back(nextPoint);
        }
        return perimeter;
    }

private:
    vector<pair<int, int>> visited;
    vector<pair<int, int>> neighbours;

    int visit(pair<int, int> point, const vector<vector<int>> &grid) {
        int x_size = grid.size();
        int y_size;
        int n_neighbours = 0;
        if (x_size) {
            y_size = grid[0].size();
        } else {
            return n_neighbours;
        }

        int x = point.first;
        int y = point.second;
        pair<int, int> neighbour;
        if (x - 1 >= 0) {
            neighbour = {x - 1, y};
            addNeighbour(n_neighbours, neighbour, grid);
        }
        if (x + 1 < x_size) {
            neighbour = {x + 1, y};
            addNeighbour(n_neighbours, neighbour, grid);
        }
        if (y - 1 >= 0) {
            neighbour = {x, y - 1};
            addNeighbour(n_neighbours, neighbour, grid);
        }
        if (y + 1 < y_size) {
            neighbour = {x, y + 1};
            addNeighbour(n_neighbours, neighbour, grid);
        }

        return n_neighbours;
    }

    void addNeighbour(int &n_neighbours, pair<int, int> neighbour, const vector<vector<int>> &grid) {
        if (grid[neighbour.first][neighbour.second]) {
            n_neighbours++;
        }
        if (!isVisited(neighbour) and grid[neighbour.first][neighbour.second]) {
            neighbours.emplace_back(neighbour);
        }
    }

    bool isVisited(pair<int, int> point) {
        return count(visited.begin(), visited.end(), point);
    }

};

int main() {
    Solution sol;
    vector<vector<int>> buggy{{1, 0}};
    cout << sol.islandPerimeter(buggy) << endl;
    vector<vector<int>> island{{0, 1, 0, 0},
                               {1, 1, 1, 0},
                               {0, 1, 0, 0},
                               {1, 1, 0, 0}};
    cout << sol.islandPerimeter(island) << endl;
    vector<vector<int>> island2{{0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0}};
    cout << sol.islandPerimeter(island2) << endl;

    return 0;
}