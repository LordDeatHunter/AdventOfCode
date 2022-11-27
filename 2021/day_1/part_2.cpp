#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream input("input.txt");
    vector<int> numbers;
    for (string line ; getline(input, line); ) {
        numbers.push_back(stoi(line));
    }
    int segments = 3;
    vector<int> sum(numbers.size() - segments + 1, 0);
    for (int i = segments - 1, j = 0; i < numbers.size(); ++i, ++j) {
        for (int currentSegment = 0; currentSegment < segments && i - currentSegment >= 0; ++currentSegment) {
            sum[j] += numbers[i - currentSegment];
        }
    }
    int total = 0;
    int previous = sum[0];
    for (int i = 1; i < sum.size(); ++i) {
        int current = sum[i];
        if (current > previous) {
            ++total;
        }
        previous = current;
    }
    cout << total;
    return 0;
}
