#include<bits/stdc++.h>
using namespace std;

int main() {
    int x = 0;
    int y = 0;
    ifstream input("input.txt");
    for (string line ; getline(input, line); ) {
        string typeString;
        int amount = 0;
        bool getNum = false;
        for (char c : line) {
            if (c == ' ') {
                getNum = true;
            } else if (!getNum) {
                typeString += c;
            } else {
                amount += int(c) - 48;
            }
        }
        if (typeString == "forward") {
            x += amount;
        } else if (typeString == "down") {
            y += amount;
        } else if (typeString == "up") {
            y -= amount;
        }
    }
    cout << x << " " << y << endl;
    cout << x * y;
    return 0;
}
