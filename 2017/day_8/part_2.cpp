#include<bits/stdc++.h>
using namespace std;
int main(){
    string inp;
    map<string,int> var;
    ifstream input("input.txt");
    int mx=0;
    while(getline(input,inp)){

        int i=0,num=0,comp2=0;
        string cur="",comp1="";

        while(!isspace(inp[i])) //variable to change
            cur+=inp[i++];

        if(var.count(cur)==0)var[cur]=0; //if variable doesn't exist, initialize it as 0

        int sign=int(inp[++i]=='i'); //1 = add, 0 = sub
        i+=4; //skip rest of inc/dec, skip space
        //at num value if exists, else at num
        if(inp[i]=='-'){sign=!sign;i++;} //if negative, flip operation

        while(!isspace(inp[i])) //what value to increase by
            num=(num*10)+int(inp[i++]-'0');

        i+=4; //skip "if" and space
        //at comp variable
        while(!isspace(inp[i])) //get variable to compare
            comp1+=inp[i++];
        //space after variable
        if(var.count(comp1)==0)var[comp1]=0; //if var doesn't exist, create it
        int j=++i; //save j [1st operator] for later, i at first variable
        if(!isspace(inp[++i]))i++; //if its a double operator, skip it, go to space

        int sign2=1;
        if(inp[++i]=='-'){sign2=-1;i++;}

        while(i<inp.size())
            comp2=(comp2*10)+int(inp[i++]-'0');

        comp2*=sign2;

        if(!sign)sign=-1;
        if          (((inp[j+1]=='=')&&
            ((inp[j]=='<'&&var[comp1]<=comp2)||
             (inp[j]=='>'&&var[comp1]>=comp2)||
             (inp[j]=='='&&var[comp1]==comp2)||
             (inp[j]=='!'&&var[comp1]!=comp2)))

           ||((inp[j]=='<'&&var[comp1]<comp2)||
              (inp[j]=='>'&&var[comp1]>comp2)))
            var[cur]+=num*sign;
        string print;
        if(sign>0)print=" + ";else print=" - ";
        cout<<"if ( "<<comp1<<" "<<inp[j]<<inp[j+1]<<" "<<comp2<<" )"<<cur<<print<<num<<" -> "<<var[cur]<<endl;
        mx=max(mx,var[cur]);
    }
    cout<<"Old max: "<<mx<<endl;
    mx=0;
    for(auto i : var){
        //cout<<i.first<<" = "<<i.second<<endl;
        mx=max(i.second,mx);
    }
    cout<<"End max: "<<mx;
}
