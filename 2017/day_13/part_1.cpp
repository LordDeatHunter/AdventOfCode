#include<bits/stdc++.h>
using namespace std;

int toint(string s){
  int n=0;
  for(auto i:s){
    n=n*10+int(i-'0');
  }
  return n;
}

struct tower{
public:
  bool up;
  int maxH;
  int curH;
};

int main(){
  fstream f("input.txt");
  string s;
  map<int,tower> layer;
  while(getline(f,s)){
    string tmp="",tmp2="";
    bool first=true;
    for(int i=0;i<s.size();i++){
      if(s[i]==':'){i+=2;first=false;}
      if(first)tmp+=s[i];
      else tmp2+=s[i];
    }
    layer[toint(tmp)].up=true;
    layer[toint(tmp)].maxH=toint(tmp2);
    layer[toint(tmp)].curH=1;
  }
  int scan=0;
  for(int i=0;i<=layer.rbegin()->first;i++){
    if(layer.count(i)&&layer[i].curH==1){
      cout<<i<<"*"<<layer[i].maxH<<" + ";
      scan+=i*layer[i].maxH;
    }
    for(int j=0;j<=layer.rbegin()->first;j++){
      if(!layer.count(j))continue;
      if((layer[j].up&&layer[j].curH==layer[j].maxH)||(!layer[j].up&&layer[j].curH!=1)){
        layer[j].up=false;
        layer[j].curH--;
      }
      else{
        layer[j].up=true;
        layer[j].curH++;
      }
      //cout<<j<<" "<<layer[j].curH<<endl;
    }
    //cout<<endl;
  }
  cout<<" = "<<scan;
}
