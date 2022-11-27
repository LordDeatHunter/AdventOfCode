#include<bits/stdc++.h>
using namespace std;

int main() {
    int z = 0;
    int y = 0;
    int aim = 0;
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
            z += amount;
            y += aim * amount;
        } else if (typeString == "down") {
            aim += amount;
        } else if (typeString == "up") {
            aim -= amount;
        }
    }
    cout << z << " " << y << endl;
    cout << z * y;
    return 0;
}
