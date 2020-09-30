//
// Created by Михаил Степанов on 07.09.2020.
//

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool check_word(const string &w,
                    basic_string<char, char_traits<char>, allocator<char>>::const_iterator &iter,
                    basic_string<char, char_traits<char>, allocator<char>>::const_iterator &end
    )
    {
        for (char c: w) {
            if (iter == end || *iter == ' ') { return false; }
            if (c != *iter) { return false; }
            iter++;
        }
        // if (*iter != ' ' || iter != end) { return false; }
        return true;
    }

    string extract_word(basic_string<char, char_traits<char>, allocator<char>>::const_iterator &iter,
                        basic_string<char, char_traits<char>, allocator<char>>::const_iterator &end
    )
    {
        string s;
        while (iter != end && *iter != ' ') {
            s.append(1, *iter);
            iter++;
        }
        return s;
    }

    bool wordPattern(const string &pattern, const string &str)
    {
        unordered_map<char, string> memory;
        unordered_set<string> known_words;
        auto string_iter = str.begin();
        auto str_end = str.end();
        auto c = pattern.begin();
        for (; c != pattern.end(); c++) {
            if (string_iter == str_end) { return false; }
            if (memory.count(*c) != 0) {
                if (!check_word(memory.at(*c), string_iter, str_end)) { return false; }
            } else {
                string word = extract_word(string_iter, str_end);
                if (known_words.count(word) != 0) { return false; }
                memory[*c] = word;
                known_words.insert(word);
            }
            if (*string_iter == ' ') { string_iter++; }
            // else { return false; }
        }
        return string_iter == str_end && c == pattern.end();
    }
};


int main()
{
    Solution solution;
    cout << solution.wordPattern("abba", "cat dog dog cat") << endl;
    cout << solution.wordPattern("aaaa", "dog cat cat dog") << endl;
    cout << solution.wordPattern("abba", "dog dog dog dog") << endl;
    cout << solution.wordPattern("aaa", "aa aa aa aa") << endl;
    cout << solution.wordPattern("jquery", "jquery") << endl;
    cout << solution.wordPattern("he", "unit") << endl;

}
