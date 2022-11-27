#include<bits/stdc++.h>
using namespace std;
int main(){
    string inp;
    vector<string> str;
    ifstream input("input.txt");
    int two=0,three=0;
    while(getline(input,inp)){
        bool twob=0,threeb=0;
        //sort(inp.begin(),inp.end());
        for(char c='a';c<='z';c++){
            int cnt=count(inp.begin(),inp.end(),c);
            //cout<<c<<" "<<cnt<<endl;
            if(cnt==3)threeb=true;
            if(cnt==2)twob=true;
        }
        //cout<<endl;
        //cout<<twob<<" "<<threeb<<endl;
        if(twob)two++;
        if(threeb)three++;
    }
    cout<<two*three;
}
