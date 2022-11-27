#include<bits/stdc++.h>
using namespace std;
int to_int(char x){return int(x-'0');} //convert a char to int
char to_char(int x){return char(x+'0');} //convert an int to char
int main(){
    string num; //number
    int sum=0; //total sum
    cin>>num; //inputting number
    int n=num.size()/2; //half of string size
    for(int i=0;i<num.size();i++){ //traversing string
        int x=n-(num.size()-i); //next element to check, set it default to start from 0, in case the string ends
        if(i+n<num.size())x=i+n; //if the next element is in the string size limit, set X to that, else keep X as is
        if(num[i]==num[x]){sum+=to_int(num[i]);} //if current element and next are the same, increase the sum by that number
    }
    cout<<sum; //output
}
