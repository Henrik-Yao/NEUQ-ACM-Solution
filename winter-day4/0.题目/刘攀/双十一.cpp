#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
typedef long long ll;
int mp[1000][1000];
int main()
{
    int n,e;
    while(cin>>n>>e)
    {
        memset(mp, 10000, sizeof mp);
        for(int i = 1; i <= e; i++)
        {
            int from, to, v;
            scanf("%d %d %d",&from,&to,&v);
            ++from, ++to;
            if(from == to) mp[from][to] = 0;
            else
            {
                mp[from][to] = v;
                mp[to][from] = v;
            }
        }
        
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    if(mp[i][j] > mp[i][k] + mp[k][j])
                        mp[i][j] = mp[i][k] + mp[k][j];
        
        ll dis[maxn] = {0};
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i != j) dis[i] = dis[i] + (ll)mp[i][j];
            }
        }
        ll ans = 0x3f3f3f3f;
        int pos = 1;
        for(int i = 1; i <= n; i++)
            if(dis[i] < ans) ans = dis[i], pos = i;
        --pos;
        printf("%d\n",pos);
    }
    return 0;
}

