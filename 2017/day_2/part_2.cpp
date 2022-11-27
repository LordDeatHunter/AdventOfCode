#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> row;
    vector<vector<int> > matrix;
    int n,m,tmp,sm=0;
    cin>>n>>m;
    vector<int> mm; //minimum, maximum
    for(int i=0;i<n;i++){
        matrix.push_back(row);
        for(int j=0;j<m;j++){
            cin>>tmp;
            matrix[i].push_back(tmp);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=j+1;k<m;k++){
                if(max(matrix[i][k],matrix[i][j])%min(matrix[i][k],matrix[i][j])==0){
                    mm.push_back(max(matrix[i][k],matrix[i][j])/min(matrix[i][k],matrix[i][j]));
                    //cout<<mm[i]<<" ";
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++)sm+=mm[i];
    cout<<sm;
}
