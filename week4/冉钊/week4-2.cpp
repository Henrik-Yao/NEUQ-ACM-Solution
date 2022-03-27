#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum(int m){
    if(m==1) return 1;
    if(m==2) return 1;

    return sum(m-1)+sum(m-2);
    
}
int main(){
     cin>>n;
     while(n--){
        cin>>m;
        if(m>1)
        cout<<sum(m)<<endl;
        else
        cout<<"0"<<endl;

     }



    return 0;
}