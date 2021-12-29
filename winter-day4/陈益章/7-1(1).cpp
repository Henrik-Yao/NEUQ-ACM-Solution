#include <cstdio>
#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 107;
typedef long long ll;
int mp[107][107];
int main()
{
    int n,e;
    while(~scanf("%d %d",&n,&e))
    {
        memset(mp, 0x3f, sizeof mp);
        for(int i = 1; i <= e; i++)
        {
            int a, b, c;
            scanf("%d %d %d",&a,&b,&c);
            ++a, ++b;
            if(a == b) mp[a][b] = 0;
            else
            {
                mp[a][b] = c;
                mp[b][a] = c;
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

