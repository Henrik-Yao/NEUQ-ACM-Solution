#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
ll n,m,dis[205][205],pass[205][205];
vector<ll> v;
void output(int a,int b){
	if(pass[a][b]==-1) return;
	output(a,pass[a][b]);
	cout<<pass[a][b]<<"->";
	output(pass[a][b],b);
}
int main()
{
    memset(pass,-1,sizeof pass);
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i!=j) dis[i][j]=inf;
        }
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=min(dis[a][b],c);
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    pass[i][j]=k;
                }
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        int a,b;
        cin>>a>>b;
        if(dis[a][b]<inf)
        {
            cout<<a<<"->";
            output(a,b);
            cout<<b<<":";
            cout<<dis[a][b]<<endl;
        }
        else printf("%d->%d:-1\n",a,b);
    }
    ll maxn=0;
    ll a,b;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dis[i][j]>maxn&&dis[i][j]<inf)
            {
                maxn=dis[i][j];
                a=i,b=j;
            }
        }
    }
    cout<<a<<"->";
    output(a,b);
    cout<<b<<":";
    cout<<maxn<<endl;
    return 0;
}
