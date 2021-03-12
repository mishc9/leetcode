//
// Created by Михаил Степанов on 12.03.2021.
//

#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    static bool isValidSerialization(const string &preorder)
    {
        stringstream ss(preorder);
        string token;
        int sum = 1;
        while (getline(ss, token, ',')) {
            if (sum <= 0) { return false; }
            if (token == "#") { sum--; }
            else { sum++; }
        }
        return sum == 0;
    }
};

#include <iostream>

int main()
{
    cout << (Solution::isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") == true) << endl;
    cout << (Solution::isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#") == false) << endl;
    cout << (Solution::isValidSerialization("9,3,4,#,#,1,#,#,2,#,#") == true) << endl;
    cout << (Solution::isValidSerialization("9,3,#,1,#,#,2,#,#") == true) << endl;
    cout << (Solution::isValidSerialization("9,#,#") == true) << endl;
    cout << (Solution::isValidSerialization("9,3,#,#") == false) << endl;
    cout << (Solution::isValidSerialization("9,3,#,#,#") == true) << endl;
    cout << (Solution::isValidSerialization("9,#,3,#,#") == true) << endl;
    cout << (Solution::isValidSerialization("#") == true) << endl;
    cout << (Solution::isValidSerialization("9,#") == false) << endl;
    cout << (Solution::isValidSerialization("#,9") == false) << endl;
    cout << (Solution::isValidSerialization("#,#,3,5,#") == false) << endl;
}

