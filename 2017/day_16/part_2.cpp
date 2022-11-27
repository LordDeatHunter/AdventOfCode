#include<bits/stdc++.h>
//sX -> last X characters to start, s3 abcdefg->efgabcd
//xA/B -> exchange #a and #b, x2/4 -> adcbefg
//pA/B -> exchange a&b, pB/F -> afcdebg
using namespace std;
int main(){
  ifstream input("input.txt");
  vector<string> cmd;
  string inp,pr="";
  while(getline(input,inp,','))cmd.push_back(inp);
  for(char c='a';c<='p';c++)pr+=c;
  //pr="abcde";
  int a=0,b=0;
  vector<string> out;
  for(int i=0;i<cmd.size();i++){

    if(cmd[i][0]=='p'){
      size_t pos1 = pr.find(cmd[i][1]);
      size_t pos2 = pr.find(cmd[i][3]);
      swap(pr[pos1],pr[pos2]);
    }

    else if(cmd[i][0]=='s'){
      a=cmd[i][1]-'0';
      if(cmd[i].size()==3)
        a=(a*10)+cmd[i][2]-'0';
      string sb=pr.substr(0,pr.size()-a);
      string sa=pr.substr(pr.size()-a);
      pr=sa+sb;
    }

    else{
      a=cmd[i][1]-'0';
      if(cmd[i][2]=='/'){
        b=cmd[i][3]-'0';
        if(cmd[i].size()==5)b=(b*10)+cmd[i][4]-'0';
      }
      else{
        a=(a*10)+cmd[i][2]-'0';
        b=cmd[i][4]-'0';
        if(cmd[i].size()==6)b=(b*10)+cmd[i][5]-'0';
      }
      swap(pr[a],pr[b]);
    }

    //cout<<pr<<endl;
  }
  out.push_back(pr);
  cout<<pr;
}
