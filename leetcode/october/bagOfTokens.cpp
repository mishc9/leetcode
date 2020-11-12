//
// Created by Михаил Степанов on 24.10.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int P)
    {
        sort(tokens.begin(), tokens.end());
        int low = 0, high = tokens.size() - 1;
        int points = 0, ans = 0;
        while (low <= high && (P >= tokens[low] || points > 0)) {
            while (low <= high && P >= tokens[low]) {
                P -= tokens[low++];
                points++;
            }

            ans = max(ans, points);
            if (low <= high && points > 0) {
                P += tokens[high--];
                points--;
            }
        }
        return ans;
    }
};
