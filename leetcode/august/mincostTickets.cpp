//
// Created by Михаил Степанов on 25.08.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    int mincostTickets(const vector<int> &days, const vector<int> &costs)
    {
        int last = days.back(), cache[last + 1];
        cache[0] = 0; // initial value
        for (int dayNum = 1, dayOfRidePtr = 0; dayNum <= last; dayNum++) {
            if (dayNum == days[dayOfRidePtr]) {  // if it's a day to ride
                dayOfRidePtr++;
                cache[dayNum] = min( // minimal cost of 1, 7-day or month ticket based on history
                        {costs[0] + cache[dayNum - 1],
                         costs[1] + cache[dayNum - min(dayNum, 7)], // look back for one week if possible
                         costs[2] + cache[dayNum - min(dayNum, 30)]}); // look back one month if possible
            } else { // no ride this day
                cache[dayNum] = cache[dayNum - 1];
            }
        }
        return cache[last];  // A minimal cost for the last day to ride
    }
};