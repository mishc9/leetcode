//
// Created by Михаил Степанов on 01.10.2020.
//

#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class RecentCounter
{
    list<int> requestsHistory;
public:

    int ping(int t)
    {
        requestsHistory.push_back(t);
        for (auto it = requestsHistory.begin(); it != requestsHistory.end();) {
            if (*it < t - 3000) { requestsHistory.erase(it++); }
            else { break; }
        }
        return requestsHistory.size();
    }
};

class _RecentCounter
{
    map<int, int> requestsThisTime;
public:

    int ping(int t)
    {
        requestsThisTime[t]++;
        auto lower_bound = requestsThisTime.lower_bound(t - 3000);
        for (auto it = requestsThisTime.begin(); it != lower_bound;) {
            requestsThisTime.erase(it++);
        }
        int requestsInInterval = 0;
        for (auto &it : requestsThisTime) {
            requestsInInterval += it.second;
        }
        return requestsInInterval;
    }
};

int main()
{
    RecentCounter recentCounter;

    vector<pair<int, int>> values = {{1,    1},
                                     {100,  2},
                                     {3001, 3},
                                     {3002, 3}};
    for (auto[time, count]: values) {
        cout << "Expected " << count << ", got " << recentCounter.ping(time) << endl;
    }
    return 0;
}


