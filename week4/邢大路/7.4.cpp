#include<bits/stdc++.h>
using namespace std;
long long a,b,c,ans;
int main(){
    long long n;
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        ans=1;
    while(b){ 
        if(b&1==1){
            ans = (ans*a)%c; 
            b--; 
        }
        b>>=1 ; 
        a=(a*a)%c; 
    }
        cout<<ans;
        cout<<endl;
    }
    return 0;
}
