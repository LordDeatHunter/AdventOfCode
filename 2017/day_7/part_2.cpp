#include<bits/stdc++.h>
using namespace std;

struct tree{
    int value;
    int orgval;
    bool root=1;
    vector<string> branch;
};

map<string,tree> tm;

int dfs(tree &a){
    for(int i=0; i<a.branch.size(); i++)
        a.value+=dfs(tm[a.branch[i]]);
    return a.value;
}

void visualize(tree a, int numT) {
    for (int i = 0; i < numT; i++, cout << '|' << '\t');
    cout << a.value << endl;
    for (int i = 0; i < a.branch.size(); i++) {
        visualize(tm[a.branch[i]], numT + 1);
    }
}

int main(){

    string inp;
    ifstream input("input.txt");
    while(getline(input,inp)){

        inp.erase(remove(inp.begin(), inp.end(), ' '), inp.end());
        int i=0,num=0;
        string cur="";

        while(inp[i]!='(') //get Node
            cur+=inp[i++];

        while(inp[++i]!=')') //get Node Value
            num=(num*10)+int(inp[i]-'0');

        tm[cur].value=num;
        tm[cur].orgval=num;
        if(inp.size()<14)continue;
        i+=2; //skip "->"

        while(++i<inp.size()){
            string tmpstr="";
            while(inp[i]!=','&&i<inp.size())
                tmpstr+=inp[i++];
            tm[cur].branch.push_back(tmpstr); //add branches
            tm[tmpstr].root=0;
        }
    }
    string root;
    for(auto i:tm)
        if(i.second.root){root=i.first;break;}

    dfs(tm[root]);

    //visualize(tm[root], 0);
    cout<<"String | Value | Original"<<endl;
    string str=root;
    while(true){
        pair<string,int> v[2];
        v[0].second=0;
        v[1].second=0;
        for(int i=0; i<tm[str].branch.size(); i++){
            if(tm[tm[str].branch[i]].value == tm[tm[str].branch[0]].value){
                    v[0].first=tm[str].branch[0];
                    v[0].second++;
            }
            else{
                v[1].first=tm[str].branch[i];
                v[1].second++;
            }
            cout<<tm[str].branch[i]<<"\t";
            cout<<tm[tm[str].branch[i]].value<<"\t";
            cout<<tm[tm[str].branch[i]].orgval<<endl;
        }
        cout<<endl;
        cout<<v[0].first<<" "<<v[0].second<<endl;
        cout<<v[1].first<<" "<<v[1].second<<endl<<endl;
        if(v[1].second==0||v[0].second==0)break;
        if(v[1].second<v[0].second)str=v[1].first;
        else str=v[0].first;
    }
}
