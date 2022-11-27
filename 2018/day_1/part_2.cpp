#include<bits/stdc++.h>
using namespace std;
int main(){
    long int sum=0;
    set<long int> ans;
    for(;;){
        string inp;
        ifstream input("input.txt");
        int n=0;
        while(getline(input,inp)){
            long int num=0;
            //cout<<"element num "<<n++<<endl;
            for(int i=1;i<inp.size();i++)
                num=(num*10)+int(inp[i]-'0');

            if(inp[0]=='-')sum-=num;
            else sum+=num;

            for(auto j : ans)
                if(sum==j){cout<<sum;return 0;}

            ans.insert(sum);
        }
    }
    //cout<<sum;
}
