#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
int indegree[101],state[101],n,m;
typedef struct edge
{
    int from;
    int to;
}edge;
vector<edge> v[101];
int main()
{
    while(cin>>n>>m)
    {
    	for(int i=1;i<=n;i++)
    	v[i].clear();
        memset(indegree,0,n+1);
        memset(state,0,101);
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            edge ed;
            ed.from=x;
            ed.to=y;
            v[x].push_back(ed);
            indegree[y]++;
        }
        
        queue<int> q;
        int sum=0,f=0;
        while(sum!=n)
        {
            int flag=0,num=0;
            for(int i=1;i<=n;i++)
            {
                if(indegree[i]==0&&state[i]==0)
                {
                    state[i]=1;
                    flag=1;
                    q.push(i);
                    sum++;
                    num++;
                }
            }
            if(num>1&&(f==0||f==1))
                f=2;
                else if(num==1&&f==0)
                f=1;
            if(flag==0)
            {
                f=0;
                cout<<0<<endl;
                    break;
            }
            else
            {
                while(!q.empty())
                {
                    int now=q.front();
                    for(int i=0;i<v[now].size();i++)
                    {
                        indegree[v[now][i].to]--;
                    }
                    q.pop();
                }
            }
        }
        if(f==2)
            cout<<2<<endl;
            else if(f==1)
                cout<<1<<endl;
        
    }
}
