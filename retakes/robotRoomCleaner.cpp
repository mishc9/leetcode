//
// Created by Михаил Степанов on 29.09.2020.
//

#include <unordered_set>

using namespace std;

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

class Solution
{
    struct pairHash
    {
        inline size_t operator()(const pair<int, int> &p) const
        {
            return p.first * 31 + p.second;
        }
    };

public:
    unordered_set<pair<int, int>, pairHash> visited;

    void cleanRoom(Robot &robot)
    {
        cleanTrack(robot, 0, 0, 0);
    }

    void cleanTrack(Robot &robot, int dir, int x, int y)
    {
        if (visited.count({x, y}) != 0) { return; }
        robot.clean();
        visited.insert({x, y});
        for (int i = 0; i < 4; i++) {
            if (robot.move()) {
                robot = cleanNextCell(robot, dir, x, y);
                goBackAndTurn(robot);
            } else {
                robot.turnRight();
            }
            dir = updateDirection(dir);
        }
    }

private:
    Robot &cleanNextCell(Robot &robot, int dir, int x, int y)
    {
        if (dir == 0) { cleanTrack(robot, dir, x + 1, y); }
        else if (dir == 1) { cleanTrack(robot, dir, x, y + 1); }
        else if (dir == 2) { cleanTrack(robot, dir, x - 1, y); }
        else { cleanTrack(robot, dir, x, y - 1); }
        return robot;
    }

    static void goBackAndTurn(Robot &robot)
    {
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
    }

    static int updateDirection(int dir)
    {
        return (dir + 1) % 4;
    }
};
