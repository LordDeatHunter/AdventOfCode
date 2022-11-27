#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  ifstream f;
  f.open("input.txt");
  f >> s;
  for(int i=0;i<s.size()-1;){
    if(s[i]=='!')s.erase(i,2);
    else if(s[i]==',')s.erase(i,1);
    else i++;
  }
  for(int i=0;i<s.size();){
    int j=1;
    if(s[i]=='<'){
      while(s[i+j]!='>')j++;
      s.erase(i,j+1);
    }
    else i++;
  }
  int val=0,sum=0;
  for(auto i:s){
    if(i=='{')val++;
    else sum+=val--;
  }
  cout<<sum;
}
