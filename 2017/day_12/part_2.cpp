#include<bits/stdc++.h>
using namespace std;

string tostring(int a){
  string s="";
  for(int i=a;i>0;i/=10)s+=char(i%10+'0');
  reverse(s.begin(),s.end());
  if(s=="")return "0";
  else return s;
}

int main(){
  fstream f("input.txt");
  map<string,vector<string>> a;
  string s;
  int j=0;
  while(getline(f,s)){
    vector<string> tmpv;
    bool first=false;
    for(int i=0; i<s.size(); i++){
      string tmps="";
      while(isdigit(s[i]) && i<s.size()){
        tmps+=s[i];
        i++;
      }
      if(tmps!="" && first)tmpv.push_back(tmps);
      first=true;
    }
    a[tostring(j++)]=tmpv;
  }
  set<set<string>> group;
  for(int k=0;k<a.size();k++){
    set<string> linked;
    queue<string> visit;
    for(auto i : a[tostring(k)]){
      visit.push(i);
      linked.insert(i);
    }
    while(!visit.empty()){
      s = visit.front();
      for(auto i : a[s])
        if(!linked.count(i)){
          linked.insert(i);
          visit.push(i);
        }
      visit.pop();
    }
    //for(auto i:linked)cout<<i<<" ";
    group.insert(linked);
    //cout<<endl<<linked.size();
  }
  cout<<group.size();
}
