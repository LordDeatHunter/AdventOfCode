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
  set<string> linked;
  queue<string> visit;
  visit.push(a["0"][0]);
  linked.insert(a["0"][0]);
  while(!visit.empty()){
    s = visit.front();
    for(auto i : a[s])
      if(!linked.count(i)){
        linked.insert(i);
        visit.push(i);
      }
    visit.pop();
  }
  for(auto i:linked)cout<<i<<" ";
  cout<<endl<<linked.size();
}
