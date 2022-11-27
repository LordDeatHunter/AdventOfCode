#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a;
  int n=256;
  for(int i=0;i<n;i++){
    a.push_back(i);
  }
  vector<int> shift={130,126,1,11,140,2,255,207,18,254,246,164,29,104,0,224};
  //vector<int> shift={3,4,1,5};
  int skip=0,rev=0;
  for(auto i:shift){
    reverse(a.begin(),a.begin()+i);
    //cout<<"\nReversed: ";for(auto i:a)cout<<i<<" ";
    rotate(a.begin(),a.begin() + (i + (skip++))%n ,a.end()); rev+=i+skip-1;
    //cout<<"\nRotated: ";for(auto i:a)cout<<i<<" ";
  }
  rotate(a.rbegin(),a.rbegin()+(rev)%n,a.rend());
  //cout<<endl;for(auto i:a)cout<<i<<" ";
  cout<<a[0]*a[1];
}
