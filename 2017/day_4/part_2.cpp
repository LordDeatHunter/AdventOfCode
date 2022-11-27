#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream input("input.txt");
    string inp;
    vector<vector<string> > str;
    int tot=0;
    for(int i=0;getline(input,inp);i++){
        vector<string> str2;
        istringstream s(inp);
        str2.insert(str2.end(),
            istream_iterator<string>(s),
            istream_iterator<string>());
        str.push_back(str2);
    }
    tot=str.size();
    for(int i=0;i<str.size();i++){
        for(int j=0;j<str[i].size();j++){
            sort(str[i][j].begin(),str[i][j].end());
        }
    }
    for(int i=0;i<str.size();i++){
        sort(str[i].begin(),str[i].end());
        for(int j=0;j<str[i].size()-1;j++){
            if(str[i][j]==str[i][j+1]){tot--;break;}
        }
    }
    cout<<tot;
}
