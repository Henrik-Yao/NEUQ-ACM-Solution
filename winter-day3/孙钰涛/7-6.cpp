#include<bits/stdc++.h>
using namespace std;
int f[1501];

struct tree
{
    int x;
    int y;
    int value;
};

bool cmp(tree node1,tree node2)
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
    int point,line;
    while(cin>>point>>line)
    {
        tree node[1501];
        int flag[1501];
        memset(flag,0,sizeof(flag));
        int a,b,c;
        for(int i=0;i<point;i++)
            f[i]=i;
        for(int i=0;i<line;i++)
        {
            cin>>a>>b>>c;
            node[i].x=a;
            node[i].y=b;
            node[i].value=c;
            merge(a,b);
        }
        int cnt=0;
        for(int i=0;i<point;i++)
            if(f[i]==i) cnt++;
        if(cnt!=1)
        {
            cout<<"There is no minimum spanning tree.\n";
            continue;
        }
        sort(node,node+line,cmp);
        cnt=0;
        for(int i=0;i<line;i++)
        {
            if(flag[node[i].x]==1 && flag[node[i].y]==1) continue;
            else
            {
                flag[node[i].x]=1;
                flag[node[i].y]=1;
                cnt=cnt+node[i].value;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}