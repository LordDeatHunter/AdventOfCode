#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec;
    int tmp=0,cur=0,prev=0,tot=0;
    while(true){
        cin>>tmp;
        if(abs(tmp)>=1000)break;
        vec.push_back(tmp);
    }
    while(cur<vec.size()){
        prev=cur;
        cur+=vec[cur];
        if(cur-prev>=3)vec[prev]--;
        else vec[prev]++;
        tot++;
    }
    cout<<tot;
}
