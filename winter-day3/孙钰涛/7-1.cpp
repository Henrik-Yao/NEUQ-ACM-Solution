#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct point
{
    int from;
    int to;
    int value;
} node[20001];

bool cmp(point a,point b)
{
    if(a.from!=b.from) return (a.from<b.from);
    else return (a.to<b.to);
}

int main()
{
    int n,m,cnt[20001];
    memset(cnt,0,sizeof(cnt));
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>node[i].from>>node[i].to>>node[i].value;
        cnt[node[i].from]++;
    }
    sort(node+1,node+m+1,cmp);
    int temp=1;
    for(int i=0;i<n;i++)
    {
        if(cnt[i]==0) continue;
        cout<<node[temp].from<<":";
        for(int j=1;j<=cnt[i];j++)
        {
            printf("(%d,%d,%d)",node[temp].from,node[temp].to,node[temp].value);
            temp++;
        }
        cout<<"\n";
    }
    return 0;
}