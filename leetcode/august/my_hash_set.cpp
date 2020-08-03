//
// Created by Михаил Степанов on 02.08.2020.
//

#include <vector>
#include <iostream>

using namespace std;

// Todo: RESIZE IS BROKEN

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "[";
    bool firstStep = true;

    for (const auto &val: vec) {
        if (firstStep) {
            os << val;
            firstStep = false;
            continue;
        }
        os << ", " << val;
    }

    os << "];";
    return os;

}

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        size = 8;
        table.resize(size);
        for (int i = 0; i < size; i++) {
            table[i] = emptyVal;
        }
    }

    void add(int key) {
        if (needResize()) { resize(); }
        int i = 0;
        int hashVal = hash(key);
        if (key == 95) {
            //
        }
        while (i != size) {
            int position = probing(hashVal, i);
            if (table[position] == emptyVal || table[position] == tombstone) {
                if (table[position] == emptyVal) { elementCount++; };
                table[position] = key;
                break;
            }
            if (table[position] == key) {
                break;
            }
            i++;
        }
    }

    void remove(int key) {
        int hashVal = hash(key);
        int i = 0;
        while (i != size) {
            int position = probing(hashVal, i);
            if (table[position] == emptyVal) {
                break;
            }
            if (table[position] == key) {
                table[position] = tombstone;
                break;
            }
            i++;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if (key == 95) {
            //
        }
        int hashVal = hash(key);
        int i = 0;
        while (i != size) {
            int position = probing(hashVal, i);
            if (table[position] == emptyVal) { return false; }
            if (table[position] == key) {
                return true;
            }
            i++;
        }
        return false;
    }

private:
    int size;
    int emptyVal = -1;
    int tombstone = -2;
    int elementCount;

    vector<int> table;

    bool needResize() { return size / 2 < elementCount + 1; }

    void resize() {
        vector<int> oldTable(table);
        // cout << oldTable << endl;
        int oldSize = size;
        size = size * 2;

        table.resize(size);
        for (int i = 0; i < size; i++) { table[i] = emptyVal; }
        elementCount = 0;

        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i] != emptyVal && oldTable[i] != tombstone) { add(oldTable[i]); }
        }
        // cout << table << endl;
    }

    // int hash(int key) { return (31 * key + 1) % size; }
    int hash(int key) { return key % size; }

    // int probing(int hashVal, int step) { return (hashVal + step * step) % size; }
    int probing(int hashVal, int step) { return (hashVal + step) % size; }
};


void runner(const vector<string> &commands, const vector<vector<int>> &values) {
    MyHashSet myHashSet;
    for (int i = 0; i < commands.size(); i++) {
        string command = commands[i];
        if (!values[i].empty()) {
            int value = values[i][0];
            if (command == "contains") {
                bool contains = myHashSet.contains(value);
                if (contains) {
                    cout << "true ";
                } else { cout << "false "; };
            } else if (command == "add") {
                myHashSet.add(value);
                cout << "null ";
            } else if (command == "remove") {
                myHashSet.remove(value);
                cout << "null ";
            }
        }
    }
}


int main() {
    runner(
            {"MyHashSet", "contains", "remove", "add", "add", "contains", "remove", "contains", "contains", "add",
             "add", "add",
             "add", "remove", "add", "add", "add", "add", "add", "add", "add", "add", "add", "add", "contains", "add",
             "contains",
             "add", "add", "contains", "add", "add", "remove", "add", "add", "add", "add", "add", "contains", "add",
             "add", "add",
             "remove", "contains", "add", "contains", "add", "add", "add", "add", "add", "contains", "remove", "remove",
             "add",
             "remove", "contains", "add", "remove", "add", "add", "add", "add", "contains", "contains", "add", "remove",
             "remove",
             "remove", "remove", "add", "add", "contains", "add", "add", "remove", "add", "add", "add", "add", "add",
             "add", "add",
             "add", "remove", "add", "remove", "remove", "add", "remove", "add", "remove", "add", "add", "add",
             "remove", "remove",
             "remove", "add", "contains", "add"},
            {{},
             {72},
             {91},
             {48},
             {41},
             {96},
             {87},
             {48},
             {49},
             {84},
             {82},
             {24},
             {7},
             {56},
             {87},
             {81},
             {55},
             {19},
             {40},
             {68},
             {23},
             {80},
             {53},
             {76},
             {93},
             {95},
             {95},
             {67},
             {31},
             {80},
             {62},
             {73},
             {97},
             {33},
             {28},
             {62},
             {81},
             {57},
             {40},
             {11},
             {89},
             {28},
             {97},
             {86},
             {20},
             {5},
             {77},
             {52},
             {57},
             {88},
             {20},
             {48},
             {42},
             {86},
             {49},
             {62},
             {53},
             {43},
             {98},
             {32},
             {15},
             {42},
             {50},
             {19},
             {32},
             {67},
             {84},
             {60},
             {8},
             {85},
             {43},
             {59},
             {65},
             {40},
             {81},
             {55},
             {56},
             {54},
             {59},
             {78},
             {53},
             {0},
             {24},
             {7},
             {53},
             {33},
             {69},
             {86},
             {7},
             {1},
             {16},
             {58},
             {61},
             {34},
             {53},
             {84},
             {21},
             {58},
             {25},
             {45},
             {3}}

    );


    MyHashSet myHashSet;

    myHashSet.add(10);
    cout << "contains one ";
    cout << (myHashSet.contains(1) == 0) << endl;
    cout << (myHashSet.contains(10) == 1) << endl;
    myHashSet.remove(10);
    cout << "contains ten ";
    cout << (myHashSet.contains(10) == 0) << endl;
    cout << (myHashSet.contains(10) == 0) << endl;

    vector<int> values{1, 2, 8, 0, 31, 4};

    for (auto val: values) { myHashSet.add(val); }

    cout << "Check contains it 1";
    for (auto val: values) { cout << (myHashSet.contains(val) == 1) << endl; }

    cout << "Check contains it 2";
    for (auto val: values) { cout << (myHashSet.contains(val) == 1) << endl; }

    for (auto val : values) { myHashSet.remove(val); }

    cout << "Check remove";
    for (auto val: values) { cout << (myHashSet.contains(val) == 0) << endl; }

    for (auto val: values) { myHashSet.add(val); }

    cout << "Check contains it 3 ";
    for (auto val: values) { cout << (myHashSet.contains(val) == 1) << endl; }

    cout << "Check not contains";
    vector<int> notAValues{3, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 32, 33};

    cout << "Check contains it 4";
    for (auto val: notAValues) { cout << (myHashSet.contains(val) == 0) << endl; }

    /*
     * ["MyHashSet","contains","remove","add","add","contains","remove","contains","contains","add","add","add","add","remove","add","add","add","add","add","add","add","add","add","add","contains","add","contains","add","add","contains","add","add","remove","add","add","add","add","add","contains","add","add","add","remove","contains","add","contains","add","add","add","add","add","contains","remove","remove","add","remove","contains","add","remove","add","add","add","add","contains","contains","add","remove","remove","remove","remove","add","add","contains","add","add","remove","add","add","add","add","add","add","add","add","remove","add","remove","remove","add","remove","add","remove","add","add","add","remove","remove","remove","add","contains","add"]
[[],[72],[91],[48],[41],[96],[87],[48],[49],[84],[82],[24],[7],[56],[87],[81],[55],[19],[40],[68],[23],[80],[53],[76],[93],[95],[95],[67],[31],[80],[62],[73],[97],[33],[28],[62],[81],[57],[40],[11],[89],[28],[97],[86],[20],[5],[77],[52],[57],[88],[20],[48],[42],[86],[49],[62],[53],[43],[98],[32],[15],[42],[50],[19],[32],[67],[84],[60],[8],[85],[43],[59],[65],[40],[81],[55],[56],[54],[59],[78],[53],[0],[24],[7],[53],[33],[69],[86],[7],[1],[16],[58],[61],[34],[53],[84],[21],[58],[25],[45],[3]]
     */


    return 0;
}