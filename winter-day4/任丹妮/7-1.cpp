#include <bits/stdc++.h>
using namespace std;
int mp[101][101];
typedef long long ll;
int main(){
    int n,e;
    while(cin>>n>>e){
        memset(mp,0x3f,sizeof(mp));
        while(e--){
            int h,t,w;
            cin>>t>>h>>w;
            if(t==h) mp[t][h]=0;
            else {
                mp[t][h]=w;
                mp[h][t]=w;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(mp[i][j]>mp[i][k]+mp[k][j])
                        mp[i][j]=mp[i][k]+mp[k][j];
        }
        ll dis[101]={0};
        ll ans=0x3f3f3f3f;
        int pos=0;
        memset(dis,0,sizeof(dis));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j) dis[i]+=(ll)mp[i][j];
        for(int i=0;i<n;i++)
            if(ans>dis[i]) {
                ans=dis[i];
                pos=i;
            }
        cout<<pos<<endl;
    }
    return 0;
}
