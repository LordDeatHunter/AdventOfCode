#include<bits/stdc++.h>
using namespace std;

int strcomp(string a,string b){
    for(int i=0;i<a.size();i++){
        string x=a,y=b;
        x.erase(i,1);
        y.erase(i,1);
        cout<<x<<" "<<y<<endl;
        if(x==y)return i;
    }
    return -1;
}

int main(){
    string inp;
    vector<string> str;
    ifstream input("input.txt");
    int two=0,three=0;
    while(getline(input,inp))
        str.push_back(inp);
    for(int i=0;i<str.size()-1;i++){
        for(int j=i+1;j<str.size();j++){
            int comp = strcomp(str[i],str[j]);
            cout<<comp<<endl;
            if(comp >= 0){
                string x = str[i];
                x.erase(comp);
                cout<<x;
                return 0;
            }
        }
    }
}
