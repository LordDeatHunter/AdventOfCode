#include<bits/stdc++.h>
using namespace std;

string knothash(string s){
  vector<int> a, shift, xr;
  int skip = 0, rev = 0;
  for (int i = 0; i < 256; i++)a.push_back(i);
  for (auto i : s)shift.push_back(int(i));
  shift.insert(shift.end(), {17, 31, 73, 47, 23});
  for (int k = 0; k < 64; k++){
    for (auto i : shift){
      reverse(a.begin(), a.begin() + i);
      rotate(a.begin(), a.begin() + (i + (skip++)) % 256, a.end());
      rev += i + skip - 1;
    }
  }
  rotate(a.rbegin(), a.rbegin() + (rev) % 256, a.rend());
  for (int i = 0; i < 256; i += 16)
    xr.push_back(accumulate(a.begin() + i, a.begin() + i + 16, 0, bit_xor<int>()));
  stringstream ss;
  for (auto i : xr)
    ss << setfill('0') << setw(2) << hex << i;
  return ss.str();
}

string hextobin(string s){
  string bin="";
  for(auto i:s){
    switch(toupper(i)){
      case '0': bin+="0000"; break;
      case '1': bin+="0001"; break;
      case '2': bin+="0010"; break;
      case '3': bin+="0011"; break;
      case '4': bin+="0100"; break;
      case '5': bin+="0101"; break;
      case '6': bin+="0110"; break;
      case '7': bin+="0111"; break;
      case '8': bin+="1000"; break;
      case '9': bin+="1001"; break;
      case 'A': bin+="1010"; break;
      case 'B': bin+="1011"; break;
      case 'C': bin+="1100"; break;
      case 'D': bin+="1101"; break;
      case 'E': bin+="1110"; break;
      case 'F': bin+="1111"; break;
    }
  }
  return bin;
}

string tostring(int n){
  string s="";
  for(int i=n;i>0;i/=10)s+=char(i%10+'0');
  reverse(s.begin(),s.end());
  if(s=="")return "0";
  else return s;
}

void flood(int x, int y, vector<string> &table) {
    if (x < 0 || y < 0 || x >= 128 || y >= 128 || table[x][y] != '1') return;
    table[x][y] = '2';
    flood(x - 1, y, table);
    flood(x + 1, y, table);
    flood(x, y - 1, table);
    flood(x, y + 1, table);
}

int main(){
  string s = "nbysizxe"; //main string
  //string s = "flqrgnkx"; //test string
  vector<string> table;
  for(int i=0;i<128;i++){
    table.push_back(hextobin(knothash(s+'-'+tostring(i))));
    table[i] += '0';
  }
  int group = 1;
  for(int x=0;x<128;x++){
    for(int y=0;y<128;y++){
      //cout<<table[x][y];
      if(table[x][y]=='1'){
        flood(x,y,table);
      cout<<++group<<endl;
      }
    }
    //cout<<endl;
  }
  cout<<group-1;
}
