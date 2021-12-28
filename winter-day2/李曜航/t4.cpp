#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,s,ans,fa[10010],p;
int x1,x2;
int cnt;
int find(int k)
{
    if(fa[k]==k)return k;
    return fa[k]=find(fa[k]);
}
void merge(int x, int y)
{
    fa[find(x)] = find(y);
}
int main()
{
    int q;
    cin>>n>>m>>q;
    for(i=1;i<=n;i++)
        fa[i]=i;
    for(i=1;i<=m;i++){
        cin>>x1>>x2;
        merge(x1,x2);
    }
    while(q--)
    {
        cin>>x1>>x2;
        if(find(x1)==find(x2))
            printf("In the same gang.\n");
        else
            printf("In different gangs.\n");
    }
    bool vis[1005] = {0};
    for(int i=1;i<=n;i++)
    {
        if(!vis[find(i)]) {vis[find(i)] = true;cnt++;}
    }
    printf("%d\n",cnt);
    return 0;
}