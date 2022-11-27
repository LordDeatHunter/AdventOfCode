#include<bits/stdc++.h>
using namespace std;
int main(){
    int sum = 0;
    ifstream input("input.txt");
    string inp;
    while(getline(input, inp)){
        int tmp = stoi(inp);
        sum += floor(tmp/3) - 2;
    }
    cout << sum;
}
