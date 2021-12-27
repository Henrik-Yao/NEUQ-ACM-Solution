#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N = 105;
vector<int> G[N];
int indeg[N];
void init()
{
    for(int i=0;i<=100;i++)
        G[i].clear();
    memset(indeg,0,sizeof(indeg));
}
int main()
{
    freopen("read3.in","r",stdin);
    int n,m;//篇数，关系
    while(cin>>n)
    {
        bool ifyes = false;
        m = read();
        init();
        for(int i=1;i<=m;i++)
        {
            int a = read(), b = read();
            G[a].push_back(b);
            indeg[b]++;
        }
        queue<int> q;
        
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                if(cnt==1) ifyes = true;
                cnt = 1;
            }
        }
        while(!q.empty())
        {
            int p=q.front(); q.pop();
            // printf("%d ",p);//输出
            cnt = 0;
            for(int i:G[p])
            {
                if(--indeg[i]==0)
                {
                    q.push(i);
                    if(cnt) ifyes = true;
                    cnt = 1;
                }
            }
        }
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            if(indeg[i])
            {
                printf("0\n");
                flag = false;
                break;
            }
        }
        if(flag && ifyes)
            printf("2\n");
        else if(flag && !ifyes)
            printf("1\n");
        // printf("ifmulti:%d\n",ifyes);

    }

}