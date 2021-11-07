#include <bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int vis[maxn],prime[maxn];
long long n,cnt;
void Prime() {
    for(long long i=2;i<=n;i++) {
        if(!vis[i])
            prime[++cnt]=i;
        for(long long j=1;j<=cnt && i*prime[j]<=n;j++) {
            vis[i*prime[j]]=1;
            if(!(i%prime[j]))
                break;
        }
    }
}
int main(){
	cin>>n;
	Prime();
	cout<<cnt;
    return 0;
}




