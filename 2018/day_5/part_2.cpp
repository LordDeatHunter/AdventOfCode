#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	int ms=INT_MAX;
	ifstream inp("input.txt");
	getline(inp,str);
	cout<<str.size()<<endl;
	//cout<<endl<<endl<<endl;
	for(int l=0;l<26;l++){
		string s=str;
		s.erase(remove(s.begin(), s.end(), ('a'+l)), s.end());
		s.erase(remove(s.begin(), s.end(), ('A'+l)), s.end());
		for(int i=0;i<s.size()-1;i){
			if((tolower(s[i])==tolower(s[i+1]))&&((islower(s[i])&&isupper(s[i+1]))||(islower(s[i+1])&&isupper(s[i]))))
				s.erase(i--,2);
			else i++;
			if(i<0)i=0;
		}
		ms=min(ms,int(s.size()));
	}

	//cout<<s<<endl;
	cout<<ms;
}
