#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int f[100];

struct point
{
    int x;
    int y;
    int value;
};

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

bool cmp(point node1,point node2)
{
    return (node1.value<node2.value);
}

int main()
{
    int n,v,e;
    while(cin>>n>>v>>e)
    {
        memset(f,0,sizeof(f));
        int cost=0,flag=2,cnt=0;
        point node[100];
        for(int i=0;i<n;i++)
            f[i]=i;
        for(int i=0;i<e;i++)
            cin>>node[i].x>>node[i].y>>node[i].value;
        sort(node,node+e,cmp);
        for(int i=0;i<e;i++)
        {
            if(find(node[i].x)!=find(node[i].y))
            {
                if(node[i].x==v || node[i].y==v)
                {
                    if(flag==0) continue;
                    else flag--;
                }
                merge(node[i].x,node[i].y);
                cost=cost+node[i].value;
            }
        }
        for(int i=0;i<n;i++)
            if(find(i)==i) cnt++;
        if(cnt!=1) cout<<"-1\n";
        else cout<<cost<<"\n";
    }
    return 0;
}