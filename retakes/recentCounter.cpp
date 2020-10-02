//
// Created by Михаил Степанов on 02.10.2020.
//

#include <list>
#include <vector>
#include <iostream>


class RecentCounter
{
    std::list<int> previousRequests;
public:
    int ping(int t)
    {
        previousRequests.push_back(t);
        for (auto it = previousRequests.begin(); *it < t - 3000;) {
            previousRequests.erase(it++);
        }
        return previousRequests.size();
    }
};

int main()
{
    RecentCounter recentCounter;

    std::vector<std::pair<int, int>> values = {{1,    1},
                                               {100,  2},
                                               {3001, 3},
                                               {3002, 3}};
    std::cout << "Tests:" << std::endl;
    for (auto[time, count]: values) {
        std::cout << "Expected " << count << ", got " << recentCounter.ping(time) << std::endl;
    }
    return 0;
}

