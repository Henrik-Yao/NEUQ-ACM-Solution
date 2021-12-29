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
} node[40001];

bool cmp(point a,point b)
{
    if(a.from!=b.from) return (a.from<b.from);
    else return (a.to<b.to);
}

int main()
{
    int n,m,k,cnt[40001],ccnt[40001];
    memset(cnt,0,sizeof(cnt));
    memset(ccnt,0,sizeof(ccnt));
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>node[i].from>>node[i].to>>node[i].value;
        cnt[node[i].from]++;
    }
    cin>>k;
    for(int i=m;i<m+k;i++)
    {
        cin>>node[i].from>>node[i].to;
        node[i].value=-114514;
        cnt[node[i].from]++;
    }
    sort(node,node+m+k,cmp);
    for(int i=0;i<m+k;i++)
    {
        if((node[i].from==node[i-1].from && node[i].to==node[i-1].to)|| 
           (node[i].from==node[i+1].from && node[i].to==node[i+1].to))
            {
                node[i].value=-114514;
                ccnt[node[i].from]=ccnt[node[i].from]+1;
            }
    }
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(cnt[i]==ccnt[i])
        {
            temp=temp+ccnt[i];
            continue;
        }
        cout<<node[temp].from<<":";
        for(int j=0;j<cnt[i];j++)
        {
            if(node[temp].value==-114514) 
            {
                temp++;
                continue;
            }
            printf("(%d,%d,%d)",node[temp].from,node[temp].to,node[temp].value);
            temp++;
        }
        cout<<"\n";
    }
    return 0;
}