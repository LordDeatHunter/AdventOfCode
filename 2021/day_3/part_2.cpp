#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream input("input.txt");
    vector<int> count;
    vector<string> table;
    for (string line; getline(input, line);) {
        table.push_back(line);
        for (int i = 0; i < line.size(); ++i) {
            if (count.size() < i + 1) {
                count.push_back(0);
            }
            count[i] += line[i] - 48;
        }
    }
    int oxygen = 0;
    int co2 = 0;
    vector<string> tableCopy = table;
    vector<int> countCopy = count;
    int rowSize = table[0].size();
    while (tableCopy.size() > 1) {
        for (int i = 0; i < rowSize; ++i) {
            int rowValue = countCopy[i];
            int size = tableCopy.size();
            for (int j = 0; j < tableCopy.size(); ++j) {
                string row = tableCopy[j];
                char bit = char(row[i] - 48);
                int numBit = rowValue >= size - rowValue ? 1 : 0;
                if (bit != numBit) {
                    tableCopy.erase(tableCopy.begin() + j--);
                    for (int k = 0; k < rowSize; ++k) {
                        if (row[k] == '1') {
                            --countCopy[k];
                        }
                    }
                }
            }
            if (tableCopy.size() == 1) {
                break;
            }
        }
    }
    cout << tableCopy[0] << endl;
    for (int i = tableCopy[0].size(), j = 0; i >= 0; --i, ++j) {
        int bit = int(tableCopy[0][i - 1]) - 48;
        if (bit == 1) {
            oxygen += int(pow(2, j));
        }
    }
    countCopy = count;
    tableCopy = table;
    while (tableCopy.size() > 1) {
        for (int i = 0; i < rowSize; ++i) {
            int rowValue = countCopy[i];
            int size = tableCopy.size();
            for (int j = 0; j < tableCopy.size(); ++j) {
                string row = tableCopy[j];
                char bit = char(row[i] - 48);
                int numBit = rowValue < size - rowValue ? 1 : 0;
                if (bit != numBit) {
                    tableCopy.erase(tableCopy.begin() + j--);
                    for (int k = 0; k < rowSize; ++k) {
                        if (row[k] == '1') {
                            --countCopy[k];
                        }
                    }
                }
            }
            if (tableCopy.size() == 1) {
                break;
            }
        }
    }
    cout << tableCopy[0] << endl;
    for (int i = tableCopy[0].size(), j = 0; i >= 0; --i, ++j) {
        int bit = int(tableCopy[0][i - 1]) - 48;
        if (bit == 1) {
            co2 += int(pow(2, j));
        }
    }
    cout << oxygen << " " << co2 << endl;
    cout << oxygen * co2;
    return 0;
}
