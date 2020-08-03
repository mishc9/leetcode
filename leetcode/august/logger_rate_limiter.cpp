//
// Created by Михаил Степанов on 01.08.2020.
//

#include <string>
#include <iostream>
#include <map>

using namespace std;

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, const string &message) {
        bool shouldPrint = false;
        // something;
        if (lastPrinted.count(message) == 0) {
            shouldPrint = true;
        } else if (timestamp - lastPrinted[message] >= 10) {
            shouldPrint = true;
        }
        if (shouldPrint) {
            lastPrinted[message] = timestamp;
        }
        return shouldPrint;
    }

private:
    map<string, int> lastPrinted;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

int main() {

    Logger *obj = new Logger();
    bool param_1 = obj->shouldPrintMessage();
    return 0;
}