//
// Created by Михаил Степанов on 07.10.2020.
//

#include <unordered_set>
#include <vector>

using namespace std;


class Robot
{
public:
    bool move();

    void turnLeft();

    void turnRight();

    void clean();
};

class Pair
{
    int x, y;
public:
    int getX() const { return x; }

    int getY() const { return y; }

    Pair(int x, int y) : x(x), y(y) {}

    Pair goUp() const { return Pair(x, y + 1); }

    Pair goDown() const { return Pair(x, y - 1); }

    Pair goLeft() const { return Pair(x + 1, y); }

    Pair goRight() const { return Pair(x - 1, y); }
};

class Solution
{
    struct pairHash
    {
        inline size_t operator()(const Pair &p) const
        {
            return p.getX() * 31 + p.getY();
        }
    };

    unordered_set<Pair, pairHash> visited;
public:
    void cleanRoom(Robot &robot)
    {
        cleanTrack(robot, 0, Pair(0, 0));
    }

    void cleanTrack(Robot &robot, int dir, const Pair &pair)
    {
        if (visited.count(pair) != 0) { return; }
        visited.insert(pair);
        robot.clean();

        for (int i = 0; i < 4; i++) {
            if (robot.move()) {
                if (dir == 0) { cleanTrack(robot, dir, pair.goUp()); }
                else if (dir == 1) { cleanTrack(robot, dir, pair.goRight()); }
                else if (dir == 2) { cleanTrack(robot, dir, pair.goLeft()); }
                else { cleanTrack(robot, dir, pair.goDown()); }
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnLeft();
            } else {
                robot.turnRight();
            }
            dir = (dir + 1) % 4;
        }
    }
};
