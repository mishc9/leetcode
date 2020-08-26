//
// Created by Михаил Степанов on 13.08.2020.
//

#include <cmath>
#include <string>
#include <iostream>
#include <set>


using namespace std;

set<string> getAllCombinations(const string &basicString, int len) {
    int mask = 1 << basicString.length();
    set<string> combinations;
    string comString = "";
    for (int no = 1; no < mask; no++) {
        int num = no, i = 0;
        while (num) {
            if (num & 1) {
                comString = comString + basicString[i];
            }
            i++;
            num >>= 1;
        }
        if (comString.length() == len) {
            combinations.insert(comString);
        }
        comString = "";
    }
    return combinations;
}

class CombinationIterator {
public:
    set<string> combination;
    set<string>::iterator current;

    CombinationIterator(const string &characters, int combinationLength) {
        this->combination = getAllCombinations(characters, combinationLength);
        this->current = begin(combination);
    }

    string next() {
        return !(current == end(combination)) ? *current++ : "";
    }

    bool hasNext() {
        return !(current == end(combination));
    }
};


class PermutationIterator {
public:
    PermutationIterator(const string &characters, int combinationLength) {
        source = characters;
        base = characters.size();
        len = combinationLength;
        combination.reserve(len);
        step = 0;
        nCombinations = pow(base, len);
        if (!source.empty()) { for (int i = 0; i < len; i++) { combination.append(source[0], 1); }}
    }

    string next() {
        int buff = step;
        for (int i = 0; i < len; i++) {
            combination[combination.size() - 1 - i] = source[buff % base];
            buff /= base;
        }
        step++;
        return combination;
    }

    bool hasNext() { return step < nCombinations; }

private:
    int len, base;
    int step;
    string source, combination;
    int nCombinations;
};

/**
 * Your PermutationIterator object will be instantiated and called as such:
 * PermutationIterator* obj = new PermutationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {

    auto *combinationIterator = new PermutationIterator("abc", 2);
    for (int i = 0; i < 9; i++) {
        string param_1 = combinationIterator->next();
        bool param_2 = combinationIterator->hasNext();

        cout << param_1 << endl;
        cout << param_2 << endl;
    }

    return 0;
}
