#include<bits/stdc++.h>
using namespace std;
long long t,a,b,c;
long long fastpower(long long base,long long power,long long c){
     long long result=1;
     while(power){
          if(power&1) result=(result*base)%c;
          power >>=1;
          base=(base*base)%c;
     }
     return result;
}
int main(){
    cin>>t;
    while(t--){
       cin>>a>>b>>c;
       cout<<fastpower(a,b,c)<<endl;
    }
    return 0;
}