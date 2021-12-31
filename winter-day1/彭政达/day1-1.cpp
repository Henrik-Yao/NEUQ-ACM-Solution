#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
ll a[1000010]={0};
ll get(int x){
    ll s=0;
    for(int i=x;i>0;i-=((i)&(-i))) s+=a[i];
    return s;
}
int main(){
	int m,t,x,y;
	ios::sync_with_stdio(false);
    cin>>n>>q;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=i;j<=n;j+=((i)&(-i))) a[j]+=m;
    }
    while(q--){
        cin>>t>>x>>y;
        if(t==1) for(int i=x;i<=n;i+=((i)&(-i))) a[i]+=y;
        else cout<<get(y)-get(x-1)<<endl;
    }
}
