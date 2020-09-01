//
// Created by Михаил Степанов on 29.08.2020.
//

#include <unordered_set>
#include <stack>

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
    struct pair_hash
    {
        inline std::size_t operator()(const std::pair<int, int> &v) const
        {
            return v.first * 31 + v.second;
        }
    };

public:
    unordered_set<pair<int, int>, pair_hash> visited;

    void cleanTrack(Robot &robot, int dir, int x, int y)
    {
        pair<int, int> k = {x, y};  // to_string(x) + "," + to_string(y);
        if (visited.count(k)) { return; }
        visited.insert(k);
        robot.clean();

        for (int i = 0; i < 4; i++) {
            if (robot.move()) {
                if (dir == 0) { cleanTrack(robot, dir, x + 1, y); }
                else if (dir == 1) { cleanTrack(robot, dir, x, y + 1); }
                else if (dir == 2) { cleanTrack(robot, dir, x - 1, y); }
                else { cleanTrack(robot, dir, x, y - 1); }
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnLeft();
                dir = (dir + 1) % 4;
            } else {
                robot.turnRight();
                dir = (dir + 1) % 4;
            }
        }
    }

    void cleanRoom(Robot &robot)
    {
        cleanTrack(robot, 0, 0, 0);
    }
};


int main()
{
    Solution solution;

    return 0;
}