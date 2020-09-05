//
// Created by Михаил Степанов on 04.09.2020.
//


#include <vector>
#include <string>


using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<int> lastOccurrence(26);
        for (int i = 0; i < S.size(); i++) {
            lastOccurrence[S[i] - 'a'] = i;
        }

        int j = 0, anchor = 0;
        vector<int> answer;
        for (int i = 0; i < S.size(); i++) {
            j = max(j, lastOccurrence[S[i] - 'a']);
            if (i == j) {
                answer.emplace_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return answer;
    }
};

