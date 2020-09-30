//
// Created by Михаил Степанов on 28.09.2020.
//

#include <unordered_set>

class Robot
{
public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();

    void turnRight();

    // Clean the current cell.
    void clean();
};

using namespace std;

class Solution
{
    struct pair_hash
    {
        inline size_t operator()(const pair<int, int> p) const
        {
            return p.first * 31 + p.second;
        }
    };

public:
    unordered_set<pair<int, int>, pair_hash> visited;

    void cleanRoom(Robot &robot)
    {
        dfs(robot, 0, 0, 0);
    }

    void dfs(Robot &robot, int direction, int x, int y)
    {
        pair<int, int> k = {x, y};
        if (visited.count(k)) { return; }
        visited.insert(k);
        robot.clean();

        for (int i = 0; i < 4; i++) {
            if (robot.move()) {
                if (direction == 0) { dfs(robot, direction, x + 1, y); }
                else if (direction == 1) { dfs(robot, direction, x, y + 1); }
                else if (direction == 2) { dfs(robot, direction, x - 1, y); }
                else { dfs(robot, direction, x, y - 1); }
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnLeft();
                direction = (direction + 1) % 4;
            } else {
                robot.turnRight();
                direction = (direction + 1) % 4;
            }
        }
    }
};
