#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ring=1,newVal1=0,newVal2=0,newVal3=0,val1=0,val2=0,val3=0;
    vector<int> vec={1,1};
    cin>>n;
    for(int i=2;i<=8;i++){
        val1=0;
        if(i%2!=0)val1=*(vec.rbegin()+1);
        if(i==7)val2=1;
        vec.push_back(vec.back()+vec[0]+val1+val2);
        cout<<vec[i]<<" ";
    }
    newVal1=1;
    newVal2=2;
    newVal3=3;
    ring++;
    for(int i=5;vec.back()<n;i+=2,ring++){
        //newVal = starting position
        //oldVal = moving position
        //val    = addition
        int oldVal1=newVal1,
            oldVal2=newVal2,
            oldVal3=newVal3;

        for(int j=1;j<=4*(i-1);j++){
            val1=val2=val3=0;
            if(j<3){//if first 2 values
                val1=vec[oldVal1];
                if(j==2){
                    val2=vec[oldVal2];
                    val3=*(vec.rbegin()+1);
                }
            }
            else if(j%(ring*2)==0){//if corner
                oldVal1--;oldVal2--;
                val3=vec[--oldVal3];
                if(j==ring*8)val2=vec[newVal1];//if last corner
            }
            else if((j+1)%(ring*2)==0){//if before corner
                oldVal1--;
                val2=vec[--oldVal2];
                val3=vec[--oldVal3];
                if(j+1==ring*8)val1=vec[newVal1];//if corner is last
            }
            else if((j-1)%(ring*2)==0){//if after corner
                val1=*(vec.rbegin()+1);
                val2=vec[oldVal2];
                val3=vec[oldVal3];
            }
            else{
                val1=vec[oldVal1];
                val2=vec[oldVal2];
                val3=vec[oldVal3];
            }
            vec.push_back(vec.back()+val1+val2+val3);
            cout<<vec.back()<<" ";
            if(vec.back()>n)break;
            if(j==3){newVal3=vec.size()-1;newVal2=vec.size()-2;newVal1=vec.size()-3;}
            if(j>=3){oldVal1++;oldVal2++;oldVal3++;}
        }
    }
}
