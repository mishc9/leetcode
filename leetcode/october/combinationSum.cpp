//
// Created by Михаил Степанов on 02.10.2020.
//

#include <vector>
#include <iostream>

using namespace std;

using Results = vector<vector<int>>;

class Solution
{
    vector<int> _candidates;
    vector<int> _track;
    Results results;
public:
    Results combinationSum(const vector<int> &candidates, int target)
    {
        _init(candidates);
        backtrackingWithRepetitions(0, target);
        return results;
    }

    Results combinationSumWithRepetitions(const vector<int> &candidates, int target) {
        _init(candidates);
        backtrackingWithRepetitions(0, target);
        return results;
    }
    Results combinationSumNoRepetitions(const vector<int> &candidates, int target) {
        _init(candidates);
        backtrackingNoRepetitions(0, target);
        return results;
    }

    void _init(const vector<int> &candidates)
    {
        _candidates = candidates;
        _track.clear();
        results.clear();
    }

    void _backtracking(int position, int target, bool withRepetitions) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            vector<int> copy(_track);
            results.emplace_back(copy);
        } else {
            for (int i = position; i < _candidates.size(); i++) {
                _track.emplace_back(_candidates[i]);
                _backtracking(i + (withRepetitions ? 0 : 1) , target - _candidates[i], withRepetitions);
                _track.pop_back();
            }
        }
    }

    void backtrackingWithRepetitions(int position, int target)
    {
        if (target < 0) {
            return;
        } else if (target == 0) {
            vector<int> copy(_track);
            results.emplace_back(copy);
        } else {
            for (int i = position; i < _candidates.size(); i++) {
                _track.emplace_back(_candidates[i]);
                backtrackingWithRepetitions(i, target - _candidates[i]);
                _track.pop_back();
            }
        }
    }

    void backtrackingNoRepetitions(int position, int target)
    {
        if (target < 0) {
            return;
        } else if (target == 0) {
            vector<int> copy(_track);
            results.emplace_back(copy);
        } else {
            for (int i = position; i < _candidates.size(); i++) {
                _track.emplace_back(_candidates[i]);
                backtrackingNoRepetitions(i + 1, target - _candidates[i]);
                _track.pop_back();
            }
        }
    }
};

class CombinatorialSum
{
    vector<int> _candidates;
    vector<int> _track;
    Results results;

public:
    vector<vector<int>> solve(const vector<int> &candidates, int target)
    {
        _candidates = candidates;
        _track.clear();
        results.clear();
        backtrackingWithoutRepetitions(0, target);
        return results;
    }

    void backtrackingWithoutRepetitions(int position, int target)
    {
        if (target < 0) {
            return;
        } else if (target == 0) {
            vector<int> copy(_track);
            results.emplace_back(copy);
        } else {
            for (int i = position; i < _candidates.size(); i++) {
                _track.emplace_back(_candidates[i]);
                backtrackingWithoutRepetitions(i + 1, target - _candidates[i]);
                _track.pop_back();
            }
        }
    }
};

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    cout << '[';
    int firstIter = true;
    for (const auto &item: vec) {
        if (firstIter) {
            os << item;
            firstIter = false;
        } else {
            os << ", " << item;
        }
    }
    cout << ']';
    return os;
}


int main()
{
    Solution solution;
    cout << solution.combinationSum({2, 3, 6, 7}, 7) << endl;

    cout << "==============" << endl;
    CombinatorialSum combinatorialSum;
    cout << combinatorialSum.solve({3}, 2).size() << endl;
    cout << combinatorialSum.solve({1}, 1).size() << endl;
    cout << combinatorialSum.solve({1, 1}, 1).size() << endl;
    cout << combinatorialSum.solve({1, 1}, 2).size() << endl;
    cout << combinatorialSum.solve({1, 1, 1}, 2).size() << endl;
    cout << combinatorialSum.solve({1, 2, 3}, 3).size() << endl;
    cout << combinatorialSum.solve({1, 1, 1, 1, 2}, 2).size() << endl;
    return 0;
}