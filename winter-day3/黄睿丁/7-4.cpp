#include <bits/stdc++.h>
using namespace std;
typedef struct edge
{
    int from;
    int to;
    int weight;
}edge;
vector<edge> v[20001];
bool cmp(edge a,edge b)
{
    return a.weight<=b.weight;
}

set<int> Y,N;
vector<edge> ed;
int main()
{
    int n,m;
    cin>>n>>m;
    int i,j;
    for(i=1;i<=m;i++)
    {
        edge e1,e2;
        int a,b,c;
        cin>>a>>b>>c;
        e1.from=a;
        e1.to=b;
        e1.weight=c;
        e2.from=b;
        e2.to=a;
        e2.weight=c;
        v[a].push_back(e1);
        v[b].push_back(e2);
        
    }
    for(i=1;i<=n;i++)
    {
		N.insert(i);
        sort(v[i].begin(),v[i].end(),cmp);
    }
    N.erase(1);
    Y.insert(1);
    while(N.size()>0)
    {
        edge now[Y.size()];
        int num=0;
        for(auto it:Y)
        {
            for(i=0;i<v[it].size();i++)
            {
                if(N.count(v[it][i].to))
                {
                	now[num++]=v[it][i];
                	break;
            	}
            }
        }
        int min=10000000,locate;
        for(j=0;j<num;j++)
        {
            if(min>now[j].weight)
            {
                min=now[j].weight;
                locate=j;
            }
        }
        ed.push_back(now[locate]);
        N.erase(now[locate].to);
        Y.insert(now[locate].to);
    }
    sort(ed.begin(),ed.end(),cmp);
    cout<<n-1<<" "<<ed[n-2].weight;
}
