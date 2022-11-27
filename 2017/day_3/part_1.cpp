#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,square=0;
    cin>>n;
    for(int i=1;square<n;i+=2)square=pow(i,2);
    int ring=ceil(sqrt(square)/2);
    int center=square-ring+1;
    cout<<(ring-1)+min(min(abs(center-n),abs(center-2*(ring-1)-n)),min(abs(center-4*(ring-1)-n),abs(center-6*(ring-1)-n)));
}
