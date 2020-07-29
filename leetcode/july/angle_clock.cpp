//
// Created by Михаил Степанов on 14.07.2020.
//

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        int roundHours = hour % 12;
        double minutesToHours = double(minutes) / 12;
        double roundHourMinutes = double(roundHours) * 5;
        double hourPosition = minutesToHours + roundHourMinutes;
        double diff = abs(double(minutes) - hourPosition);
        if (diff > 30) {
            diff = 30 - (diff - 30);
        }
        return diff * 6;
    }
};


int main() {
    Solution sol;
    cout << sol.angleClock(12, 30) << " 165 " << endl;
    cout << sol.angleClock(3, 30) << " 75 " << endl;
    cout << sol.angleClock(3, 15) << " 7.5 " << endl;
    cout << sol.angleClock(4, 50) << " 155 " << endl;
    cout << sol.angleClock(12, 0) << " 0 " << endl;

    return 0;

}
