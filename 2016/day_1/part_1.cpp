#include<bits/stdc++.h>
using namespace std;
int main(){
  string inp;
  int state=1;
  pair<int,int> crd=make_pair(0,0);
  ifstream input("input.txt");
  while(getline(input,inp,' ')){
    char dir=inp[0];
    int num=0;
    for(int i=1;i<inp.size()-1;i++)
      num=(num*10)+int(inp[i]-'0');
    //cout<<num<<"\t";
    switch(state){
      case 1:
        if(dir=='R'){crd.first+=num;state=2;}
        else {crd.first-=num;state=3;}
        break;
      case 2:
        if(dir=='R'){crd.second-=num;state=4;}
        else {crd.second+=num;state=1;}
        break;
      case 3:
        if(dir=='R'){crd.second+=num;state=1;}
        else {crd.second-=num;state=4;}
        break;
      case 4:
        if(dir=='R'){crd.first-=num;state=3;}
        else {crd.first+=num;state=2;}
        break;
    }
  }
  cout<<"x="<<crd.first<<"   y="<<crd.second<<endl;
  cout<<abs(crd.first)+abs(crd.second);
}
