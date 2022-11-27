#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans=0;
    string inp;
    vector<string> path;
    pair<int,string> mov[6]={{0,"nw"},{0,"n"},{0,"ne"},{0,"se"},{0,"s"},{0,"sw"}};
    ifstream input("input.txt");
    while(getline(input,inp,',')){
        int tot=0;
        path.push_back(inp);
        for(int i=0;i<6;i++)mov[i].first=count(path.begin(),path.end(),mov[i].second);

        for(int i=0;i<3;i++){
            if(mov[i].first>=mov[i+3].first){mov[i].first-=mov[i+3].first;mov[i+3].first=0;}
            else {mov[i+3].first-=mov[i].first;mov[i].first=0;}
        }

        for(int i=0;i<6;i++){
            if(mov[i%6].first!=0 && mov[(i+2)%6].first!=0){
                mov[(i+1)%6].first+=min(mov[i%6].first,mov[(i+2)%6].first);
                if(mov[i%6].first>=mov[(i+2)%6].first){mov[i%6].first-=mov[(i+2)%6].first;mov[(i+2)%6].first=0;}
                else {mov[(i+2)%6].first-=mov[i%6].first;mov[i%6].first=0;}
            }
        }

        for(int i=0;i<6;i++)if(mov[i].first!=0)tot+=mov[i].first;
        ans=max(tot,ans);
    }
    cout<<ans;

}
