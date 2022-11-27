#include<bits/stdc++.h>
using namespace std;
int main(){
    long int sum = 0;

    ifstream input("input.txt");
    string inp;
    while(getline(input, inp)){
//    {
        int tmp = stoi(inp);
//        int tmp;
//        cin >> tmp;
        int i;
        long sums = 0;
        for(i = floor(tmp/3) - 2; i > 0; i = floor(i/3) - 2){
            sums += i;
        }
        sum += sums;
    }
    cout << sum;
}
