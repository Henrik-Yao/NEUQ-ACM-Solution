#include<bits/stdc++.h>
using namespace std;
int f[114514];
struct point
{
    int x;
    int y;
    int value;
}node[114514];

bool cmp(point node1,point node2)
{
    return (node1.value<node2.value);
}

int find(int x)
{
    if(f[x]==x) return x;
    else return f[x]=find(f[x]);
}

void merge(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a!=b) f[a]=b;
}

int main()
{
    int n,m,Max=0,cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        f[i]=i;
    for(int i=0;i<m;i++)
        cin>>node[i].x>>node[i].y>>node[i].value;
    sort(node,node+m,cmp);
    for(int i=0;i<m;i++)
    {
        if(find(node[i].x)!=find(node[i].y))
        {
            merge(node[i].x,node[i].y);
            cnt++;
            Max=node[i].value;
        }
    }
    cout<<cnt<<" "<<Max;
    return 0;
}