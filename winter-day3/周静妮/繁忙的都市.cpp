#include<bits/stdc++.h>
using namespace std;
struct node
{
    int from,to;
    int dis;
    friend bool operator <(node A,node B)
    {
        return A.dis<B.dis;
    }
}mapp[20000],s[20000];
int n,m;
int p[1000];
int findth(int x)
{
    if(x==p[x]) return x;
    return p[x]=findth(p[x]);
}
 
void unionn(int x,int y)
{
    int xx=findth(x);
    int yy=findth(y);
    if(xx!=yy) p[yy]=xx;
}
int cnt=0;
void Kruskal()
{
    sort(mapp+1,mapp+1+m);
    for(int i=1;i<=m;i++){
        if(findth(mapp[i].from)==findth(mapp[i].to)) continue;
        unionn(mapp[i].from,mapp[i].to);
        cnt++;
        s[cnt].from=mapp[i].from;
        s[cnt].to=mapp[i].to;
        s[cnt].dis=mapp[i].dis;
 
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d %d %d",&mapp[i].from,&mapp[i].to,&mapp[i].dis);
    }
    Kruskal();
    sort(s+1,s+1+cnt);
    printf("%d %d",cnt,s[cnt].dis);
    return 0;
}
