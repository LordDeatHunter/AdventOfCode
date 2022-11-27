#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  ifstream f;
  f.open("input.txt");
  f >> s;
  for(int i=0;i<s.size()-1;){
    if(s[i]=='!')s.erase(i,2);
    //else if(s[i]==',')s.erase(i,1);
    else i++;
  }
  int sum=0;
  for(int i=0;i<s.size();){
    int j=1;
    if(s[i]=='<'){
      while(s[i+j]!='>')j++;
      sum+=j-1;
      s.erase(i,j+1);
    }
    else i++;
  }
  cout<<sum;
}
