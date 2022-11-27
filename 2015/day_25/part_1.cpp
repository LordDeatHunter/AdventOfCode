#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long unsigned int> v={20151125};
  int col,row;
  cin>>col>>row;
  int n=col+row-1;
  for (int i=1; i<((n*(n-1))/2)+col; i++){
    v.push_back((v[i-1]*252533)%33554393);
  }
  cout<<v.back();
}
