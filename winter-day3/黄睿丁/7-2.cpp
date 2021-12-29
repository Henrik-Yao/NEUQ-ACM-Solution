#include <bits/stdc++.h>
using namespace std;
typedef struct edge
{
    int to;
    int weight;
}edge;
vector<edge> v[20001];
bool cmp(edge a,edge b)
{
    return a.to<b.to;
}
int main()
{
    int n,m,z;
    cin>>n>>m;
    int i,j;
    for(i=0;i<m;i++)
    {
        edge e;
        int a,b,c;
        cin>>a>>b>>c;
        e.to=b;
        e.weight=c;
        v[a].push_back(e);
    }
    cin>>z;
    for(i=0;i<z;i++)
    {
        int a,b;
        cin>>a>>b;
        for(j=0;j<v[a].size();j++)
        {
            if(v[a][j].to==b)
            {
                v[a].erase(v[a].begin()+j);
                break;
            }
        }
    }
    for(i=0;i<n;i++)
        sort(v[i].begin(),v[i].end(),cmp);
    for(i=0;i<n;i++)
    {
        if(!v[i].empty())
        {
            cout<<i<<":";
            for(auto x:v[i])
            {
                cout<<"("<<i<<","<<x.to<<","<<x.weight<<")";
            }
            cout<<endl;
        }
    }
}
