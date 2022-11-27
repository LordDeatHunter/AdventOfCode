#include<bits/stdc++.h>
using namespace std;
int main(){
    string inp;
    map<string,bool> tm;
    vector<string> tree;
    ifstream input("input.txt");
    while(getline(input,inp)){
        if(inp.size()<14)continue;
        inp.erase(remove(inp.begin(), inp.end(), ' '), inp.end());
        int i=0;
        string cur="";
        while(inp[i]!='(')
            cur+=inp[i++];
        i=inp.find('>');
        while(++i<inp.size()){
            string tmpstr="";
            while(inp[i]!=','&&i<inp.size()){
                //cout<<inp[i];
                tmpstr+=inp[i++];}
            //cout<<tmpstr<<endl;
            //cout<<endl;
            tm[tmpstr]=1;
        }
        tree.push_back(cur);
    }
    for(auto i:tree)if(!tm[i]){cout<<i;break;}
}
