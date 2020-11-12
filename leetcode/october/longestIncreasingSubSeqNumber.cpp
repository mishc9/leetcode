//
// Created by Михаил Степанов on 31.10.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    static int findNumberOfLIS(const vector<int> &nums)
    {
        int size = nums.size();
        if (size <= 1) { return size; }
        vector<int> lengths(size, 0);
        vector<int> counts(size, 1);

        for (int j = 0; j < size; ++j) {
            for (int i = 0; i < j; ++i)
                if (nums[i] < nums[j]) {
                    if (lengths[i] >= lengths[j]) {
                        lengths[j] = lengths[i] + 1;
                        counts[j] = counts[i];
                    } else if (lengths[i] + 1 == lengths[j]) {
                        counts[j] += counts[i];
                    }
                }
        }

        int longest = 0, answer = 0;
        for (int length: lengths) {
            longest = max(longest, length);
        }
        for (int i = 0; i < size; ++i) {
            if (lengths[i] == longest) {
                answer += counts[i];
            }
        }
        return answer;
    }
};

