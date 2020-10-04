//
// Created by Михаил Степанов on 03.10.2020.
//

#include <vector>
#include <iostream>

using namespace std;

using Results = vector<vector<int>>;
using Candidates = const vector<int> &;

class Solution
{
    vector<int> resultBuffer;
    Results results;

    void _init()
    {
        results.clear();
        resultBuffer.clear();
    }

    void backtracking(int pointer, Candidates candidates, int target, bool withRepetitions)
    {
        if (target < 0) {
            return;
        } else if (target == 0) {
            vector<int> copy(resultBuffer);
            results.emplace_back(copy);
        } else {
            for (int i = pointer; i < candidates.size(); i++) {
                resultBuffer.emplace_back(candidates[i]);
                backtracking(i + (withRepetitions ? 0 : 1),
                             candidates,
                             target - candidates[i],
                             withRepetitions);
                resultBuffer.pop_back();
            }
        }
    }

    Results _combinations(Candidates candidates, int target, bool withRepetitions)
    {
        _init();
        backtracking(0, candidates, target, withRepetitions);
        return results;
    }

public:
    Results combinationsWithRepetition(Candidates candidates, int target)
    {
        return _combinations(candidates, target, true);
    }

    Results combinationsNoRepetition(Candidates candidates, int target)
    {
        return _combinations(candidates, target, false);
    }
};

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    cout << '[';
    bool firstStep = true;
    for (const auto &item: vec) {
        if (firstStep) {
            cout << item;
            firstStep = false;
        } else {
            cout << ", ";
            cout << item;
        }
    }
    cout << ']';
    return os;
}


int main()
{
    Solution solution;
    cout << solution.combinationsWithRepetition({2, 3, 6, 7}, 7) << endl;

    cout << "==============" << endl;
    Solution combinatorialSum;
    cout << combinatorialSum.combinationsNoRepetition({3}, 2).size() << endl;
    cout << combinatorialSum.combinationsNoRepetition({1}, 1).size() << endl;
    cout << combinatorialSum.combinationsNoRepetition({1, 1}, 1).size() << endl;
    cout << combinatorialSum.combinationsNoRepetition({1, 1}, 2).size() << endl;
    cout << combinatorialSum.combinationsNoRepetition({1, 1, 1}, 2).size() << endl;
    cout << combinatorialSum.combinationsNoRepetition({1, 2, 3}, 3).size() << endl;
    cout << combinatorialSum.combinationsNoRepetition({1, 1, 1, 1, 2}, 2).size() << endl;
    return 0;
}
