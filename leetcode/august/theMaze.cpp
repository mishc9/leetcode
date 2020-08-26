//
// Created by Михаил Степанов on 22.08.2020.
//

#include <vector>
#include <queue>

using namespace std;


using Maze = vector<vector<int>>;
using Visited = vector<vector<bool>>;
using Point = vector<int>;


class Solution
{
public:
    bool hasPath(Maze &maze, Point &start, Point &destination)
    {
        int row = maze.size();
        if (!row) return false;
        int col = maze[0].size();
        vector<vector<int>> directions = {{0,  1},
                                          {1,  0},

                                          {0,  -1},
                                          {-1, 0}};
        queue<tuple<int, int>> queue;
        queue.emplace(start[0], start[1]);
        maze[start[0]][start[1]] = -1;
        while (!queue.empty())
        {
            auto[r, c] = queue.front();
            queue.pop();
            for (auto &next : directions)
            {
                int next_r = r;
                int next_c = c;
                while (next_r + next[0] >= 0 && next_c + next[1] >= 0 && next_r + next[0] < row
                       && next_c + next[1] < col && maze[next_r + next[0]][next_c + next[1]] <= 0)
                {
                    next_r += next[0];
                    next_c += next[1];
                }
                if (next_r == destination[0] && next_c == destination[1]) { return true; }
                if (!maze[next_r][next_c])
                {
                    queue.emplace(next_r, next_c);
                    maze[r][c] = -1; //mark as visited if its 0
                }
            }
        }
        return false;
    }
};


class _Solution
// Fixme: contains a bug
{
public:
    bool hasPath(Maze &maze, const Point &start, const Point &destination)
    {
        Visited visited;
        for (int i = 0; i < maze.size(); i++)
        {
            vector<bool> row(maze.size(), false);
            visited.emplace_back(row);
        }
        return dfs(maze, start, destination, visited);
    }

    bool dfs(Maze &maze, const Point &start, const Point &destination, Visited &visited)
    {
        if (visited[start[0]][start[1]])
        {
            return false;
        }
        if (start[0] == destination[0] && start[1] == destination[1])
        {
            return true;
        }
        visited[start[0]][start[1]] = true;
        int r = start[1] + 1, l = start[1] - 1, u = start[0] - 1, d = start[0] + 1;
        while (r < maze[0].size() && maze[start[0]][r] == 0) // right
            r++;
        if (dfs(maze, {start[0], r - 1}, destination, visited))
            return true;
        while (l >= 0 && maze[start[0]][l] == 0) //left
            l--;
        if (dfs(maze, {start[0], l + 1}, destination, visited))
            return true;
        while (u >= 0 && maze[u][start[1]] == 0) //up
            u--;
        if (dfs(maze, {u + 1, start[1]}, destination, visited))
            return true;
        while (d < maze.size() && maze[d][start[1]] == 0) //down
            d++;
        if (dfs(maze, {d - 1, start[1]}, destination, visited))
            return true;
        return false;
    }
};

