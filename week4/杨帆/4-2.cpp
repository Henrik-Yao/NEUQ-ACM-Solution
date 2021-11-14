#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[50];
int main(){
    int t;
    cin>>t;
    f[1]=0,f[2]=1,f[3]=2;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            if(!f[i])
                f[i]=f[i-1]+f[i-2];
        }
        cout<<f[n]<<"\n";
    }
    return 0;
}
