#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	ifstream inp("input.txt");
	getline(inp,s);
	cout<<s.size()<<endl;
	//cout<<endl<<endl<<endl;
	for(int i=0;i<s.size()-1;i){
		if((tolower(s[i])==tolower(s[i+1]))&&((islower(s[i])&&isupper(s[i+1]))||(islower(s[i+1])&&isupper(s[i]))))
			s.erase(i--,2);
		else i++;
		if(i<0)i=0;
	}
	//cout<<s<<endl;
	cout<<s.size();
}
