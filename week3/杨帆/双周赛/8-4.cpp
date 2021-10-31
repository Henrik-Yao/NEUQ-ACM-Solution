#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define INF 0x3f3f3f3f
ll d[100],f[100];
int main(){
    int n;
    while(cin>>n){
        for(ll i=1;i<=n;i++){
            d[i]=pow(2,i)-1;
        }
        memset(f,INF,sizeof(f));
        f[1]=d[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                f[i]=min(f[i],f[j]*2+d[i-j]);
            }
        }
        cout<<f[n]<<"\n";
    }
    return 0;
}
