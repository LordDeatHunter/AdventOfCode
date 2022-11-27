#include<bits/stdc++.h>
using namespace std;
int to_int(char x){return int(x-'0');} //convert a char to int
char to_char(int x){return char(x+'0');} //convert an int to char
int main(){
    string num; //number
    int sum=0; //total sum
    cin>>num; //inputting number
    for(int i=0;i<num.size();i++){ //traversing string
        int x=0; //next element to check
        if(i+1<num.size())x=i+1; //if the next element is in the string size limit, set X to that, else keep X as the 1st number of the string
        if(num[i]==num[x]){sum+=to_int(num[i]);} //if current element and next are the same, increase the sum by that number
    }
    cout<<sum; //output
}
