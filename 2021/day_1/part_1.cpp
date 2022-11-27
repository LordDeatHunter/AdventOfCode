#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream input("input.txt");
    vector<int> numbers;
    for (string line ; getline(input, line); ) {
        numbers.push_back(stoi(line));
    }
    int total = 0;
    int previous = numbers[0];
    for (int i = 1; i < numbers.size(); ++i) {
        int current = numbers[i];
        if (current > previous) {
            ++total;
        }
        previous = current;
    }
    cout << total;
    return 0;
}
