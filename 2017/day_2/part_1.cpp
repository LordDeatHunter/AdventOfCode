#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,tmp,sm=0;
    cin>>n>>m;
    vector<pair<int,int> > mnx; //minimum, maximum
    for(int i=0;i<n;i++){
        mnx.push_back(make_pair(INT_MAX,0));
        for(int j=0;j<m;j++){
            cin>>tmp;
            mnx[i]=make_pair((min(mnx[i].first,tmp)),(max(mnx[i].second,tmp)));
        }
    }
    for(int i=0;i<n;i++)sm+=mnx[i].second-mnx[i].first;
    cout<<sm;
}
