#include<bits/stdc++.h>
using namespace std;
int main(){
    int sum=0;
    string inp;
    ifstream input("input.txt");
    while(getline(input,inp,'\n')){
        int num=0;
        for(int i=1;i<inp.size();i++)
            num=(num*10)+int(inp[i]-'0');
        if(inp[0]=='-')sum-=num;
        else sum+=num;
    }
    cout<<sum;
}
