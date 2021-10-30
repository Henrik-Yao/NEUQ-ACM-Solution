#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int main(){
    int n;
    int cns=0;
    int cns2=0;
    int ans=0;
    cin>>n;
    int a[n+1];
    int vis[maxn],vis2[maxn];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]]++;
        if(vis[a[i]]==1)cns++;
    }
    for(int i=1;i<=n;i++){
        if(vis[a[i]]==1)cns--;
        vis[a[i]]--;
        if(vis2[a[i]]==0)cns2++;
        vis2[a[i]]++;
        ans=max(ans,cns+cns2);
    }
    cout<<ans;
    return 0;
}
