#include<bits/stdc++.h>
using namespace std;
int main(){
    int tot=0,tot2,tmp;
    vector<string> st;
    vector<int> mem,stVal;
    st.push_back("");
    stVal.push_back(0);
    for(int i=0;i<16;i++){
        cin>>tmp;
        mem.push_back(tmp);
        st[0]+=to_string(mem[i])+" ";
    }
    bool bol=true;
    int val=1;
    for(;bol;val++){
        pair<int,int> mx={0,0};
        for(int i=0;i<16;i++){
            if(mx.first<mem[i]){
                mx.first=mem[i];
                mx.second=i;
            }
        }
        mem[mx.second]=0;
        for(int i=0;i<mx.first;i++){
            mx.second++;
            if(mx.second==16)mx.second=0;
            mem[mx.second]++;
        }
        st.push_back("");
        stVal.push_back(0);
        for(int i=0;i<16;i++){
            st[val]+=to_string(mem[i])+" ";
        }
        tot++;
        cout<<st[val]<<endl;
        for(int i=0;i<st.size()-1;i++){
            stVal[i]++;
            if(st[i]==st[val]){tot2=stVal[i];bol=false;break;}
        }
    }
    cout<<tot<<" "<<tot2;
}
