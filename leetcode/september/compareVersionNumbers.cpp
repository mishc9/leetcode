//
// Created by Михаил Степанов on 09.09.2020.
//

#include <string>
#include <iostream>

using namespace std;


class Solution
{
public:
    static int compareVersion(string version1, string version2)
    {
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < version1.length() || ptr2 < version2.length()) {
            long long int first_number = 0, second_number = 0;
            while (ptr1 < version1.length() && version1[ptr1] != '.') {
                first_number = 10 * first_number + (version1[ptr1] - '0');
                ptr1++;
            }
            ptr1++;
            while (ptr2 < version2.length() && version2[ptr2] != '.') {
                second_number = 10 * second_number + (version2[ptr2] - '0');
                ptr2++;
            }
            ptr2++;
            if (first_number < second_number) { return -1; }
            else if (first_number > second_number) { return 1; }
        }
        return 0;
    }
};


int main()
{
    cout << Solution::compareVersion("1.0.1", "1") << endl;
    cout << Solution::compareVersion("0.1", "1.1") << endl;

}

