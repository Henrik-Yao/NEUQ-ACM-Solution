#include<bits/stdc++.h>
using namespace std;
bool x[101][101];
vector<int>vec[101];
queue<int>q;
int degree[101];

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int flag=0;
        memset(x,0,sizeof(x));
        memset(degree,0,sizeof(degree));
        for(int i=1;i<=n;i++)
            vec[i].clear();
        int a,b;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            x[a][b]=1;
            vec[a].push_back(b);
            degree[b]++;
        }
        int num=0;
        for(int i=1;i<=n;i++)
            if(!degree[i]) q.push(i);
        if(q.size()==1) flag=1;
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            num++;
            for(int i=0;i<vec[now].size();i++)
                if(--degree[vec[now][i]]==0)
                    q.push(vec[now][i]);
        }
        if(num!=n)
        {
            cout<<0<<endl;
            continue;
        }
        else if(num==n && flag==1) cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}