#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream input("input.txt");
    vector<int> count;
    int rows = 0;
    for (string line ; getline(input, line); ) {
        ++rows;
        for (int i = 0; i < line.size(); ++i) {
            if (count.size() < i + 1) {
                count.push_back(0);
            }
            count[i] += line[i] - 48;
        }
    }
    int gamma = 0;
    int epsilon = 0;
    for (int i = 0, j = count.size(); i < count.size(); ++i, --j) {
        int current = count[j - 1];
        if (current >= rows / 2) {
            gamma += int(pow(2, i));
        } else {
            epsilon += int(pow(2, i));
        }
    }
    cout << gamma << " " << epsilon << endl;
    cout << gamma * epsilon;
    return 0;
}
