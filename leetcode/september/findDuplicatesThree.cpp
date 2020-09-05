//
// Created by Михаил Степанов on 03.09.2020.
//

#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        int n = nums.size();

        if (n == 0 || k < 0 || t < 0) { return false; }

        unordered_map<int, int> bucketsHash;

        for (int i = 0; i < n; ++i) {
            int bucket = nums[i] / ((long) t + 1);

            if (nums[i] < 0) { --bucket; }

            if (bucketsHash.find(bucket) != bucketsHash.end()) return true;
            else {
                bucketsHash[bucket] = nums[i];
                if (bucketsHash.find(bucket - 1) != bucketsHash.end() &&
                    (long) nums[i] - bucketsHash[bucket - 1] <= t) { return true; }
                if (bucketsHash.find(bucket + 1) != bucketsHash.end() &&
                    (long) bucketsHash[bucket + 1] - nums[i] <= t) { return true; }

                if (bucketsHash.size() > k) {
                    int key_to_remove = nums[i - k] / ((long) t + 1);
                    if (nums[i - k] < 0) { --key_to_remove; }
                    bucketsHash.erase(key_to_remove);
                }
            }
        }
        return false;
    }
};

